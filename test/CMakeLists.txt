set(GTEST_SHUFFLE 1)

#add include directory
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

#add excutable files
add_executable(
    PID-test
    main.cpp
    test.cpp
    ../include/PID.cpp
)

target_include_directories(PID-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(PID-test PUBLIC gtest)
