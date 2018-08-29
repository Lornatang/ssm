CMAKE_MINIMUM_REQUIRED(VERSION 3.12)
project(ssm CXX)

SET(CMAKE_CXX_STANDARD 17)


add_library(user STATIC user/user.cc)

add_executable(ssm user/user.h user/user.cc user/file.h util/user.h user/base.h user/methods.h)

install(TARGETS ssm RUNTIME DESTINATION bin)
install(TARGETS user ARCHIVE DESTINATION ssm/lib)

