#Specify the version being used as well as the language
cmake_minimum_required(VERSION 2.6C)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")
# The version number.
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)
#Name your project here
project(maestro)

add_definitions(-Wno-deprecated)
add_executable(maestro.x main.cpp)

find_package(liberVisu)
if (liberVisu_FOUND)
  include_directories(${liberVisu_INCLUDE_DIRS})
  target_link_libraries (maestro.x ${liberVisu_LIBRARIES})
endif (liberVisu_FOUND)

find_package(VTK REQUIRED)
if (VTK_FOUND)
  include_directories(${VTK_INCLUDE_DIRS})
  target_link_libraries (maestro.x ${VTK_LIBRARIES})
endif (VTK_FOUND)

find_package(HDF5 1.8.6 REQUIRED)
if (HDF5_FOUND)
  include_directories(${HDF5_INCLUDE_DIRS})
  target_link_libraries (maestro.x ${HDF5_LIBRARIES})
endif (HDF5_FOUND)
############## TESTING ###############

ENABLE_TESTING()
include(CTest)
ADD_TEST(SimpleTest maestro.x)
