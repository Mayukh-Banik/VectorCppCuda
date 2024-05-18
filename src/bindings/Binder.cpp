#include <pybind11/pybind11.h>
#include "Ufuncs/TEMP.h"

namespace py = pybind11;

PYBIND11_MODULE(Matrixin, m) 
{
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("hadd", &hAdd, "hadd");
    m.def("dadd", &dAdd, "hadd");
    m.def("gadd", &gAdd, "hadd");
}