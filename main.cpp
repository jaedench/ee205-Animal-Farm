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
#include "Cat.h"
#include "SinglyLinkedList.h"

using namespace std;

#define MAX_NAME1    "1234567890123456789012345678901234567890123456789"
#define MAX_NAME2    "DIFFERENT 123456789012345678901234567890123456789"
#define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"

// #define DEBUG

int main() {
    cout << "Starting " << PROGRAM_TITLE << endl ;
    SinglyLinkedList catDB ;
    catDB.push_front( new Cat( "Loki", Color::CREAM, true, Gender::MALE, 1.0 ) ) ;
    catDB.push_front( new Cat( "Milo", Color::BLACK, true, Gender::MALE, 1.1 ) ) ;
    catDB.push_front( new Cat( "Bella", Color::BROWN, true, Gender::FEMALE, 1.2 ) ) ;
    catDB.push_front( new Cat( "Kali", Color::CALICO, true, Gender::FEMALE, 1.3 ) ) ;
    catDB.push_front( new Cat( "Trin", Color::WHITE, true, Gender::FEMALE, 1.4 ) ) ;
    catDB.insert_after(catDB.get_first(), new Cat( "Chili", Color::GINGER, true,
                                                   Gender::MALE, 1.5 ) );
    for( Animal* pAnimal = (Animal*)catDB.get_first() ; pAnimal != nullptr ; pAnimal =
                                                                                     (Animal*)List::get_next( (Node*)pAnimal ) ) {
        cout << pAnimal->speak() << endl;
    }
    catDB.validate() ;
    catDB.dump() ;
    catDB.deleteAllNodes() ;
    catDB.dump() ;
    cout << "Done with " << PROGRAM_TITLE ;
    return( EXIT_SUCCESS ) ;


    //DEBUG MAIN
    #ifdef DEBUG
    {
        // Verify that a cat's default values are set
        Cat testCat = Cat();
        assert(testCat.getName() != nullptr);
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
    #endif

    #ifdef DEBUG
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
}
