///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>

#include "config.h"

#define MAX_LENGTH (50)

extern int currentCats;

enum Gender {UNKNOWN_GENDER, MALE, FEMALE};

enum Breed {UNKNOWN_BREED, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX};

enum Color {BLACK, WHITE, RED, BLUE, GREEN, PINK};

struct Cat {
    char                     name[MAX_LENGTH];
    enum               Gender gender;
    enum               Breed  breed;
    bool                      isFixed;
    float                     weight;
    enum               Color  collarColor1;
    enum               Color  collarColor2;
    unsigned long long        license;
};

extern struct Cat cats[MAX_CATS];

extern void initializeDatabase();