#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/modules)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} $ENV{HOME}/cmake/modules)
include_directories(inc)

find_package(ROOT REQUIRED)
include_directories(${ROOT_INCLUDE_DIR})

#find_package(Vc REQUIRED)
#include_directories(${VC_INCLUDE_DIR})

find_package(VectorClass REQUIRED)
include_directories(${VectorClass_INCLUDE_DIR})

find_package(NT2 REQUIRED)
include_directories(${NT2_INCLUDE_DIR})

find_package(BOOST REQUIRED)
include_directories(${BOOST_INCLUDE_DIR})

find_package(TBB)
include_directories(${TBB_INCLUDE_DIR})

#file(GLOB sources src/TGeoBBox_v.cxx src/TGeoTube_v.cxx )
file(GLOB headers ${CMAKE_CURRENT_SOURCE_DIR}/inc/*.h)

# for optimization studies, we compile this directory with higher Ox when no debug build
# TODO: check compiler etc
if(CMAKE_BUILD_TYPE MATCHES "Debug")
	set( BASEFLAGS "-O0 -fpermissive" )	
else()
# set baseflags as a function of the compiler:
      message(STATUS "setting up compilation flags to compile vectorized geometry")
 if( CMAKE_COMPILER_IS_GNUCXX )
      message(STATUS "configuration compile flags for gcc")
      set( BASEFLAGS "-Ofast -ftree-vectorize -ftree-vectorizer-verbose=0 -fpermissive" )
      #set( BASEFLAGS "-O3" )
  elseif( CMAKE_CXX_COMPILER_ID STREQUAL Intel )
      message(STATUS "configuring compile flags for Intel compiler")
      set( BASEFLAGS "-Ofast -restrict -vec-report=2" )
  endif()
endif()


if( USEVECEXTENSIONS)
  add_definitions( "-DVEC_EXTEN" )
  #set( BASEVCFLAGS "-std=c++11 -fabi-version=6" )
endif()

if( USE_VECTOR_CLASS)
  add_definitions("-DVECTOR_CLASS")
endif()

if( USE_BOOST_SIMD )
  add_definitions( "-DBOOST_SIMD" )
  #set( BASEFLAGS "-std=c++11 -fabi-version=6" )
  
endif()


if( USEAVX )
    set_source_files_properties(${sources} PROPERTIES COMPILE_FLAGS "${BASEFLAGS} -std=c++11 -mavx -fabi-version=6")
else()
    set_source_files_properties(${sources} PROPERTIES COMPILE_FLAGS "${BASEFLAGS} -std=c++11 -msse4.1")

endif(USEAVX)

#add_library(VecGeom SHARED ${sources} ${headers})
#add_library(VecGeom_static STATIC ${sources} ${headers})
#target_link_libraries(VecGeom ${ROOT_LIBRARIES} -lEG -lGeom)

#add_custom_target(VectorizedGeom DEPENDS VecGeom VecGeom_static)


#----------------------------------------------------------------------------
# Add some benchmarks and standard tests if wanted

#file(GLOB benchmarksources src/tests/TestSIMD.cpp)
file(GLOB benchmarksources BenchmarkFramework/testBoost.cxx)
set_source_files_properties(${benchmarksources} PROPERTIES COMPILE_FLAGS "${BASEFLAGS} -std=c++11")

    foreach( benchmarksrc  ${benchmarksources} )
        get_filename_component( BENCHEXEC  ${benchmarksrc} NAME_WE)
	message(STATUS "building benchmark ${BENCHEXEC}")
	add_executable( ${BENCHEXEC} ${benchmarksrc} ${headers})
	#target_link_libraries( ${BENCHEXEC} ${ROOT_LIBRARIES} -lrt -lGeom -L${CMAKE_LIBRARY_OUTPUT_DIRECTORY} -lVecGeom_static ${TBB_LIBRARIES})

	#add_dependencies( ${BENCHEXEC} VectorizedGeom )
    endforeach( benchmarksrc )



#----------------------------------------------------------------------------
 
