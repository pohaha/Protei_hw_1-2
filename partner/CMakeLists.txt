add_library(Partner "src/partner.cpp")

list(APPEND EXTRA_INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/partner/includes")


target_include_directories(Partner
                           PUBLIC ${PROJECT_BINARY_DIR}
                           PUBLIC ${EXTRA_INCLUDE_DIRECTORIES}
                          )

target_link_libraries(Partner
                      #${EXTRA_LINKED_SOURCES}
                     )