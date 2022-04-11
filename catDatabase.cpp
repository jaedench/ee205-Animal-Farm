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

/// The head pointer to a linked list of cats
Cat* catDatabaseHeadPointer = nullptr;

/// Initialize the cat database
void initializeDatabase() {
    if(catDatabaseHeadPointer != nullptr) {
        throw logic_error( PROGRAM_TITLE ": Delete the old database first");
    }
    assert( validateDatabase() );

#ifdef DEBUG
    cout << PROGRAM_TITLE << ": Database initialized" << endl ;
#endif
}

bool isCatInDatabase( const Cat* aCat ) {
    assert( aCat != nullptr );

    assert( validateDatabase() ); // validate database before and after

    for(Cat* iCat = catDatabaseHeadPointer ; iCat != nullptr ; iCat = iCat->next ) {
        if( iCat == aCat ) {
            return true ;
        }
    }

    assert( validateDatabase() ) ;

    return false ;  // The cat wasn't found
}

/// Database is valid = silent
/// Database is not valid = print a message as to why and return false.
/// It should not throw an exception.

bool validateDatabase() {
    int validCats = 0 ;

    for(Cat* iCat = catDatabaseHeadPointer ; iCat != nullptr ; iCat = iCat->next ) {
        if( !iCat->validate() ) {
            return false ;
        }

        Cat* foundCat = findCatByName( iCat->getName() ) ;

        if( foundCat != iCat ) {
            cout << PROGRAM_TITLE ": Warning: Duplicate cat name [" << iCat->getName() << "]" << endl ;
        }

        validCats++ ;
    }

    if( validCats != currentCats ) {
        cout << PROGRAM_TITLE << ": Error: currentCats [" << currentCats
             << "] does not equal [" << validCats << "]" << endl ;
        return false ;
    }

#ifdef DEBUG
    cout << PROGRAM_TITLE << ": Valid database" << endl ;
#endif
    return true ;  // healthy database
}
