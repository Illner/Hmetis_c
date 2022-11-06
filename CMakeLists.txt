cmake_minimum_required(VERSION 3.14)
project(Hmetis)

#set (CMAKE_C_FLAGS "-m32")
set(CMAKE_CXX_STANDARD 20)

add_executable(Hmetis main.cpp)
set_target_properties(Hmetis PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

# macOS
IF (${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    # Apple Silicon
    IF (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "arm64")
        message("Operating system: macOS (Apple Silicon)")
        target_link_libraries(Hmetis "${CMAKE_SOURCE_DIR}/macOS/libhmetis.a")
    # Intel
    ELSE ()
        message("Operating system: macOS (Intel)")
        target_link_libraries(Hmetis "${CMAKE_SOURCE_DIR}/macOS/libhmetis.a")
    ENDIF ()

# Windows
ELSEIF ((${CMAKE_SYSTEM_NAME} STREQUAL "Windows") OR (CMAKE_SYSTEM_NAME STREQUAL "CYGWIN"))
    message("Operating system: Windows")
    target_link_libraries(Hmetis "${CMAKE_SOURCE_DIR}/Windows/libhmetis.lib")

# Linux
ELSEIF (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    message("Operating system: Linux")
    target_link_libraries(Hmetis "${CMAKE_SOURCE_DIR}/Linux/libhmetis.a")

# Undefined
ELSE()
    message(FATAL_ERROR "Your operating system (" ${CMAKE_SYSTEM_NAME} ") is not supported!")
ENDIF()
