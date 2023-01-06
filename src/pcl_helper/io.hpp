#ifndef PCL_HELPER_IO_HPP
#define PCL_HELPER_IO_HPP

#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>

#include <cstdint>
#include <iostream>
#include <stdexcept>

#include <spdlog/spdlog.h>

namespace py = pybind11;

py::array_t<double> loadPcdFilePointXYZ(const char *filename)
{
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
  if (pcl::io::loadPCDFile<pcl::PointXYZ>(filename, *cloud) == -1)//* load the file
  {
    spdlog::error("couldn't load points from file {0}", filename);
    // std::cerr << "Couldn't read file " << filename << std::endl;
    throw std::runtime_error("Couldn't read file");
    return py::array_t<double>();
  }

  // std::cout << "Loaded data points from " << filename << std::endl;
  // std::cout << "Width: " << cloud->width << std::endl;
  // std::cout << "Height: " << cloud->height << std::endl;
  spdlog::info("loaded {1} points from file {0}", filename, cloud->width * cloud->height);

  // Create a numpy array
  py::array_t<double> array =
    py::array_t<double>({ static_cast<uint64_t>(cloud->width * cloud->height), static_cast<uint64_t>(3) });

  auto r = array.mutable_unchecked<2>();
  for (auto i = 0; i < array.shape()[0]; i++) {
    r(i, 0) = cloud->points[i].x;
    r(i, 1) = cloud->points[i].y;
    r(i, 2) = cloud->points[i].z;
  }
  return array;
};

py::array_t<double> loadPcdFilePointXYZI(const char *filename)
{
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZI>);
  if (pcl::io::loadPCDFile<pcl::PointXYZI>(filename, *cloud) == -1)//* load the file
  {
    spdlog::error("couldn't load points from file {0}", filename);
    // std::cerr << "Couldn't read file " << filename << std::endl;
    throw std::runtime_error("Couldn't read file");
    return py::array_t<double>();
  }

  // std::cout << "Loaded data points from " << filename << std::endl;
  // std::cout << "Width: " << cloud->width << std::endl;
  // std::cout << "Height: " << cloud->height << std::endl;
  spdlog::info("loaded {1} points from file {0}", filename, cloud->width * cloud->height);


  // Create a numpy array
  py::array_t<double> array =
    py::array_t<double>({ static_cast<uint64_t>(cloud->width * cloud->height), static_cast<uint64_t>(4) });

  auto r = array.mutable_unchecked<2>();
  for (auto i = 0; i < array.shape()[0]; i++) {
    r(i, 0) = cloud->points[i].x;
    r(i, 1) = cloud->points[i].y;
    r(i, 2) = cloud->points[i].z;
    r(i, 4) = cloud->points[i].intensity;
  }
  return array;
};

py::array_t<double> loadPcdFilePointXYZRGB(const char *filename)
{
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
  if (pcl::io::loadPCDFile<pcl::PointXYZRGB>(filename, *cloud) == -1)//* load the file
  {
    spdlog::error("couldn't load points from file {0}", filename);
    // std::cerr << "Couldn't read file " << filename << std::endl;
    throw std::runtime_error("Couldn't read file");
    return py::array_t<double>();
  }

  // std::cout << "Loaded data points from " << filename << std::endl;
  // std::cout << "Width: " << cloud->width << std::endl;
  // std::cout << "Height: " << cloud->height << std::endl;
  spdlog::info("loaded {1} points from file {0}", filename, cloud->width * cloud->height);


  // Create a numpy array
  py::array_t<double> array =
    py::array_t<double>({ static_cast<uint64_t>(cloud->width * cloud->height), static_cast<uint64_t>(6) });

  auto r = array.mutable_unchecked<2>();
  for (auto i = 0; i < array.shape()[0]; i++) {
    r(i, 0) = cloud->points[i].x;
    r(i, 1) = cloud->points[i].y;
    r(i, 2) = cloud->points[i].z;
    r(i, 4) = cloud->points[i].r;
    r(i, 5) = cloud->points[i].g;
    r(i, 6) = cloud->points[i].b;
  }
  return array;
};

