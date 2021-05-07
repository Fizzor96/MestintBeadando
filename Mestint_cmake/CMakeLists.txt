cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 14)
project(korongok)

set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static-libgcc")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_C_FLAGS} -static-libgcc -s")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS} -static-libgcc -static-libstdc++ -s")



set(SFML_DIR "cmake_modules/SFML-2.5.1/lib/cmake/SFML")
find_package (SFML 2.5 COMPONENTS system window graphics audio REQUIRED)
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "cmake_modules/SFML/include")
target_link_libraries(${CMAKE_PROJECT_NAME} sfml-graphics sfml-system sfml-audio sfml-window)
