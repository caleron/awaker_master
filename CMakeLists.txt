cmake_minimum_required(VERSION 3.6)
project(awaker_master)

set(CMAKE_CXX_STANDARD 11)

include_directories(C:\\dev\\Awaker\\libraries\\)
include_directories(C:\\dev\\Awaker\\libraries\\RF24)
include_directories(C:\\dev\\Awaker\\libraries\\RF24Network)
include_directories(C:\\dev\\Awaker\\libraries\\RF24Mesh)

set(SOURCE_FILES AwakerMesh.cpp AwakerMesh.h)
add_executable(awaker_master ${SOURCE_FILES})