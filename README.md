# Matrixin

**Goals**

Making a dynamic/statically linked library with debugging and release versions.

Will aim at making a python version with pybind11
Basic math operations for now.
Will use cuda and cpu. 
Aiming at making it used like pytorch with device=cuda.


Directory Structure:

obj -  all intemediary files

include - all custom include files

bin - binary/shared executable locations

    release - version without debugging information

    debug - versions with debug information

src - source files

    src/cuda - locations of cu files

    src/cpp - location of cpp files

    src/py - location of pybind11 binding files

lib - libraries from other sources

test - location of test files

    test/cpp - tests functionality of cpp/cu files dynamically/statically loaded

    test/py - python shared library functionality




Below is making the object files:


nvcc -c -o add.o add.cu -Xcompiler -fPIC


Below is compiling it into a shared library:

nvcc -shared -o liboperations.so add.o -Xcompiler -fPIC




weket@MayukhPC:~/VectorCppCuda$ nvcc -c -Xcompiler -fPIC add.cu -o add.o


weket@MayukhPC:~/VectorCppCuda$ g++ -shared -fPIC $(python3 -m pybind11 --includes) binding.cpp add.o -o example$(python3-config --extension-suffix) -L/usr/local/cuda/lib64 -lcudart



weket@MayukhPC:~/VectorCppCuda$ nvcc -c -Xcompiler -fPIC -Iinclude src/cuda/cudaAdd.cu -o obj/cudaAdd.o


weket@MayukhPC:~/VectorCppCuda$ g++ -shared -fPIC $(python3 -m pybind11 --includes) -Iinclude src/py/binding.cpp obj/cpuAdd.o obj/cudaAdd.o -o example$(python3-config --extension-suffix) -L/usr/local/cuda/lib64 -lcudart
