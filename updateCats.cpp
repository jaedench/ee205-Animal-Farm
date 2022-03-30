///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.cpp
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "catDatabase.h"
#include "config.h"
#include "updateCats.h"
#include "catValidation.h"

bool updateCatName(const int index, const char newName[]) {
    if (index >= currentCats) {
        fprintf(stderr, "%s: No cat at index [%d] to update.\n", PROGRAM_NAME, index);
        return false;
    }

    if (isValidIndex(index) == false) {
        std::cout << PROGRAM_NAME << ": Invalid index!\n" << std::endl;
        return false;
    }

    if (isValidName(newName) == false) {
        std::cout << PROGRAM_NAME << ": Invalid name!\n" << std::endl;
        return false;
    }

    int i = 0;
    while (i <= MAX_CATS) {
        if (nameExists(i, newName) == false) {
            std::cout << PROGRAM_NAME << ": Name exists!\n" << std::endl;
            return false;
        }
        i++;
    }

    strcpy(cats[index].name, newName);

    std::cout << "Cat at index [" << index << "] has been changed to [" << newName << "]!\n" << std::endl;

    return true;
}



bool fixCat(const int index) {
    if (isValidIndex(index) == false) {
        std::cout << PROGRAM_NAME << ": Invalid index!\n" << std::endl;
        return false;
    }

    if (cats[index].isFixed == true) {
        fprintf(stderr, "%s: Cat is already fixed! Too late to go back now...\n", PROGRAM_NAME);
        return false;
    }

    cats[index].isFixed = true;
    std::cout << "Cat at index [" << index << "] is fixed now!\n" << std::endl;
    return true;
}


bool updateCatWeight(const int index, const Weight newWeight) {
    if (isValidIndex(index) == false) {
        std::cout << PROGRAM_NAME << ": Invalid index!\n" << std::endl;
        return false;
    }

    if (isValidWeight(newWeight) == false) {
        std::cout << PROGRAM_NAME << ": Invalid weight!\n" << std:: endl;
        return false;
    }

    cats[index].weight = newWeight;
    std::cout << "Cat weight at index [" << index << "] has been changed to [" << newWeight << "]\n" << std::endl;
    return true;
}


bool updateCatCollar1(const int index, const enum Color newColor1) {
    cats[index].collarColor1 = newColor1;
    return true;
}


bool updateCatCollar2(const int index, const enum Color newColor2) {
    cats[index].collarColor2 = newColor2;
    return true;
}


bool updateLicense(const int index, const unsigned long long newLicense) {
    cats[index].license = newLicense;
    return true;
}