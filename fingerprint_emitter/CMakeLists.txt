add_library(Fingerprint_Emitter "src/fingerprint_emitter.cpp")

list(APPEND EXTRA_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/fingerprint_emitter/includes")

list(APPEND EXTRA_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/fingerprint/includes")
list(APPEND EXTRA_LIBRARY_DIRECTORIES "${CMAKE_SOURCE_DIR}/out/build/fingerprint")
list(APPEND EXTRA_LINKED_SOURCES Fingerprint)

list(APPEND EXTRA_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/package/includes")
list(APPEND EXTRA_LIBRARY_DIRECTORIES "${CMAKE_SOURCE_DIR}/out/build/package")
list(APPEND EXTRA_LINKED_SOURCES Package)

target_include_directories(Fingerprint_Emitter
                           PUBLIC ${PROJECT_BINARY_DIR}
                           PUBLIC ${EXTRA_INCLUDE_DIRECTORIES}
                          )

target_link_libraries(Fingerprint_Emitter
                      ${EXTRA_LINKED_SOURCES}
                     )