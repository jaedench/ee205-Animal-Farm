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

#include <iostream>
#include <cassert>

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "addCats.h"
#include "catDatabase.h"
#include "config.h"
#include "catValidation.h"
#include "Cat.h"

//#define DEBUG

using namespace std;

bool addCat(Cat* newCat) {
    assert(newCat != nullptr);

    if (!newCat->validate()) {
        throw invalid_argument(PROGRAM_TITLE ": that's a bad cat!");
    }

    assert(validateDatabase()); //validate database before and after addign cat

    // adding the cat after everything is validated
    newCat->next = catDatabaseHeadPointer;
    catDatabaseHeadPointer = newCat;
    currentCats++;

    assert(validateDatabase());

#ifdef DEBUG
    cout << "Cat added" << endl;
#endif

    return true;
}