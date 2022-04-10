///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catValidation.cpp
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "config.h"
#include "catDatabase.h"
#include "catValidation.h"


bool nameExists( const int index, const char checkName[] ) {
    if((strcmp(checkName, cats[index].name) == 0 )) {
        fprintf(stderr, "%s: Name of cat already exists!\n",PROGRAM_TITLE);
        return false;
    }
    else {
        return true;
    }
}


bool nameEmpty( const int index ) {
    if( cats[index].name[0] == '\0') {
        return false;
    }
    else {
        return true;
    }
}


bool isValidIndex( const int index ) {
    if( index < 0) {
        fprintf(stderr, "%s: Index must be greater than or equal to zero.\n", PROGRAM_TITLE);
        return false;
    }
    else if( index > MAX_CATS ) {
        fprintf(stderr, "%s: Index must be less than or equal to %d.\n", PROGRAM_TITLE, MAX_CATS);
        return false;
    }
    else {
        return true;
    }
}


bool isValidName( const char checkName[] ) {
    if( strlen(checkName) == 0 ) {
        fprintf(stderr, "%s: No cat name detected! Cat's name must be longer than 0 characters.\n", PROGRAM_TITLE);
        return false;
    }
    else if( strlen(checkName) > MAX_LENGTH ) {
        fprintf(stderr, "%s: Cat name too long! Name must be %d characters or less.\n", PROGRAM_TITLE, MAX_LENGTH);
        return false;
    }
    else {
        return true;
    }
}


bool isValidWeight( const Weight checkWeight ) {
    if (checkWeight <= 0) {
        fprintf(stderr, "%s: No cat detected! Weight must be greater than 0.\n", PROGRAM_TITLE);
        return false;
    }
    return true;
}
