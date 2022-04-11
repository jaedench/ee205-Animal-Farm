///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "catDatabase.h"
#include "deleteCats.h"
#include "config.h"

using namespace std;

bool deleteCat( Cat* deletingCat ) {
    assert( deletingCat != nullptr);

    assert( validateDatabase() ); // validate database before and after

    // special case: deleting first cat
    if( deletingCat == catDatabaseHeadPointer) {
        catDatabaseHeadPointer = catDatabaseHeadPointer->next;
        delete deletingCat; // deletes first cat
        currentCats--;

        assert(validateDatabase());

#ifdef DEBUG
        cout << "deleted cat" << endl;
#endif

        return true;
    }

    //special case: deleting a cat somewhere in the list
    Cat* iCat = catDatabaseHeadPointer;
    while( iCat != nullptr ) {
        if( iCat->next == deletingCat ) {
            iCat->next = deletingCat->next;
            delete deletingCat;
            currentCats--;

            assert(validateDatabase());
#ifdef DEBUG
            cout << "deleted cat" << endl;
#endif
        }
        iCat = iCat->next;
    }

    assert(validateDatabase());

    throw invalid_argument( PROGRAM_TITLE ": Unable to delete cat.");
}

bool deleteAllCats() {
    while(catDatabaseHeadPointer != nullptr ) {     //this will keep iterating through the list until the end
        deleteCat(catDatabaseHeadPointer);
    }
#ifdef DEBUG
    cout << "All cats deleted" << endl;
#endif

    currentCats = 0;
    return true;
}