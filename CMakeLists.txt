cmake_minimum_required(VERSION 3.5.0)
project(usth-cryptography VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_library(rsa assignment-03/rsa.cpp)

add_executable(assignment-03-test-keygen assignment-03/tests/test_keygen.cpp)
target_link_libraries(assignment-03-test-keygen PRIVATE rsa PUBLIC fmt)

add_test(
    NAME assignment-03-test-keygen
    COMMAND $<TARGET_FILE:assignment-03-test-keygen>
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
