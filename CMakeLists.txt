cmake_minimum_required(VERSION 3.3)

set(PROJECT_NAME      "clips-project")
set(PROJECT_VERSION   "0.0.1")
set(PROJECT_STRING    "${PROJECT_NAME} ${PROJECT_VERSION}")
set(PROJECT_TARNAME   "${PROJECT_NAME}-${PROJECT_VERSION}")

project(${PROJECT_NAME} CXX C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__FILENAME__='\"$(subst ${CMAKE_SOURCE_DIR}/,,$(abspath $<))\"'")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++1y -Ofast -march=native -Wdeprecated-register")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -O0 -gdwarf-2")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(LIBS ${LIBS} -lpthread -lrt -ldl)
else()
    set(LIBS ${LIBS} -lc++abi)
endif()

# lib
file(GLOB_RECURSE LIB_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc")
file(GLOB_RECURSE LIB_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(${PROJECT_NAME} ${LIB_SOURCE})
set(LIBS ${PROJECT_NAME} ${LIBS})

add_executable(${PROJECT_NAME}-exe ${CMAKE_CURRENT_SOURCE_DIR}/executables/clips-project.cc)
target_link_libraries(${PROJECT_NAME}-exe ${LIBS})
set_target_properties(${PROJECT_NAME}-exe PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
