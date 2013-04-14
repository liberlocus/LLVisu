cmake_minimum_required(VERSION 2.6.4)
project(liber)
find_package(VTK REQUIRED)
include_directories("${VTK_INCLUDE_DIRS}")
#find_package(HDF5 REQUIRED)
#include_directories("${HDF5_INCLUDE_DIRS}")
include_directories("${CMAKE_SOURCE_DIR}")

add_definitions(-Wno-deprecated)

add_library(liber liberVTK.h liberVTK.cpp liberXMF.h liberXMF.cpp liberOut.h liberOut.cpp)

target_link_libraries(liber ${VTK_LIBRARIES})
#target_link_libraries(liber ${HDF5_LIBRARIES})



