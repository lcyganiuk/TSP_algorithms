cmake_minimum_required(VERSION 4.1)
project(zad1)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")

if(WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -static")
endif()

add_executable(zad1
        src/bruteforce.cpp
        src/config.cpp
        src/config.h
        src/loader.cpp
        src/loader.h
        src/main.cpp
        src/nn.cpp
        src/rand.cpp
        src/rnn.cpp
        src/tsp.cpp
        src/tsp.h)
add_executable(generator generator.cpp)

set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")

if(WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -static")
endif()