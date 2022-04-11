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
#include <cstdlib>  // For EXIT_SUCCESS / EXIT_FAILURE
#include <cassert>  // For assert()
#include <cstring>  // For strcmp()
#include <exception>  // For try/catch blocks

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "config.h"
#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "updateCats.h"
#include "deleteCats.h"
#include "catValidation.h"
#include "Cat.h"

using namespace std;

#define MAX_NAME1    "1234567890123456789012345678901234567890123456789"
#define MAX_NAME2    "DIFFERENT 123456789012345678901234567890123456789"
#define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"

int main() {
    // RELEASE MAIN
    cout << "Starting " << PROGRAM_TITLE << endl;

    initializeDatabase();

    bool result; //result is true if add cat succeeds
    result = addCat( new Cat( "Loki",  MALE,   PERSIAN,    1.0 ));
    assert(result);
    if( !result ) {
        throw logic_error(PROGRAM_TITLE ": addCat() failed");
    }
    result = addCat( new Cat( "Milo",  MALE,   MANX,       1.1 )) ;
    assert(result);
    result = addCat( new Cat( "Bella", FEMALE, MAINE_COON, 1.2 )) ;
    assert(result);
    result = addCat( new Cat( "Kali",  FEMALE, SHORTHAIR,  1.3 )) ;
    assert(result);
    result = addCat( new Cat( "Trin",  FEMALE, MANX,       1.4 )) ;
    assert(result);
    result = addCat( new Cat( "Chili", MALE,   SHORTHAIR,  1.5 )) ;
    assert(result);

    printAllCats();

    deleteAllCats();

    printAllCats();
    // END RELEASE MAIN

    //DEBUG MAIN
    #ifdef DEBUG
        {
          // Verify that a cat's default values are set
          Cat testCat = Cat();
          assert(testCat.getName() != nullptr );
          assert(strcmp(testCat.getName(), "") == 0);
          assert(testCat.getGender() == UNKNOWN_GENDER);
          assert(testCat.getBreed() == UNKNOWN_BREED);
          assert(testCat.isCatFixed() == false);
          assert(testCat.getWeight() == UNKNOWN_WEIGHT);
          assert(!testCat.isCatFixed());
          assert(!testCat.validate());  // The default cat is invalid

          // Test for NULL name
          try {
             testCat.setName(nullptr);
             assert(false); // We should never get here
          } catch (exception const &e) {}

          // Test for empty name
          try {
             testCat.setName("");
             assert(false); // We should never get here
          } catch (exception const &e) {}

          // Test valid names
          testCat.setName("A");       // A 1 character name is valid
          testCat.setName(MAX_NAME1); // A MAX_NAME1 name is valid

          // Test for name too large
          try {
             testCat.setName(ILLEGAL_NAME);
             assert(false); // We should never get here
          } catch (exception const &e) {}

          testCat.setGender(FEMALE);

          try {
             testCat.setGender(MALE);
             assert(false); // We should never get here
          } catch (exception const &e) {}

          testCat.setBreed(MAINE_COON);

          try {
             testCat.setBreed(MANX);
             assert(false); // We should never get here
          } catch (exception const &e) {}

          testCat.fixCat();
          assert(testCat.isCatFixed());

          // Test for Weight <= 0
          try {
             testCat.setWeight(0);
             assert(false); // We should never get here
          } catch (exception const &e) {}

          testCat.setWeight(1.0 / 1024);
          assert(testCat.getWeight() == 1.0 / 1024);

          assert(testCat.validate());  // The cat should now be valid
          testCat.print() ;

          assert(!isCatInDatabase(&testCat)) ;
       }
    //#endif

    //#ifdef DEBUG
        {
          // Test finding a cat...
          Cat *bella = findCatByName("Bella");
          assert(bella != nullptr);
          // Test not finding a cat
          assert(findCatByName("Bella's not here") == nullptr);

          // Test deleting a cat...
          assert(deleteCat(bella) == true);
          try {
             deleteCat(bella); // Verify that Bella's not there
          } catch (exception const &e) {}

          bella = nullptr;
       }
    #endif
    // END DEBUG MAIN

    std::cout << "Done with " PROGRAM_TITLE << "\n" << std::endl;

    return( EXIT_SUCCESS ) ;
}
