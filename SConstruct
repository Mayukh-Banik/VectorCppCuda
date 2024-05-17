import os
from SCons.Script import *

# Create a build environment
env = Environment()

# Set the compiler to NVCC for CUDA and g++ for C++
env['CC'] = '/usr/bin/g++'
env['CXX'] = '/usr/bin/g++'
env['LINK'] = '/usr/bin/g++'

# Set NVCC as a separate tool for CUDA files
env['NVCC'] = '/usr/bin/nvcc'

# Set debugging and PIC flags, ensuring no duplication
env.Append(CCFLAGS=['-g', '-fPIC'])
env.Append(CXXFLAGS=['-g', '-fPIC'])
env.Append(NVCCFLAGS=['-g', '-Xcompiler', '-fPIC', '-arch=sm_86'])

# Explicitly define the include directory path
include_dir = os.path.abspath('include')

# Define CUDA builder with NVCC-specific flags
cuda = Builder(action='$NVCC -c $SOURCE -o $TARGET -I' + include_dir + ' $NVCCFLAGS',
               suffix='.o',
               src_suffix='.cu')
env.Append(BUILDERS={'Cuda': cuda})

# Set the include directory
env.Append(CPPPATH=[include_dir])

# Output directories
obj_dir = 'obj'
bin_dir = 'bin'
if not os.path.exists(obj_dir):
    os.makedirs(obj_dir)
if not os.path.exists(bin_dir):
    os.makedirs(bin_dir)

def obj_target(source):
    return os.path.join(obj_dir, os.path.splitext(os.path.basename(str(source)))[0] + '.o')

# Collect source files
cpp_files = Glob(os.path.join('src/cpp', '*.cpp'))
cuda_files = Glob(os.path.join('src/cuda', '*.cu'))

objects = []

# Compile C++ source files
for src in cpp_files:
    target = obj_target(src)
    obj = env.Object(target=target, source=src)
    objects.append(obj)

# Compile CUDA source files
for src in cuda_files:
    target = obj_target(src)
    obj = env.Cuda(target=target, source=src)
    objects.append(obj)

# Create both shared and static libraries
shared_lib = env.SharedLibrary(target=os.path.join(bin_dir, 'mylib'), source=objects)
static_lib = env.StaticLibrary(target=os.path.join(bin_dir, 'mylib'), source=objects)
