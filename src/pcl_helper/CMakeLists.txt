pybind11_add_module(pcl_helper pcl_helper.cpp)
target_link_libraries(pcl_helper PRIVATE project_options project_warnings)
target_link_system_libraries(
  pcl_helper
  PRIVATE
  ${PCL_LIBRARIES}
  spdlog::spdlog
  fmt::fmt)
