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
        printf("%s: Invalid index!\n", PROGRAM_NAME);
        return false;
    }

    if (isValidName(newName) == false) {
        printf("%s: Invalid name!\n", PROGRAM_NAME);
        return false;
    }

    int i = 0;
    while (i <= MAX_CATS) {
        if (nameExists(i, newName) == false) {
            printf("%s: Name exists!\n", PROGRAM_NAME);
            return false;
        }
        i++;
    }

    strcpy(cats[index].name, newName);

    printf("Cat at index [%d] has been changed to [%s]!\n", index, newName);

    return true;
}



bool fixCat(const int index) {
    if (isValidIndex(index) == false) {
        printf("%s: Invalid index!\n", PROGRAM_NAME);
        return false;
    }

    if (cats[index].isFixed == true) {
        fprintf(stderr, "%s: Cat is already fixed! Too late to go back now...\n", PROGRAM_NAME);
        return false;
    }

    cats[index].isFixed = true;
    printf("Cat at index [%d] is fixed now!\n", index);
    return true;
}


bool updateCatWeight(const int index, const float newWeight) {
    if (isValidIndex(index) == false) {
        printf("%s: Invalid index!\n", PROGRAM_NAME);
        return false;
    }

    if (isValidWeight(newWeight) == false) {
        printf("%s: Invalid weight!\n", PROGRAM_NAME);
        return false;
    }

    cats[index].weight = newWeight;
    printf("Cat weight at index [%d] has been changed to [%f]\n", index, newWeight);
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