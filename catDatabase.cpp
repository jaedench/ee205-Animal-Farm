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
/*
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
void initializeDatabase() {
    if(catDatabaseHeadPointer != nullptr) {
        throw logic_error( PROGRAM_NAME ": Delete the old database first");
    }
    assert( validateDatabase());

    #ifdef DEBUG
        cout << PROGRAM_NAME << ": Database initialized" << endl ;
    #endif
}

bool isCatInDatabase( const Cat* aCat ) {
    assert( aCat != nullptr );

    assert( validateDatabase() );

    for(Cat* iCat = catDatabaseHeadPointer ; iCat != nullptr ; iCat = iCat->next ) {
        if( iCat == aCat ) {
            return true ;
        }
    }

    assert( validateDatabase() ) ;

    return false ;  // The cat wasn't found
}

/// If the database is valid, this should be silent.  If the database is not
/// valid, it should print a message as to why and then return false.  It
/// should not throw an exception.
///

bool validateDatabase() {
    int validCats = 0 ;

    for(Cat* iCat = catDatabaseHeadPointer ; iCat != nullptr ; iCat = iCat->next ) {
        if( !iCat->validate() ) {
            return false ;
        }

        Cat* foundCat = findCatByName( iCat->getName() ) ;
        if( foundCat != iCat ) {
            cout << PROGRAM_NAME ": Warning:  Found a duplicate cat name [" << iCat->getName() << "]" << endl ;
        }

        validCats++ ;
    }

    if( validCats != numberOfCats ) {
        cout << PROGRAM_NAME << ": Error:  numberOfCats [" << numberOfCats
             << "] does not equal [" << validCats << "]" << endl ;
        return false ;
    }

#ifdef DEBUG
    cout << PROGRAM_NAME << ": The database is valid." << endl ;
#endif

    return true ;  // The database is healthy
}
*/