# - Finds Vc installation ( the wrapper library to SIMD intrinsics )
# This module sets up Vc information 
# It defines:
# BOOSTSIMD_FOUND          If the ROOT is found
# BOOSTSIMD_INCLUDE_DIR    PATH to the include directory
# BOOSTSIMD_LIBRARIES      Most common libraries
# BOOSTSIMD_LIBRARY_DIR    PATH to the library directory 

# look if an environment variable BOOSTSIMDROOT exists
set(BOOSTSIMDROOT $ENV{BOOSTSIMDROOT})

find_library(BOOSTSIMD_LIBRARIES libBOOSTSIMD.a PATHS ${BOOSTSIMDROOT}/lib)
if (BOOSTSIMD_LIBRARIES) 
   set(BOOSTSIMD_FOUND TRUE)	
   string(REPLACE "/lib/libBOOSTSIMD.a" "" BOOSTSIMDROOT  ${BOOSTSIMD_LIBRARIES})
   set(BOOSTSIMD_INCLUDE_DIR ${BOOSTSIMDROOT}/include)
   set(BOOSTSIMD_LIBRARY_DIR ${BOOSTSIMDROOT}/lib)
   message(STATUS "Found BOOSTSIMD library in ${BOOSTSIMD_LIBRARIES}")		
else()
   message(STATUS "BOOSTSIMD library not found; try to set a BOOSTSIMDROOT environment variable to the base installation path or add -DBOOSTSIMDROOT= to the cmake command")	
endif()



