add_library(Package "src/package.cpp")


list(APPEND EXTRA_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/package/includes")

target_include_directories(Package
                           PUBLIC ${PROJECT_BINARY_DIR}
                           PUBLIC ${EXTRA_INCLUDE_DIRECTORIES}
                          )