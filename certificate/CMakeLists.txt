project(Certificate C CXX)

add_library(${PROJECT_NAME} "src/certificate.cpp")

find_package(OpenSSL REQUIRED)

target_link_libraries(${PROJECT_NAME} OpenSSL::SSL)

target_include_directories(${PROJECT_NAME}
                   PUBLIC "${PROJECT_SOURCE_DIR}/includes"
                   PUBLIC ${PROJECT_BINARY_DIR}
                   PUBLIC ${EXTRA_INCLUDE_DIRECTORIES}
                    )
