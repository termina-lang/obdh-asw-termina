#!/usr/bin/env python3
"""
Generate .wcet files from .twcep files.

For each *.twcep file found recursively, a sibling *.wcet file is created
containing all path occurrences with a default WCET value.
"""

import argparse
import re
from pathlib import Path


TWCEP_DECL_RE = re.compile(
    r"""(?mx)
    ^\s*twcep\s+
    (?P<path>
      [A-Za-z_]\w*(?:::[A-Za-z_]\w*)*
      \(
        [^\)]*
      \)
    )
    \s*=\s*\[
    """
)


def extract_paths(text):
    seen = set()
    paths = []
    for m in TWCEP_DECL_RE.finditer(text):
        p = m.group("path").strip()
        if p not in seen:
            seen.add(p)
            paths.append(p)
    return paths


def render_wcet(paths, platform, default_wcet):
    lines = []
    lines.append(f"wcet {platform} = {{")
    lines.append("")

    if paths:
        for p in paths[:-1]:
            lines.append(f"    {p} = {default_wcet},")
        lines.append(f"    {paths[-1]} = {default_wcet}")

    lines.append("")
    lines.append("};")
    lines.append("")
    return "\n".join(lines)


def process_file(twcep_path, platform, default_wcet, overwrite):
    text = twcep_path.read_text(encoding="utf-8", errors="replace")
    paths = extract_paths(text)

    wcet_path = twcep_path.with_suffix(".wcet")
    if wcet_path.exists() and not overwrite:
        print(f"SKIP: {wcet_path}")
        return

    wcet_path.write_text(
        render_wcet(paths, platform, default_wcet),
        encoding="utf-8",
    )
    print(f"WROTE: {wcet_path} ({len(paths)} paths)")


def main():
    ap = argparse.ArgumentParser(description="Generate .wcet files from .twcep files recursively.")
    ap.add_argument("root", nargs="?", default=".", help="Root directory (default: current)")
    ap.add_argument("--platform", default="rtems5-leon3-qemu")
    ap.add_argument("--default", type=float, default=1e-4, dest="default_wcet")
    ap.add_argument("--overwrite", action="store_true")
    args = ap.parse_args()

    root = Path(args.root).resolve()
    for twcep in sorted(root.rglob("*.twcep")):
        process_file(twcep, args.platform, args.default_wcet, args.overwrite)


if __name__ == "__main__":
    main()

