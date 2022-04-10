///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include <stdio.h>
#include <string.h>

#include "catDatabase.h"
#include "reportCats.h"

const char* colorName(const enum Color color) {
    switch(color) {
        case 0:
            return "Black";
        case 1:
            return "White";
        case 2:
            return "Red";
        case 3:
            return "Blue";
        case 4:
            return "Green";
        case 5:
            return "Pink";
    }
    return 0;
}


const char* genderName(const enum Gender gender) {
    switch(gender) {
        case 0:
            return "Unknown Gender";
        case 1:
            return "Male";
        case 2:
            return "Female";
    }
    return 0;
}


const char* breedName(const enum Breed breed) {
    switch(breed) {
        case 0:
            return "Unknown Breed";
        case 1:
            return "Maine Coon";
        case 2:
            return "Manx";
        case 3:
            return "Shorthair";
        case 4:
            return "Persian";
        case 5:
            return "Sphynx";
    }
    return 0;
}


int printCat(const int index) {
    if (index < 0 || index >= currentCats) {
        fprintf(stderr, "%s: Bad cat [%d]\n",PROGRAM_NAME, index);
        return 1;
    }

    std::cout << "cat index = [" << index << "] "
              << "name=["        << cats[index].name                          << "] "
              << "gender=["      << genderName(cats[index].gender)    << "] "
              << "breed=["       << breedName(cats[index].breed)       << "] "
              << "isFixed=["     << cats[index].isFixed                       << "] "
              << "weight=["      << cats[index].weight                        << "] "
              << "collar1=["     << colorName(cats[index].collarColor1) << "] "
              << "collar2=["     << colorName(cats[index].collarColor2) << "] "
              << "license=["     << cats[index].license                       << "] "
              << std::endl;

    return 0;
}


int printAllCats() {
    if (currentCats == 0) {
        fprintf(stderr, "%s: No cats stored!\n", PROGRAM_NAME);
        return 1;
    }


    //int i;
    for (int i = 0; i < currentCats; ++i) {
        std::cout << "cat index =[" << i << "] "
                  << "name=[" << cats[i].name << "] "
                  << "gender=[" << genderName(cats[i].gender) << "] "
                  << "breed=[" << breedName(cats[i].breed) << "] "
                  << "isFixed=[" << cats[i].isFixed << "] "
                  << "weight=[" << cats[i].weight << "] "
                  << "collar1=[" << colorName(cats[i].collarColor1) << "] "
                  << "collar2[" << colorName(cats[i].collarColor2) << "] "
                  << "license[" << cats[i].license << "]"
                  << std::endl;
    }
    return 0;
}

int findCat(const char name[]) {
    int i = 0;
    if (strlen(name) == 0) {
        fprintf(stderr,"%s: Hey! You need to enter a name!\n", PROGRAM_NAME);
        return 1;
    }


    if (strlen(name) > MAX_LENGTH) {
        fprintf(stderr, "%s: Name must be 30 characters or less! No cat's name is THAT long!\n", PROGRAM_NAME);
        return 1;
    }

    for (i = 0; i < currentCats; ++i) {
        if (strcmp(name, cats[i].name) == 0) {
            std::cout << "Match with cat at index " << i << "\n" << std::endl;
            return i;
        }
    }
    fprintf(stderr, "%s: Cat not found!", PROGRAM_NAME);
    return 1;
}
