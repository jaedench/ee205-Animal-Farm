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

bool deleteAllCats() {
    memset(cats, 0, sizeof(cats));
    currentCats = 0;
    std::cout << "Deleted all cats\n" << std::endl;

    return true;
}