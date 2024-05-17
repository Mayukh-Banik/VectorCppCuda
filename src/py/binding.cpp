#include <pybind11/pybind11.h>

#include "add.h"

namespace py = pybind11;

PYBIND11_MODULE(TEMP, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("add", &add, "Function that adds values");
    m.def("add_GPU", &add_GPU, "A function that adds two numbers CUDA");
    m.def("add_CPU", &add_CPU, "A function that adds two numbers CPU");
}
