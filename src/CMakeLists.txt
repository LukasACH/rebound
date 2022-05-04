add_library(rebound SHARED)
target_include_directories(rebound PUBLIC ${MY_LIB_SOURCE_DIR})

# source files get added as before
target_sources(rebound PUBLIC ${MY_LIB_SOURCE_DIR}/my_lib/my_lib.cpp)

# header files get added via FILE_SET
# BASE_DIR should point to the same directory that is used as the 
# target_include_directory, otherwise the install paths may be off.
target_sources(rebound PUBLIC FILE_SET HEADERS
  BASE_DIRS ${MY_LIB_SOURCE_DIR}
  FILES ${MY_LIB_SOURCE_DIR}/my_lib/my_lib.hpp)

# install command needs to reference the file set again
install(TARGETS my_lib FILE_SET HEADERS)


add_library(rebound SHARED
    rebound.c
    binarydiff.c
    boundary.c
    collision.c
    display.c
    gravity.c
    input.c
    integrator.c
    integrator_bs.c
    integrator_eos.c
    integrator_ias15.c
    integrator_janus.c
    integrator_leapfrog.c
    integrator_mercurius.c
    integrator_saba.c
    integrator_sei.c
    integrator_whfast.c
    output.c
    particle.c
    simulationarchive.c
    tools.c
    transformations.c
    tree.c
)
target_include_directories(rebound PUBLIC ${CURRENT_SOURCE_DIR})