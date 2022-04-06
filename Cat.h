///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   31_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "config.h"
#include "catDatabase.h"

/// Felis Catus
///
/// There's no `setGender()` and `setBreed()` methods.  Under normal
/// circumstances, they would be passed in the constructor and never changed
/// afterwards.
///
/// In the real world, it's impossible to change the breed of a cat, however,
/// in actual databases, there are times when a breed is mis-entered and
/// needs to be corrected.

/// The maximum size of a cat's name
#define MAX_CAT_NAME (50)
