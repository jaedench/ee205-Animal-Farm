///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.h
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "config.h"
#include "Cat.h"
#include "catDatabase.h"
#include "reportCats.h"

extern bool printAllCats();

extern Cat* findCatByName( const char* name );

//extern const char* colorName(const enum Color color);

//extern const char* genderName(const enum Gender gender);

extern const char* breedName(const enum Breed breed);