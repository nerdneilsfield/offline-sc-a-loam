#include <pybind11/pybind11.h>

#include "pcl_helper/io.hpp"

namespace py = pybind11;

PYBIND11_MODULE(pcl_helper, m)
{
  m.doc() = "pcl_helper function collections";// optional module docstring

  m.attr("__version__") = "v0.1.0";
  m.def(
    "add", [](int i, int j) { return i + j; }, "A function which adds two numbers");

  py::module io = m.def_submodule("io", "I/O functions");
  io.def("load_pcd_file_point_xyz", &loadPcdFilePointXYZ, "Load a PCD file with XYZ points");
  io.def("load_pcd_file_point_xyz_i", &loadPcdFilePointXYZI, "Load a PCD file with XYZI points");
  io.def("load_pcd_file_point_xyz_rgb", &loadPcdFilePointXYZRGB, "Load a PCD file with XYZRGB points");
  io.def("load_ply_file_point_xyz", &loadPlyFilePointXYZ, "Load a PLY file with XYZ points");
  io.def("load_ply_file_point_xyz_i", &loadPlyFilePointXYZI, "Load a PLY file with XYZI points");
  io.def("load_ply_file_point_xyz_rgb", &loadPlyFilePointXYZRGB, "Load a PLY file with XYZRGB points");
}