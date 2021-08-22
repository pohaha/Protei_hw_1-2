CMAKE_MINIMUM_REQUIRED(VERSION 3.4)
project(Shared_Memory C CXX)

add_subdirectory(producer)
add_subdirectory(consumer)
add_subdirectory(fingerprint)
add_subdirectory(certificate)
add_subdirectory(package)
add_subdirectory(fingerprint_emitter)
