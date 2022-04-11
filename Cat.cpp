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

#include "config.h"
#include "reportCats.h"
#include "catDatabase.h"
#include "Cat.h"

#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52);

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
//Name
const char *Cat::getName() const noexcept {
    return name;
}

void Cat::getName(const char* newName) {
    memset( name, 0, MAX_CAT_NAME ); // zero out old name
    strcpy( name, newName ); // set new name
}

//Gender
Gender Cat::getGender() const noexcept{
    return gender;
}

void Cat::setGender(Gender newGender) {
    if( gender != UNKNOWN_GENDER ) {
        throw logic_error( PROGRAM_TITLE ": The cat's gender is already set. You can't change it!");
    }
    Cat::gender = newGender;
}

//Breed
Breed Cat::getBreed() const noexcept {
    return breed;
}

void Cat::setBreed(Breed newBreed) {
    if( breed != UNKNOWN_BREED ) {
        throw logic_error(PROGRAM_TITLE ": The cat's breed is already set. You can't change it!");
    }
    Cat::breed = newBreed;
}

//Fixed
bool Cat::isCatFixed() const noexcept {
    return isFixed;
}

void Cat::isCatFixed() const noexcept {
    Cat::isFixed = true;
}

//Weight
Weight Cat::getWeight() const noexcept {
    return weight;
}

void Cat::setWeight(Weight newWeight) {
    Cat::weight = newWeight;
}

//VALIDATION
bool Cat::validateName(const char *newName) {
    if( newName == nullptr ) {
        throw invalid_argument( PROGRAM_TITLE ": name cannot be NULL");
    }

    if( strlen( newName)  <= 0 ) {
        throw length_error(PROGRAM_TITLE ": name must be greater than 0 charactes in length");
    }

    if( strlen( newName )>= MAX_CAT_NAME ) {
        throw length_error( PROGRAM_TITLE ": name must be less than MAX_CAT_NAME.");
    }

    return true;
}

bool Cat::validateGender(const Gender newGender) {
    if( newGender == UNKNOWN_GENDER ) {
        throw invalid_argument(PROGRAM_TITLE ": The cat's gender must be known.");
    }

    return true;
}

bool Cat::validateBreed(const Breed newBreed) {
    if( newBreed == UNKNOWN_BREED ) {
        throw invalid_argument( PROGRAM_TITLE ": The cat's breed must be known.");
    }

    return true;
}

bool Cat::validateWeight(const Weight newWeight) {
    if( newWeight <= 0 ) {
        throw invalid_argument( PROGRAM_TITLE ": The cat's weight must be greater than 0.");
    }

    return true;
}



//Validating a cat using a try and catch block
bool Cat::validate() const noexcept{ //won't throw exceptions
    try {
        validateName( name ) ;
        validateGender( gender ) ;
        validateBreed( breed ) ;
        validateWeight( weight ) ;
    } catch (exception const& e) {
        cout << e.what() << endl ;
        return false ;
    }
    return true;
}


//PRINT

bool Cat::print() const noexcept {
    assert( validate() ) ;
    cout  << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Cat", "name" )    << getName()                 << endl ;
    FORMAT_LINE( "Cat", "gender" )  << genderName( getGender() ) << endl ;
    FORMAT_LINE( "Cat", "breed" )   << breedName( getBreed() )   << endl ;
    FORMAT_LINE( "Cat", "isFixed" ) << isCatFixed()              << endl ;
    FORMAT_LINE( "Cat", "weight" )  << getWeight()               << endl ;

    return true ;
}

