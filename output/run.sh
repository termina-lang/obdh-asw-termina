#!/bin/bash

set -e

QEMU_CMD=(
    qemu-system-sparc -nographic 
    -M leon3_generic -m 64M 
    -kernel bin/obdh-asw-termina 
    -nodefaults -serial /dev/tnt2
)

echo "Starting QEMU. Press Ctrl+C to stop."

trap "echo 'Terminating...'; exit 0" SIGINT

while true; do
    "${QEMU_CMD[@]}"
    echo "QEMU exited. Rebooting in 1 second..."
    sleep 1
done
