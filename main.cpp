///////////////////////////////////////////////////////////////////////////////
///        University of Hawaii, College of Engineering
/// @brief Lab 07d - Animal Farm 1 - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   01_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include <stdio.h>
#include <stdlib.h> //For EXIT_SUCCESS / EXIT_FAILURE
#include <assert.h> //For assert()
#include <stdbool.h>
#include <string.h>

#include "config.h"
#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "updateCats.h"
#include "deleteCats.h"
#include "catValidation.h"


#define MAX_NAME1    "1234567890123456789012345678901234567890123456789"
#define MAX_NAME2    "DIFFERENT 123456789012345678901234567890123456789"
#define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"

int main() {
    std::cout << "Starting " << PROGRAM_TITLE << "\n" << std::endl;


    //initializeDatabase();

    addCat( "Loki",  MALE,           PERSIAN,    true,   8.5, BLACK, WHITE, 101 ) ;
    addCat( "Milo",  MALE,           MANX,       true,   7.0, BLACK, RED,   102 ) ;
    addCat( "Bella", FEMALE,         MAINE_COON, true,  18.2, BLACK, BLUE,  103 ) ;
    addCat( "Kali",  FEMALE,         SHORTHAIR,  false,  9.2, BLACK, GREEN, 104 ) ;
    addCat( "Trin",  FEMALE,         MANX,       true,  12.2, BLACK, PINK,  105 ) ;
    addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR,  false, 19.0, WHITE, BLACK, 106 ) ;

#ifdef DEBUG
    // Test for empty name
   assert( addCat( "", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, BLACK, WHITE, 101 ) == BAD_CAT ) ;
   // Test for max name
   assert( addCat( MAX_NAME1, UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, RED, 107 ) != BAD_CAT ) ;
   // Test for name too long
   assert( addCat( ILLEGAL_NAME, UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLUE, 108 ) == BAD_CAT ) ;
   // Test for duplicate cat name
   assert( addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR, false, 0, WHITE, GREEN, 109 ) == BAD_CAT ) ;
   // Test for weight <= 0
   assert( addCat( "Neo", UNKNOWN_GENDER, SHORTHAIR, false, 0, WHITE, PINK, 110 ) == BAD_CAT ) ;
   // Test for printCat( -1 ) ;
   printCat( -1 ) ;
   // Test for out of bounds
   printCat( 2000 ) ;
   // Test finding a cat...
   assert( findCat( "Bella" ) == 2 ) ;
   // Test not finding a cat
   assert( findCat( "Bella's not here" ) == BAD_CAT ) ;
   // Test addCat details
   size_t testCat = addCat( "Oscar", UNKNOWN_GENDER, SHORTHAIR, false, 1.1, RED, BLACK, 111 ) ;
   assert( testCat != BAD_CAT );
   assert( testCat < MAX_CATS );
   // Test setting a large name
   assert( updateCatName( testCat, MAX_NAME2 ) == true ) ;
   printCat( testCat ) ;
   // Test setting an out-of-bounds name
   assert( updateCatName( testCat, ILLEGAL_NAME ) == false ) ;
   printCat( testCat ) ;
   // Test setting an illegal cat weight
   assert( updateCatWeight( testCat, -1 ) == false ) ;
#endif


    printAllCats();

    int kali = findCat( "Kali" ) ;
    assert( updateCatName( kali, "Chili" ) == false ) ; // duplicate cat name should fail
    printCat( kali ) ;
    assert( updateCatName( kali, "Capulet" ) == true ) ;
    assert( updateCatWeight( kali, 9.9 ) == true ) ;
    assert( fixCat( kali ) == true ) ;
    assert( updateCatCollar1( kali, GREEN ) == true ) ;
    assert( updateCatCollar2( kali, GREEN ) == true ) ;
    assert( updateLicense( kali, 201 ) == true ) ;


    printCat( kali ) ;

    printAllCats() ;

    deleteAllCats() ;
    printAllCats() ;


    std::cout << "Done with " PROGRAM_TITLE << "\n" << std::endl;

    return( EXIT_SUCCESS ) ;
}
