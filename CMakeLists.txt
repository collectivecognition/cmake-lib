cmake_minimum_required(VERSION 2.8.9)
SET(CMAKE_C_COMPILER C:\\\\MinGW\\\\bin\\\\gcc.exe)
SET(CMAKE_CXX_COMPILER C:\\\\MinGW\\\\bin\\\\g++.exe)
project(fooLib)
set(CMAKE_BUILD_TYPE Release)
 
#Bring the headers, such as Foo.h into the project
include_directories(include)
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
 
#Generate the shared library from the sources
add_library(foo SHARED ${SOURCES})

include (GenerateExportHeader)          
GENERATE_EXPORT_HEADER(foo           # generates the export header shared_EXPORTS.h automatically
    BASE_NAME foo
    EXPORT_MACRO_NAME foo_EXPORTS
    EXPORT_FILE_NAME foo_EXPORTS.h
    STATIC_DEFINE SHARED_EXPORTS_BUILT_AS_STATIC)
target_link_libraries(foo)  