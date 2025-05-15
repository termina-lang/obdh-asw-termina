#!/bin/bash

qemu-system-sparc -nographic -M leon3_generic -m 64M -kernel bin/obdhlab-termina -nodefaults -serial /dev/tnt2 -s -S
