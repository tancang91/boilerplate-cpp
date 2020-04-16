cmake_minimum_required(VERSION 3.1...3.17)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(MyProject VERSION 1.0 LANGUAGES CXX)

# Specify c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(FIB_TESTING "Fib testing [default: ON]" OFF)

# Specify compile flag here
if(("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU") OR ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang"))
    add_compile_options(-Wall -Wextra)
elseif(DEFINED MSVC)
    add_definitions(-DNOMINMAX)
endif()

# ----------------------------------------------------------------------------
# dependencies

if(FIB_TESTING)
    set(CATCH_INSTALL_DOC OFF CACHE BOOL "Catch2: Install documentation.")
    set(CATCH_INSTALL_HELPERS OFF CACHE BOOL "Catch2: Install helpers.")
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/catch2")
endif()

# ----------------------------------------------------------------------------
# Library

add_library(fiblib STATIC ${PROJECT_SOURCE_DIR}/src/fib.cpp)
target_include_directories(fiblib PUBLIC ${PROJECT_SOURCE_DIR}/include)

# ----------------------------------------------------------------------------
# Executable
add_executable(target ${PROJECT_SOURCE_DIR}/apps/main.cpp)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
target_compile_options(target PUBLIC
    $<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>
)
target_link_libraries(target PUBLIC
    "$<$<CONFIG:Debug>:-fsanitize=address>"
    fiblib
)

# -----------------------------------------------------------------------------
# TEST
if(FIB_TESTING)
    enable_testing()
    add_executable(test_fib
        test/fib_test.cpp)
    target_link_libraries(test_fib fiblib Catch2::Catch2)
    add_test(test_fib ./test_fib)
endif()
