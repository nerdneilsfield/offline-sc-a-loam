cmake_minimum_required(VERSION 3.15...3.23)

project(CmakeConfigPackageTests LANGUAGES CXX)

# ---- Test as standalone project the exported config package ----

if(PROJECT_IS_TOP_LEVEL OR TEST_INSTALLED_VERSION)
  enable_testing()

  # find_package(myproject CONFIG REQUIRED) # for intro, project_options, ...

  # if(NOT TARGET myproject::project_options)
  #   message(FATAL_ERROR "Requiered config package not found!")
  #   return() # be strictly paranoid for Template Janitor github action! CK
  # endif()
endif()

# # ---- Dependencies ----

# # find_package(Catch2 CONFIG REQUIRED)
# if(Catch2_ADDED)
#   message(STATUS "Catch2 already added")
#   include(${Catch2_SOURCE_DIR}/extras/Catch.cmake)
# endif()

# # add_library(catch_main OBJECT catch_main.cpp)
# # target_link_libraries(catch_main PUBLIC Catch2::Catch2)
# # target_include_directories(catch_main PUBLIC ${Catch2_SOURCE_DIR}/src)
# # target_link_libraries(catch_main PRIVATE myproject::project_options)

# add_library(catch_main INTERFACE)
# target_link_system_libraries(
#   catch_main 
#   INTERFACE
#   Catch2::Catch2WithMain
# )


# # Provide a simple smoke test to make sure that the CLI works and can display a --help message
# add_test(NAME cli.has_help COMMAND intro --help)

# # Provide a test to verify that the version being reported from the application
# # matches the version given to CMake. This will be important once you package
# # your program. Real world shows that this is the kind of simple mistake that is easy
# # to make, but also easy to test for.
# add_test(NAME cli.version_matches COMMAND intro --version)
# set_tests_properties(cli.version_matches PROPERTIES PASS_REGULAR_EXPRESSION "${PROJECT_VERSION}")

# add_executable(tests tests.cpp)
# target_link_libraries(tests PRIVATE  catch_main)
# message(STATUS ${Catch2_SOURCE_DIR})
# target_include_directories(tests PUBLIC ${Catch2_SOURCE_DIR}/src)


# # automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# # to whatever you want, or use different for different binaries
# # catch_discover_tests(
# #   tests
# #   TEST_PREFIX
# #   "unittests."
# #   REPORTER
# #   xml
# #   OUTPUT_DIR
# #   .
# #   OUTPUT_PREFIX
# #   "unittests."
# #   OUTPUT_SUFFIX
# #   .xml)
# catch_discover_tests(tests)

# # Add a file containing a set of constexpr tests
# add_executable(constexpr_tests constexpr_tests.cpp)
# target_link_libraries(constexpr_tests PRIVATE  catch_main)

# # catch_discover_tests(
# #   constexpr_tests
# #   TEST_PREFIX
# #   "constexpr."
# #   REPORTER
# #   json
# #   OUTPUT_DIR
# #   .
# #   OUTPUT_PREFIX
# #   "constexpr."
# #   OUTPUT_SUFFIX
# #   .json)
# catch_discover_tests(constexpr_tests)

# # Disable the constexpr portion of the test, and build again this allows us to have an executable that we can debug when
# # things go wrong with the constexpr testing
# add_executable(relaxed_constexpr_tests constexpr_tests.cpp)
# target_link_libraries(relaxed_constexpr_tests PRIVATE  catch_main)
# target_compile_definitions(relaxed_constexpr_tests PRIVATE -DCATCH_CONFIG_RUNTIME_STATIC_REQUIRE)

# # catch_discover_tests(
# #   relaxed_constexpr_tests
# #   TEST_PREFIX
# #   "relaxed_constexpr."
# #   REPORTER
# #   json
# #   OUTPUT_DIR
# #   .
# #   OUTPUT_PREFIX
# #   "relaxed_constexpr."
# #   OUTPUT_SUFFIX
# #   .json)
# catch_discover_tests(relaxed_constexpr_tests)


pybind11_add_module(numpy_array_size numpy_array_size.cpp)
target_link_libraries(numpy_array_size PRIVATE pybind11::headers)
# target_include_directories(numpy_array_size PRIVATE ${CMAKE_BINARY_DIR}/_deps/pybind11-src/include)
