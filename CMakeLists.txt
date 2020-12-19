cmake_minimum_required(VERSION 3.18)
project(msvcweak)

add_subdirectory(src)
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT msvcweak)
