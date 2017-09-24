add_executable(PID_controller_app main.cpp ../include/PID.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
