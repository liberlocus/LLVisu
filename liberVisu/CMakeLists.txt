cmake_minimum_required(VERSION 2.6.4)
project(liberVisu)
find_package(VTK REQUIRED)
include_directories("${VTK_INCLUDE_DIRS}")
#find_package(HDF5 REQUIRED)
#include_directories("${HDF5_INCLUDE_DIRS}")
include_directories("${CMAKE_SOURCE_DIR}")

add_definitions(-Wno-deprecated)

add_library(liberVisu liberVisuXMF.h liberVisuXMF.cpp liberVisuVTK.h liberVisuVTK.cpp liberVisuOut.h)
#add_library(liber liberVTK.h liberVTK.cpp liberXMF.h liberXMF.cpp liberOut.h liberOut.cpp)

target_link_libraries(liberVisu ${VTK_LIBRARIES})
#target_link_libraries(liber ${HDF5_LIBRARIES})

######### TESTING ####################

#ENABLE_TESTING()
#include(CTest)
#ADD_TEST(SimpleTest maestro.x)

######### PACKAGING ####################

SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "LiberLocus Visualization Library")
SET(CPACK_PACKAGE_VENDOR "LiberLocus")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.TXT")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYRIGHT.TXT")
SET(CPACK_GENERATOR "TGZ")
SET(CPACK_PACKAGE_VERSION_MAJOR "1")
SET(CPACK_PACKAGE_VERSION_MINOR "4")
SET(CPACK_PACKAGE_VERSION_PATCH "0")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "CMake ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")
INCLUDE(CPack)

