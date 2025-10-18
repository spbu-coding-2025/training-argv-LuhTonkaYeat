#!/bin/sh -e

BASEDIR=$(realpath "$(dirname "$0")")
ROOTDIR=$(realpath "$BASEDIR/..")
BUILDDIR="$ROOTDIR/build"

rm -rf "$BUILDDIR"
mkdir -p "$BUILDDIR"

cmake -S "$ROOTDIR" -B "$ROOTDIR/build"
cmake --build "$ROOTDIR/build"
