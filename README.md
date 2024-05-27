## Matrixin ##

Basic Shared Library recreating NumPy from scratch with a lot of functionality stipped.

To name a few:
  Reduced function support.
  Only supports C++ double data type, eg 64 bit floating pointing as a data type.

Benefits:

  Supports CUDA out of the gate (hopefully).

Installation Guide:
  Use Windows 11.
  Install WSL2.0.
  Install CUDA 12.4, CMAKE 3.29.3
  Run python3 pip install pybind11
  Go to build and run cmake ..  then make.
  That should be it
