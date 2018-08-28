CMAKE_MINIMUM_REQUIRED(VERSION 3.12)
project(lsm)

SET(CMAKE_CXX_STANDARD 17)

add_library(user STATIC account/user.cc)

add_executable(lsm account/user.h account/user.cc account/file.h account/util.h)

install(TARGETS lsm RUNTIME DESTINATION bin)
install(TARGETS user ARCHIVE DESTINATION lib)

