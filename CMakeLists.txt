cmake_minimum_required(VERSION 3.22)
project(ee205-animal-farm)

set(CMAKE_CXX_STANDARD 14)

add_executable(ee205-animal-farm main.cpp config.h Cat.cpp Cat.h Gender.h Color.h Weight.cpp Weight.h Node.cpp Node.h List.cpp List.h SinglyLinkedList.cpp SinglyLinkedList.h Animal.cpp Animal.h Mammal.cpp Mammal.h Breed.h)
