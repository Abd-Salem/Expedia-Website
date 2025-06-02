cmake_minimum_required(VERSION 3.15)
project(ExpediaSystem)

# Explicitly set compilers
set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Print current directory for debugging
message(STATUS "Current source directory: ${CMAKE_CURRENT_SOURCE_DIR}")

# List files manually since GLOB isn't working
set(SOURCES
    ../src/Airports.cpp
    ../src/Airport_APls.cpp
    ../src/Expedia.cpp
    ../src/Expedia_Manager.cpp
    ../src/Flight_Reservation_info.cpp
    ../src/Hotel_APls.cpp
    ../src/Hotel_Reservation_info.cpp
    ../src/Hotels.cpp
    ../src/Itinerary.cpp
    ../src/Itinerary_Builder.cpp
    ../src/Make_Payment.cpp
    ../src/Make_Reservation.cpp
    ../src/Payment_APls.cpp
    ../src/Payment_Handler.cpp
    ../src/Payment_Methods.cpp
    ../src/User.cpp
    ../src/User_Manager.cpp
)

set(HEADERS
    ../include/Airport_APIs.hpp
    ../include/Airports.hpp
    ../include/Expedia_Manager.hpp
    ../include/Flight_Reservation.hpp
    ../include/Flight_Reservation_Info.hpp
    ../include/Hotel_APIs.hpp
    ../include/Hotel_Reservation.hpp
    ../include/Hotel_Reservation_Info.hpp
    ../include/Hotels.hpp
    ../include/Itinerary.hpp
    ../include/Itinerary_Builder.hpp
    ../include/Json.hpp
    ../include/Make_Paymente.hpp
    ../include/Make_Reservaion.hpp
    ../include/Payment.hpp
    ../include/Payment_APIs.hpp
    ../include/Payment_Handler.hpp
    ../include/Payment_Methods.hpp
    ../include/Properties.hpp
    ../include/Transactions.hpp
    ../include/User.hpp
    ../include/User_Manager.hpp
)

# Verify source files exist
foreach(src ${SOURCES})
    if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${src}")
        message(WARNING "Source file not found: ${src}")
    endif()
endforeach()

add_executable(ExpediaSystem ${SOURCES} ${HEADERS})

target_include_directories(ExpediaSystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(WIN32)
    target_compile_definitions(ExpediaSystem PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

# Print found files
message(STATUS "Source files: ${SOURCES}")
message(STATUS "Header files: ${HEADERS}")