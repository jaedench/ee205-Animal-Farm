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

    printf("cat index = [%d] name=[%s] gender=[%s] breed=[%s] isFixed=[%d] weight=[%f] collar1=[%s] collar2=[%s] license=[%llu]\n",
           index,
           cats[index].name,
           genderName(cats[index].gender),
           breedName(cats[index].breed),
           cats[index].isFixed,
           cats[index].weight,
           colorName(cats[index].collarColor1),
           colorName(cats[index].collarColor2),
           cats[index].license);

    return 0;
}


int printAllCats() {
    if (currentCats == 0) {
        fprintf(stderr, "%s: No cats stored!\n", PROGRAM_NAME);
        return 1;
    }


    //int i;
    for (int i = 0; i < currentCats; ++i) {
        printf("cat index =[%d] name=[%s] gender=[%s] breed=[%s] isFixed=[%d] weight=[%f] collar1=[%s] collar2[%s] license[%llu]\n",
               i,
               cats[i].name,
               genderName(cats[i].gender),
               breedName(cats[i].breed),
               cats[i].isFixed,
               cats[i].weight,
               colorName(cats[i].collarColor1),
               colorName(cats[i].collarColor2),
               cats[i].license);
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
            printf("Match with cat at index [%d]\n", i);
            return i;
        }
    }
    fprintf(stderr, "%s: Cat not found!", PROGRAM_NAME);
    return 1;
}