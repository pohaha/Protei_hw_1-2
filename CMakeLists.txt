CMAKE_MINIMUM_REQUIRED(VERSION 3.14..3.20)
project(Shared_Memory C CXX)

#TDD STUFF
option(WITH_MY_TESTS "Do we want to configure tests" ON)
if (WITH_MY_TESTS)
    add_subdirectory(tests)
endif()

add_subdirectory(producer)
add_subdirectory(consumer)
add_subdirectory(fingerprint)
add_subdirectory(certificate)
add_subdirectory(package)
add_subdirectory(fingerprint_emitter)
