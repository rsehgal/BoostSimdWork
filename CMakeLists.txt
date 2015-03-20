#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(GEANTVProto)


#---Set pathes where to put the libraries, executables and headers------------------------------
if(NOT OUTDIR)
  set(OUTDIR ${PROJECT_SOURCE_DIR})
endif()
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTDIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTDIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTDIR}/bin)

#----------------------------------------------------------------------------
# Find ROOT and setup the libraries
#
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/modules)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} $ENV{HOME}/cmake/modules)
find_package(ROOT REQUIRED)
find_package(BOOSTSIMD REQUIRED)

include_directories(${ROOT_INCLUDE_DIR})
#include_directories(/home/raman/BackBoneSoftwares/boost-simd/include)
include_directories(${BOOSTSIMD_INCLUDE_DIR})
#----------------------------------------------------------------------------
if(CUSTOM_ALLOCATOR)
  find_package(CAllocator)
endif()

#----------------------------------------------------------------------------
# Add subdirectories
#

#add_subdirectory (geom_vec_tests)
add_subdirectory (boost_vec_tests)
