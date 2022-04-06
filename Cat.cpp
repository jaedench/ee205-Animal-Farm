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
#include "reportCats.h"
#include "catDatabase.h"

using namespace std;

void Cat* zeroOutMemberData() {
    memset( name, 0, MAX_CAT_NAME);
    gender = UNKNOWN_GENDER;
    breed = UNKNOWN_BREED;
    isFixed = false;
    weight = UNKNOWN_WEIGHT;
    next = nullptr;
}

Cat::Cat() {
    zeroOutMemberData();
}

Cat::Cat(const char *newName, const Gender newGender, const Breed newBreed, const Weight newWeight) {
    setName( newName );
    setGender( newGender );
    setBreed( newBreed );
    setWeight( newWeight );
}

Cat::~Cat() {
    zeroOutMemberData();
}
