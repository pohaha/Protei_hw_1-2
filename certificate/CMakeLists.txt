add_library(Certificate "src/certificate.cpp")

find_package(OpenSSL REQUIRED)
list(APPEND EXTRA_LINKED_SOURCES OpenSSL::SSL)

list(APPEND EXTRA_INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/fingerprint/includes")
list(APPEND EXTRA_LIBRARY_DIRECTORIES "${PROJECT_SOURCE_DIR}/fingerprint")
list(APPEND EXTRA_LINKED_SOURCES Fingerprint)

target_include_directories(Certificate
                           PUBLIC ${PROJECT_BINARY_DIR}
                           PUBLIC ${EXTRA_INCLUDE_DIRECTORIES}
                          )

target_link_libraries(Certificate
                      ${EXTRA_LINKED_SOURCES}
                     )
