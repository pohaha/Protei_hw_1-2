add_library(Fingerprint_Reciever "src/fingerprint_reciever.cpp")

list(APPEND EXTRA_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/fingerprint_reciever/includes")

list(APPEND EXTRA_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/fingerprint/includes")
list(APPEND EXTRA_LIBRARY_DIRECTORIES "${CMAKE_SOURCE_DIR}/out/build/fingerprint")
list(APPEND EXTRA_LINKED_SOURCES Fingerprint)

list(APPEND EXTRA_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/package/includes")
list(APPEND EXTRA_LIBRARY_DIRECTORIES "${CMAKE_SOURCE_DIR}/out/build/package")
list(APPEND EXTRA_LINKED_SOURCES Package)

target_include_directories(Fingerprint_Reciever
                           PUBLIC ${PROJECT_BINARY_DIR}
                           PUBLIC ${EXTRA_INCLUDE_DIRECTORIES}
                          )

target_link_libraries(Fingerprint_Reciever
                      ${EXTRA_LINKED_SOURCES}
                     )