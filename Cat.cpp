///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   05_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <cstring>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cassert>

#include "Cat.h"
#include "config.h"
#include "reportCats.h"
#include "catDatabase.h"

using namespace std;

void Cat::zeroOutMemberData() {
    memset( name, 0, MAX_CAT_NAME);
    gender = UNKNOWN_GENDER; // note: the unknown values are set to 0
    breed = UNKNOWN_BREED;
    isFixed = false;
    weight = UNKNOWN_WEIGHT;
    next = nullptr;
}

//CONSTRUCTORS AND DESTRUCTORS
// constructor with no values, which means default values
Cat::Cat() {
    zeroOutMemberData();
}

// constructor with the bare minimum for a valid cat
Cat::Cat(const char *newName, const Gender newGender, const Breed newBreed, const Weight newWeight) : Cat() {
    setName( newName );
    setGender( newGender );
    setBreed( newBreed );
    setWeight( newWeight);
}

// destructor that will zero out data
Cat::~Cat() {
    zeroOutMemberData();
}

// GETTERS AND SETTERS
const char *Cat::getName() const noexcept {
    return name;
}

void Cat::getName(const char *newName) {
    memset( name, 0, MAX_CAT_NAME ); // zero out old name
    strcpy( name, newName ); // set new name
}
