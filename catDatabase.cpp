///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdexcept>  // For logic_error
#include <iostream>
#include <cassert>

#include "catDatabase.h"
#include "config.h"
#include "Cat.h"
#include "reportCats.h"

using namespace std;

NumCats currentCats = 0; /// Initialize number of cats

struct Cat cats[MAX_CATS];

/// The head pointer to a linked list of cats
Cat* catDatabaseHeadPointer = nullptr;

/// Initialize the cat database
extern void initializeDatabase() {
    if(catDatabaseHeadPointer != nullptr) {
        throw logic_error( PROGRAM_NAME ": Delete the old database first");
    }
    assert( validateDatabase());

    #ifdef DEBUG
        cout << PROGRAM_NAME << ": Database initialized" << endl ;
    #endif
}

