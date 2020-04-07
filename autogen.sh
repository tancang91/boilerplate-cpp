#!/usr/bin/env bash
#set -ex

BUILD_TYPE="${1:-Debug}"
WORKDIR="build"
if [[ "${BUILD_TYPE}" != "Debug" ]]; then
    WORKDIR="release"
fi

ROOTDIR="$(pwd)"
mkdir -p "${WORKDIR}"

exec cmake  "-S${ROOTDIR}" \
            "-B${WORKDIR}" \
            -DCMAKE_BUILD_TYPE="${BUILD_TYPE}" \
            -DCMAKE_CXX_FLAGS="-fdiagnostics-color=always" \
            -DCMAKE_EXPORT_COMPILE_COMMANDS="ON" \
            #-DFIB_TESTING="ON"\
