cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(hello)


option(USE_STATIC "Use static library" ON)
message(STATUS "OS: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Compile with static library? ${USE_STATIC}")


add_executable(hello hello.c)


add_library(message-objs
    OBJECT
    lib/hello.h
    lib/hello.cpp
)
target_compile_options(message-objs
    PRIVATE
        -Wall -fPIC
)


if(USE_STATIC)
    add_library(message-a
        STATIC
        $<TARGET_OBJECTS:message-objs>
    )
    target_link_libraries(hello message-a)

else()
    add_library(message-so
        SHARED
        $<TARGET_OBJECTS:message-objs>
    )
    target_link_libraries(hello message-so)
endif()