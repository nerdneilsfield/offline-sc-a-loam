add_library(scancontext SHARED Scancontext.cpp)
target_link_libraries(
  scancontext
  PUBLIC
  project_options
  project_warnings)
target_include_directories(
  scancontext
  PUBLIC
  ${PCL_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS})
target_link_system_libraries(
  scancontext
  PRIVATE
  ${PCL_LIBRARIES}
  ${OpenCV_LIBS})
