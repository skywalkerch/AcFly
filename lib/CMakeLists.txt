aux_source_directory(lib_src/src DIR_LIB_SRC)
aux_source_directory(lib_src/src/sort DIR_LIB_SRC)
aux_source_directory(lib_src/include DIR_LIB_INCLUDE)
include_directories(lib_src/include)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
add_library(AcFly STATIC ${DIR_LIB_SRC} ${DIR_LIB_INCLUDE} )
