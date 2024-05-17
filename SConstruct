import os
from SCons.Script import *

# Create a build environment
env = Environment()

# Set the compiler to NVCC
env['CC'] = '/usr/bin/nvcc'
env['CXX'] = '/usr/bin/nvcc'

# Explicitly define the include directory path relative to the SConstruct file location
include_dir = os.path.abspath('include')

# Adding CUDA builder to the environment
cuda = Builder(action='$CC -c $SOURCE -o $TARGET -I' + include_dir,
               suffix='.o',
               src_suffix='.cu')
env.Append(BUILDERS={'Cuda': cuda})

# Set the include directory
env.Append(CPPPATH=[include_dir])

# Specify where to find the source files
cpp_path = 'src/cpp'
cuda_path = 'src/cuda'

# Specify the output directory for object files
obj_dir = 'obj'

# Helper function to modify object file names
def obj_target(source):
    return os.path.join(obj_dir, os.path.splitext(os.path.basename(str(source)))[0] + '.o')

# Collect all CPP source files
cpp_files = Glob(os.path.join(cpp_path, '*.cpp'))

# Collect all CUDA source files
cuda_files = Glob(os.path.join(cuda_path, '*.cu'))

# Compile CPP files
for src in cpp_files:
    target = obj_target(src)
    env.Object(target=target, source=src)

# Compile CUDA files using the custom CUDA builder
for src in cuda_files:
    target = obj_target(src)
    env.Cuda(target=target, source=src)
