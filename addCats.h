///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.h
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <stdbool.h>
#include <stdio.h>

#include "catDatabase.h"
#include "config.h"

extern bool addCat(const char name[],
                   const enum Gender gender,
                   const enum Breed breed,
                   const bool isFixed,
                   const Weight weight,
                   const enum Color collarColor1,
                   const enum Color collarColor2,
                   const unsigned long long license);