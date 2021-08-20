CMAKE_MINIMUM_REQUIRED(VERSION 3.4)

project(OpenSSL_parser C CXX)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(fingerprint)
list(APPEND EXTRA_INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/fingerprint/includes")
list(APPEND EXTRA_LIBRARY_DIRECTORIES "${PROJECT_SOURCE_DIR}/fingerprint")
list(APPEND EXTRA_LINKED_SOURCES Fingerprint)

add_subdirectory(certificate)
list(APPEND EXTRA_INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/certificate/includes")
list(APPEND EXTRA_LIBRARY_DIRECTORIES "${PROJECT_SOURCE_DIR}/certificate")
list(APPEND EXTRA_LINKED_SOURCES Certificate)


target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_BINARY_DIR}
    PUBLIC ${EXTRA_INCLUDE_DIRECTORIES}
)
target_link_directories(${PROJECT_NAME}
    PUBLIC ${EXTRA_LIBRARY_DIRECTORIES}
)

target_link_libraries(${PROJECT_NAME}
    ${EXTRA_LINKED_SOURCES}
)

