cmake_minimum_required(VERSION 3.1...3.17)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(MyProject VERSION 1.0 LANGUAGES CXX)

# Specify c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Specify compile flag here
if(("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU") OR ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang"))
    add_compile_options(-Wall -Wextra)
elseif(DEFINED MSVC)
    add_definitions(-DNOMINMAX)
endif()

add_executable(target ${PROJECT_SOURCE_DIR}/apps/main.cpp)

# Add library go here
add_library(fiblib STATIC ${PROJECT_SOURCE_DIR}/src/fib.cpp)
target_include_directories(fiblib PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(target PUBLIC fiblib)

