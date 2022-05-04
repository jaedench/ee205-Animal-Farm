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
#include "Animal.h"
#include "Breed.h"
#include "Cat.h"
#include "Color.h"
#include "Gender.h"
#include "List.h"
#include "Mammal.h"
#include "Node.h"
#include "SinglyLinkedList.h"
#include "Weight.h"

using namespace std;

#define MAX_NAME1    "1234567890123456789012345678901234567890123456789"
#define MAX_NAME2    "DIFFERENT 123456789012345678901234567890123456789"
#define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"

//#define DEBUG1

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
    //return( EXIT_SUCCESS ) ;


    //DEBUG MAIN
#ifdef DEBUG1
    // testing Color switch statement
    cout << Color::UNKNOWN_COLOR << endl;
    cout << Color::BLACK << endl;
    cout << Color::BROWN << endl;
    cout << Color::WHITE << endl;
    cout << Color::RED << endl;
    cout << Color::BLUE << endl;
    cout << Color::GREEN << endl;
    cout << Color::GINGER << endl;
    cout << Color::CREAM << endl;
    cout << Color::CINNAMON << endl;
    cout << Color::CALICO << endl;
    cout << Color::GINGER << endl;
    cout << Color::CREAM << endl;

    // testing Breed switch statement
    cout << Breed::UNKNOWN_BREED << endl;
    cout << Breed::MAINE_COON << endl;
    cout << Breed::MANX << endl;
    cout << Breed::SHORTHAIR << endl;
    cout << Breed::PERSIAN << endl;
    cout << Breed::SPHYNX << endl;

    Node testNodeA;
    testNodeA.dump();

    Node testNodeB;
    testNodeB.dump();

    // testing SinglyLinkedList functions
    SinglyLinkedList testList;
    assert(testList.validate());

    testList.push_front( &testNodeA );
    cout << "After push_front:" << endl;
    testList.dump();
    assert(testList.size() == 1);
    assert(testList.validate());

    testList.push_front( &testNodeB );
    cout << "After second push_front:" << endl;
    testList.dump();
    assert(testList.size() == 2);
    assert(testList.validate());

    testList.insert_after( &testNodeB, new Node);
    cout << "After insert_after:" << endl;
    testList.dump();
    assert(testList.size() == 3);
    assert(testList.validate());

    testList.pop_front();
    cout << "After first pop_front:" << endl;
    testList.dump();
    assert(testList.size() == 2);
    assert(testList.validate());

    testList.pop_front();
    cout << "After second pop_front:" << endl;
    testList.dump();
    assert(testList.size() == 1);
    assert(testList.validate());

    testList.pop_front();
    cout << "After third pop_front:" << endl;
    testList.dump();
    assert(testList.size() == 0);
    assert(testList.validate());
#endif
    // END DEBUG MAIN
}
