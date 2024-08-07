cmake_minimum_required (VERSION 3.18)
project (HDF4_HDF_TEST C)

#-----------------------------------------------------------------------------
# Generate the srcdir_str.h file
#-----------------------------------------------------------------------------
set (srcdir ${HDF4_HDF_TEST_SOURCE_DIR})
configure_file (${HDF4_HDF_TEST_SOURCE_DIR}/srcdir_str.h.in srcdir_str.h  @ONLY)

LINK_DIRECTORIES (
    ${HDF4_HDF_BINARY_DIR}
    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
)

set (testhdf_SRCS
    ${HDF4_HDF_TEST_SOURCE_DIR}/testhdf.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/an.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/anfile.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/bitio.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/blocks.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/chunks.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/comp.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/conv.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/extelt.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/file.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/file1.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/litend.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/macros.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/man.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/mgr.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/nbit.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/rig.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/sdmms.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/sdnmms.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/sdstr.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/slab.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/tattdatainfo.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/tbv.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/tdatainfo.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/tdfr8.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/tdupimgs.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/tmgrattr.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/tmgrcomp.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/tree.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/tszip.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/tusejpegfuncs.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/tutils.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/tvattr.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/tvnameclass.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/tvset.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/tvsfpack.c
    ${HDF4_HDF_TEST_SOURCE_DIR}/vers.c
  )

#-- Adding test for testhdf
add_executable (testhdf ${testhdf_SRCS})
target_include_directories(testhdf PRIVATE "${HDF4_HDF_BINARY_DIR};${HDF4_BINARY_DIR};${CMAKE_CURRENT_BINARY_DIR};${HDF4_COMP_INCLUDE_DIRECTORIES};${HDF4_HDFSOURCE_DIR}")
if (NOT BUILD_SHARED_LIBS)
  TARGET_C_PROPERTIES (testhdf STATIC)
  target_link_libraries (testhdf PRIVATE ${HDF4_SRC_LIB_TARGET} ${LINK_COMP_LIBS})
else ()
  TARGET_C_PROPERTIES (testhdf SHARED)
  target_link_libraries (testhdf PRIVATE ${HDF4_SRC_LIBSH_TARGET} ${LINK_COMP_LIBS})
endif ()
set_target_properties (testhdf PROPERTIES FOLDER test)

#-- Adding test for buffer
if (NOT WIN32)
  add_executable (buffer ${HDF4_HDF_TEST_SOURCE_DIR}/buffer.c)
  target_include_directories(buffer PRIVATE "${HDF4_HDF_BINARY_DIR};${HDF4_BINARY_DIR};${HDF4_HDFSOURCE_DIR}")
  if (NOT BUILD_SHARED_LIBS)
    TARGET_C_PROPERTIES (buffer STATIC)
    target_link_libraries (buffer PRIVATE ${HDF4_SRC_LIB_TARGET})
  else ()
    TARGET_C_PROPERTIES (buffer SHARED)
    target_link_libraries (buffer PRIVATE ${HDF4_SRC_LIBSH_TARGET})
  endif ()
  set_target_properties (buffer PROPERTIES FOLDER test)
endif ()

include (CMakeTests.cmake)
