///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file Mammal.cpp
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <iomanip>
#include <iostream>

#include "config.h"
#include "Color.h"
#include "Mammal.h"

const std::string Mammal::MAMMAL_NAME = "Mammalia";

void Mammal::dump() const noexcept {
    Animal::dump();
    FORMAT_LINE_FOR_DUMP( "Mammal", "color") << getColor() << std::endl;
}