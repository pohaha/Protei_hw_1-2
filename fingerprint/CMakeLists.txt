add_library(Fingerprint "src/fingerprint.cpp")

list(APPEND EXTRA_INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/fingerprint/includes")

list(APPEND EXTRA_LINKED_SOURCES Certificate)
list(APPEND EXTRA_INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/certificate/includes")

list(APPEND EXTRA_LINKED_SOURCES Package)
list(APPEND EXTRA_INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/package/includes")

target_include_directories(Fingerprint
                           PUBLIC ${PROJECT_BINARY_DIR}
                           PUBLIC ${EXTRA_INCLUDE_DIRECTORIES}
                          )

target_link_libraries(Fingerprint
                      ${EXTRA_LINKED_SOURCES}
                     )