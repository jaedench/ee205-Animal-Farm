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
#include <cstring>  // For strncmp
#include <stdexcept> // To throw if the enumName functions are bad
#include <cassert>

#include <stdio.h>
#include <string.h>

#include "catDatabase.h"
#include "reportCats.h"
#include "Cat.h"
#include "config.h"
/*
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
*/
/*
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
*/

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

/*
bool printAllCats() {
    int currentCats = 0;

    assert(validateDatabase());

    for (Cat *iCat = catDatabaseHeadPointer; iCat != nullptr; iCat = iCat->next) {
        iCat->print();
        currentCats++;
    }

    assert(validateDatabase());
    return true;
}


Cat* findCatByName(const char* name) {
    assert(Cat().validateName(name));

    //iterate through database until name matches
    for (Cat *iCat = catDatabaseHeadPointer; iCat != nullptr; iCat = iCat->next) {
        if (strcmp(name, iCat->getName()) == 0) {
            return iCat;
        }
    }

    // no match
    std::cout << "No matching cat in database" << std::endl;
    return nullptr;
}
 */