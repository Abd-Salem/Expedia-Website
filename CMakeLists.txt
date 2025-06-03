cmake_minimum_required(VERSION 3.10)
project(ExpediaSystem)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories for header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# List all source files with relative paths
set(SOURCES
    src/Airports.cpp
    src/Airport_APIs.cpp
    src/Expedia.cpp
    src/Expedia_Manager.cpp
    src/Flight_Reservation_info.cpp
    src/Hotel_APIs.cpp
    src/Hotel_Reservation_info.cpp
    src/Hotels.cpp
    src/Itinerary.cpp
    src/Itinerary_Builder.cpp
    src/Make_Payment.cpp
    src/Make_Reservation.cpp
    src/Payment_APIs.cpp
    src/Payment_Handler.cpp
    src/Payment_Methods.cpp
    src/User.cpp
    src/User_Manager.cpp
)

# Add executable target
add_executable(ExpediaSystem ${SOURCES})

# (Optional) You can add link libraries here if needed
# target_link_libraries(ExpediaSystem some_library)
