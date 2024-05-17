#include <pybind11/pybind11.h>

#include "add.h"

namespace py = pybind11;

PYBIND11_MODULE(PyVector, m) 
{
    m.doc() = "A library for Vector Linear Algebra";
    m.def("add", &add, "Function that adds values");
}
