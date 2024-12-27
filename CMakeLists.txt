cmake_minimum_required(VERSION 3.10)
add_library(neolog STATIC
    neolog.c
    neolog.h
)

target_include_directories(neolog PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}"
)
