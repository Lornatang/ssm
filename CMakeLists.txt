CMAKE_MINIMUM_REQUIRED(VERSION 3.12)
project(lornabk)

SET(CMAKE_CXX_STANDARD 17)

add_library(lornabk SHARED src/user.cc src/view.cc src/lornabk.cc)

add_executable(books include/user.h src/user.cc src/view.cc include/view.h src/lornabk.cc)

install(TARGETS books lornabk
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib)