cmake_minimum_required(VERSION 3.28)
project(example34 C)

set(CMAKE_C_STANDARD 11)

add_library(sensor sensor.c)

add_executable(example34 main.c)
target_link_libraries(example34 sensor)

enable_testing()
add_executable(test_sensor test_sensor.c)
target_link_libraries(test_sensor sensor)
add_test(NAME sensor COMMAND test_sensor)
