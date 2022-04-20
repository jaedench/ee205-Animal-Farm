cmake_minimum_required(VERSION 3.22)
project(ee205-animal-farm)

set(CMAKE_CXX_STANDARD 14)

add_executable(ee205-animal-farm main.cpp addCats.cpp addCats.h config.h catValidation.cpp catValidation.h deleteCats.cpp deleteCats.h reportCats.cpp reportCats.h updateCats.cpp updateCats.h catDatabase.cpp catDatabase.h Cat.cpp Cat.h Gender.h)
