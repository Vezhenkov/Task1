project(sgp_lib)

set(SOURCE_FILES
        sgp4sdp4.c
        sgp_in.c
        sgp_math.c
        sgp_obs.c
        sgp_time.c
        solar.c
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB REQUIRED IMPORTED_TARGET glib-2.0)

add_library(sgp_lib SHARED ${SOURCE_FILES})
set_target_properties(sgp_lib PROPERTIES PUBLIC_HEADER sgp4sdp4.h)
target_link_libraries(sgp_lib PkgConfig::GLIB)
