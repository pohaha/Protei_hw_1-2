project(Tests C CXX)

add_executable(${PROJECT_NAME} main.cpp)

set(CMAKE_VERBOSE_MAKEFILE ON)

include(FetchContent)

FetchContent_Declare(googletest
  GIT_REPOSITORY https://github.com/google/googletest.git)
FetchContent_MakeAvailable(googletest)



list(APPEND EXTRA_INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/../fingerprint/includes")
list(APPEND EXTRA_LIBRARY_DIRECTORIES "${PROJECT_SOURCE_DIR}/../fingerprint")
list(APPEND EXTRA_LINKED_SOURCES Fingerprint)

list(APPEND EXTRA_INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/../package/includes")
list(APPEND EXTRA_LIBRARY_DIRECTORIES "${PROJECT_SOURCE_DIR}/../package")
list(APPEND EXTRA_LINKED_SOURCES Package)


target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_BINARY_DIR}
    PUBLIC ${EXTRA_INCLUDE_DIRECTORIES}
)
target_link_directories(${PROJECT_NAME}
    PUBLIC ${EXTRA_LIBRARY_DIRECTORIES}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE gtest
    ${EXTRA_LINKED_SOURCES}
)