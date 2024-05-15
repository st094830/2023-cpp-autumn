cmake_minimum_required(VERSION 3.14)

project(Deep_First_Search_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(${PROJECT_NAME} "main.cpp"  )

target_link_libraries(${PROJECT_NAME} Deep_First_Search)