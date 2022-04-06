///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "addCats.h"
#include "catDatabase.h"
#include "config.h"
#include "catValidation.h"

//#define DEBUG


bool addCat(const char name[], const enum Gender gender, const enum Breed breed, const bool isFixed, const Weight weight, const enum Color collarColor1, const enum Color collarColor2, const unsigned long long license) {
    if (currentCats >= MAX_CATS) {
        fprintf(stderr,"%s: Too many cats! Current number of cats exceeds maximum cats allowed in database.\n", PROGRAM_NAME);
        return false;
    }
    if (isValidName(name) == false) {
        std::cout << PROGRAM_NAME << ": Invalid name!\n" << std::endl;
        return false;
    }
    if (isValidWeight(weight) == false) {
        std::cout << PROGRAM_NAME << ": Invalid weight!\n" << std::endl;
        return false;
    }


    int index = 0;
    while( (nameExists( index, name)) && (MAX_CATS > index) ) {
        index++;
    }
    index = 0;
    while( (nameEmpty( index )) && (MAX_CATS > index) ) {
        index++;  //places cat at the first empty index
    }

    strcpy(cats[currentCats].name, name);
    cats[currentCats].gender = gender;
    cats[currentCats].breed = breed;
    cats[currentCats].isFixed = isFixed;
    cats[currentCats].weight = weight;
    cats[currentCats].collarColor1 = collarColor1;
    cats[currentCats].collarColor2 = collarColor2;
    cats[currentCats].license = license;

    currentCats += 1;
    std::cout << "Cat successfully added!\n" << std::endl;
    return true;

#ifdef DEBUG
    printf("Current cats: %ld\n", currentCats);
      printf("Max length: %d\n", MAX_LENGTH);
      printf("Max cats: %d\n", MAX_CATS);
      printf("Name: %s\n", name);
      printf("Names of cats: %s\n", names[currentCats]);
      printf("Gender: %d\n", gender);
      printf("Genders of cats: %d\n", genders[currentCats]);
      printf("Breed: %d\n", breed);
      printf("Breeds of cats: %d\n", breeds[currentCats]);
      printf("Fixed: %d\n", isFixed);
      printf("Fixing of cats: %d\n", isFixedd[currentCats]);
      printf("Weight: %f\n", weight);
      printf("Weights of cats: %f\n", weights[currentCats]);
#endif

}
 */