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

#include <stdexcept>  // For logic_error
#include <iostream>
#include <cassert>

#include "config.h"
#include "Cat.h"

#define MAX_LENGTH (50)

extern NumCats currentCats;

/// The head pointer to a linked list of cats
extern Cat* catDatabaseHeadPointer;

extern void initializeDatabase();

extern bool isCatInDatabase( const Cat* aCat );

extern bool validateDatabase();

