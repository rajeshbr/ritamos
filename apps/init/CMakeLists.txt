cmake_minimum_required(VERSION 3.20)

project(ritam-init C)

set(CMAKE_C_STANDARD 17)

add_executable(ritam-init
    src/main.c
    src/banner.c
    src/mount.c
    src/filesystem.c
    src/hostname.c
    src/logger.c
    src/network.c
    src/process.c
    src/console.c
    src/waitforever.c
    src/services.c
)

target_include_directories(ritam-init PRIVATE include)

target_link_options(ritam-init PRIVATE -static)
