#!/bin/bash

qemu-system-sparc -nographic -M leon3_generic -m 64M -kernel bin/obdh-asw-termina -nodefaults -serial /dev/tnt2 -s -S
