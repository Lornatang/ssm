CMAKE_MINIMUM_REQUIRED(VERSION 3.12)
project(ssm CXX)

SET(CMAKE_CXX_STANDARD 17)

add_library(account STATIC account/user.cc)


add_executable(ssm account/user.h account/user.cc account/file.h account/util.h)

install(TARGETS ssm RUNTIME DESTINATION bin)
install(TARGETS account ARCHIVE DESTINATION ssm/lib)

