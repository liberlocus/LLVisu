cmake_minimum_required(VERSION 2.6.4)
project(liberVisu)
find_package(VTK REQUIRED)
include_directories("${VTK_INCLUDE_DIRS}")
find_package(HDF5 1.8.6 REQUIRED)
include_directories("${HDF5_INCLUDE_DIRS}")

include_directories("${CMAKE_SOURCE_DIR}")

add_definitions(-Wno-deprecated)

#add_library(liberVisu SHARED liberVisuHDF.h liberVisuHDF.cpp liberVisuXMF.h liberVisuXMF.cpp liberVisuVTK.h liberVisuVTK.cpp liberVisu.h)
add_library(liberVisu liberVisuHDF.h liberVisuHDF.cpp liberVisuXMF.h liberVisuXMF.cpp liberVisuVTK.h liberVisuVTK.cpp liberVisu.h)

target_link_libraries(liberVisu ${VTK_LIBRARIES})
target_link_libraries(liberVisu ${HDF5_LIBRARIES})

######### TESTING ####################

#ENABLE_TESTING()
#include(CTest)
#ADD_TEST(SimpleTest maestro.x)

######### PACKAGING ####################
set(CMAKE_BUILD_TYPE release)
include_directories(.) 
install(DIRECTORY liberVisu DESTINATION include FILES_MATCHING PATTERN *.h
PATTERN .svn EXCLUDE)
install(TARGETS liberVisu DESTINATION lib) 

SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "LiberLocus Visualization Library")
SET(CPACK_PACKAGE_VENDOR "LiberLocus")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.TXT")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYRIGHT.TXT")
SET(CPACK_GENERATOR "TGZ" "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Simsek Demir")
SET(CPACK_PACKAGE_VERSION_MAJOR "1")
SET(CPACK_PACKAGE_VERSION_MINOR "4")
SET(CPACK_PACKAGE_VERSION_PATCH "0")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "CMake ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")
INCLUDE(CPack)

