CMAKE_MINIMUM_REQUIRED(VERSION 3.12)
project(lornabk)

SET(CMAKE_CXX_STANDARD 17)

add_executable(books account/create.h account/user.h account/user.cc)

