#!/bin/bash

# Check for the -c flag
if [ "$1" == "-c" ]; then
    echo "Cleaning up..."
    scons -c
    rm -f example.so
    echo "Cleanup complete."
    exit 0
fi

# Run scons to build the project
scons

# Check if scons build was successful
if [ $? -eq 0 ]; then
    echo "SCons build succeeded, proceeding to create the shared library."

    # Command to gather Python include directories from pybind11
    PYBIND11_INCLUDES=$(python3 -m pybind11 --includes)

    # Find all .o files in the obj directory
    OBJECT_FILES=$(find obj -name "*.o")

    # Run nvcc to create the shared library
    nvcc -shared -Xcompiler -fPIC $PYBIND11_INCLUDES $OBJECT_FILES -o bin/debug/Matrixin.so -L/usr/local/cuda-12.4/lib64 -lcudart

    echo "Shared library created as example.so"
else
    echo "SCons build failed, aborting."
fi
