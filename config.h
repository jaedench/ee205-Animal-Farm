///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file config.h
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include <limits.h>

#define PROGRAM_TITLE "Animal Farm 3"

#define MAX_CATS (1024)

typedef float Weight;

enum Gender {UNKNOWN_GENDER, MALE, FEMALE};

enum Breed {UNKNOWN_BREED, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX};

enum Color {BLACK, WHITE, RED, BLUE, GREEN, PINK};

const Weight UNKNOWN_WEIGHT = -1 ;