py::array_t<double> loadPlyFilePointXYZ(const char *filename)
{
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
  if (pcl::io::loadPLYFile<pcl::PointXYZ>(filename, *cloud) == -1)//* load the file
  {
    spdlog::error("couldn't load points from file {0}", filename);
    // std::cerr << "Couldn't read file " << filename << std::endl;
    throw std::runtime_error("Couldn't read file");
    return py::array_t<double>();
  }

  // std::cout << "Loaded data points from " << filename << std::endl;
  // std::cout << "Width: " << cloud->width << std::endl;
  // std::cout << "Height: " << cloud->height << std::endl;
  spdlog::info("loaded {1} points from file {0}", filename, cloud->width * cloud->height);


  // Create a numpy array
  py::array_t<double> array =
    py::array_t<double>({ static_cast<uint64_t>(cloud->width * cloud->height), static_cast<uint64_t>(3) });

  auto r = array.mutable_unchecked<2>();
  for (auto i = 0; i < array.shape()[0]; i++) {
    r(i, 0) = cloud->points[i].x;
    r(i, 1) = cloud->points[i].y;
    r(i, 2) = cloud->points[i].z;
  }
  return array;
};

py::array_t<double> loadPlyFilePointXYZI(const char *filename)
{
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZI>);
  if (pcl::io::loadPLYFile<pcl::PointXYZI>(filename, *cloud) == -1)//* load the file
  {
    spdlog::error("couldn't load points from file {0}", filename);
    // std::cerr << "Couldn't read file " << filename << std::endl;
    throw std::runtime_error("Couldn't read file");
    return py::array_t<double>();
  }

  // std::cout << "Loaded data points from " << filename << std::endl;
  // std::cout << "Width: " << cloud->width << std::endl;
  // std::cout << "Height: " << cloud->height << std::endl;
  spdlog::info("loaded {1} points from file {0}", filename, cloud->width * cloud->height);


  // Create a numpy array
  py::array_t<double> array =
    py::array_t<double>({ static_cast<uint64_t>(cloud->width * cloud->height), static_cast<uint64_t>(4) });

  auto r = array.mutable_unchecked<2>();
  for (auto i = 0; i < array.shape()[0]; i++) {
    r(i, 0) = cloud->points[i].x;
    r(i, 1) = cloud->points[i].y;
    r(i, 2) = cloud->points[i].z;
    r(i, 4) = cloud->points[i].intensity;
  }
  return array;
};

py::array_t<double> loadPlyFilePointXYZRGB(const char *filename)
{
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
  if (pcl::io::loadPLYFile<pcl::PointXYZRGB>(filename, *cloud) == -1)//* load the file
  {
    spdlog::error("couldn't load points from file {0}", filename);
    // std::cerr << "Couldn't read file " << filename << std::endl;
    throw std::runtime_error("Couldn't read file");
    return py::array_t<double>();
  }

  // std::cout << "Loaded data points from " << filename << std::endl;
  // std::cout << "Width: " << cloud->width << std::endl;
  // std::cout << "Height: " << cloud->height << std::endl;
  spdlog::info("loaded {1} points from file {0}", filename, cloud->width * cloud->height);


  // Create a numpy array
  py::array_t<double> array =
    py::array_t<double>({ static_cast<uint64_t>(cloud->width * cloud->height), static_cast<uint64_t>(6) });

  auto r = array.mutable_unchecked<2>();
  for (auto i = 0; i < array.shape()[0]; i++) {
    r(i, 0) = cloud->points[i].x;
    r(i, 1) = cloud->points[i].y;
    r(i, 2) = cloud->points[i].z;
    r(i, 4) = cloud->points[i].r;
    r(i, 5) = cloud->points[i].g;
    r(i, 6) = cloud->points[i].b;
  }
  return array;
};

#endif// PCL_HELPER_IO_HPP