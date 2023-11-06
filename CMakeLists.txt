cmake_minimum_required(VERSION 3.5.0)
project(usth-cryptography VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_library(rsa assignment-03/rsa.cpp)

add_executable(assignment-03-test-keygen assignment-03/tests/test_keygen.cpp)
target_link_libraries(assignment-03-test-keygen PRIVATE rsa)

add_executable(assignment-03-test-encryption assignment-03/tests/test_rsa_01.cpp)
target_link_libraries(assignment-03-test-encryption PRIVATE rsa)

add_executable(assignment-03-test-parameters-01 assignment-03/tests/test_rsa_02.cpp)
target_link_libraries(assignment-03-test-parameters-01 PRIVATE rsa PUBLIC fmt)

add_executable(assignment-03-test-parameters-02 assignment-03/tests/test_rsa_03.cpp)
target_link_libraries(assignment-03-test-parameters-02 PRIVATE rsa PUBLIC fmt)

add_test(
    NAME assignment-03-test-keygen
    COMMAND $<TARGET_FILE:assignment-03-test-keygen>
)

add_test(
    NAME assignment-03-test-encryption
    COMMAND $<TARGET_FILE:assignment-03-test-encryption>
)

add_test(
    NAME assignment-03-test-parameters-01
    COMMAND $<TARGET_FILE:assignment-03-test-parameters-01>
)

add_test(
    NAME assignment-03-test-parameters-02
    COMMAND $<TARGET_FILE:assignment-03-test-parameters-02>
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
