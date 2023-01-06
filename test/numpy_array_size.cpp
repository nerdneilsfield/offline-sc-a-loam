#include <iostream>
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;
using namespace std;

void PrintArraySize(py::array_t<double> &array) { cout << "Array size: " << array.size() << endl; }

PYBIND11_MODULE(numpy_array_size, m)
{
  m.doc() = "numpy_array_size";
  m.def("numpy_array_size", &PrintArraySize, "Print array size");
}