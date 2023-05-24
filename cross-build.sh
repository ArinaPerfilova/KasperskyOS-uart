#!/bin/bash

BUILD=$PWD/build
mkdir -p $BUILD && cd $BUILD

BUILD_SIM_TARGET=y

export LANG=C
export SDK_PREFIX="/opt/KasperskyOS-Community-Edition-1.1.1.13"
export PATH="$SDK_PREFIX/toolchain/bin:$PATH"

export QEMU_UART="uart0"
export HW_UART="uart1"

cmake -G "Unix Makefiles" \
      -D CMAKE_BUILD_TYPE:STRING=Debug \
      -D CMAKE_INSTALL_PREFIX:STRING=$BUILD/../install \
      -D CMAKE_FIND_ROOT_PATH=$([[ -f ../additional_cmake_find_root.txt ]] && cat ../additional_cmake_find_root.txt)$SDK_PREFIX/sysroot-aarch64-kos \
      -D CMAKE_TOOLCHAIN_FILE=$SDK_PREFIX/toolchain/share/toolchain-aarch64-kos.cmake \
      -D PORT_HW=$HW_UART \
      -D PORT_QEMU=$QEMU_UART \
      ../ && make kos-image

if [ -n "${BUILD_SIM_TARGET}" ]; then
    make sim
fi
