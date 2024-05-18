import os
import SCons

# Initialize the environment
env = Environment()

# Define the path to the NVCC compiler
env['ENV']['PATH'] = os.environ['PATH']
env['CC'] = 'nvcc'
env['CXX'] = 'nvcc'
env['NVCC'] = 'nvcc'

# Define common flags (consider separating if some are not applicable to NVCC)
common_flags = ['-Iinclude', '-g', '-dc', '-G', '-std=c++17','-I/usr/include/python3.10', '-I/home/weket/.local/lib/python3.10/site-packages/pybind11/include']
cpp_flags = ['-Xcompiler', '-fPIC', '-Xcompiler', '-g']  # Specify C++ specific flags
cu_flags = ['-dc', '-G', '-std=c++17', '-Iinclude', '-Xcompiler', '-fPIC']  # CUDA specific flags

# Update the flags
env.Append(CPPFLAGS=common_flags)
env.Append(CXXFLAGS=cpp_flags)
env.Append(CUDAFLAGS=cu_flags)

# Define source and object directories
src_dir = 'src'
obj_dir = 'obj'

# Identify all source files
cpp_files = [os.path.join(dp, f) for dp, dn, filenames in os.walk(src_dir) for f in filenames if f.endswith('.cpp')]
cu_files = [os.path.join(dp, f) for dp, dn, filenames in os.walk(src_dir) for f in filenames if f.endswith('.cu')]

# Custom builder for CUDA files
cuda = Builder(action='$NVCC -o $TARGET -c $SOURCE $CUDAFLAGS',
               suffix='.o',
               src_suffix='.cu')
env.Append(BUILDERS={'CUDA': cuda})

# Compile CUDA and C++ files
for cu_file in cu_files:
    obj_path = os.path.join(obj_dir, os.path.splitext(os.path.relpath(cu_file, src_dir))[0] + '.o')
    env.CUDA(target=obj_path, source=cu_file)

for cpp_file in cpp_files:
    obj_path = os.path.join(obj_dir, os.path.splitext(os.path.relpath(cpp_file, src_dir))[0] + '.o')
    env.Object(target=obj_path, source=cpp_file)
