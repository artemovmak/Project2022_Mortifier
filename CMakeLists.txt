cmake_minimum_required(VERSION 3.16)
project(The_Game)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)


add_executable(The_Game main.cpp ../Engine.cpp ../Field.cpp ../Farmer.cpp ../Input.cpp ../Music.cpp ../Update.cpp ../Draw.cpp)
target_link_libraries(The_Game sfml-graphics sfml-audio)