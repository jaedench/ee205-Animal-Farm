///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file Breed.h
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <string>

#include "config.h"

enum class Breed {
    UNKNOWN_BREED=0,
    MAINE_COON,
    MANX,
    SHORTHAIR,
    PERSIAN,
    SPHYNX
};

/// Output Breed as a formatted string
///
/// @param lhs_stream The output stream to write to (usually `cout`). `lhs` stands for Left Hand Side and means the left side of the `<<` operator.
///
/// @param rhs_Breed The Breed to output. `rhs` stands for Right Hand Side and means the right side of the `<<` operator.
///
/// @return `Unknown breed`, `Maine Coon`, `Manx`, `Shorthair`, `Persian`, or `Sphynx`.
inline std::ostream& operator<<( std::ostream& lhs_stream, const Breed& rhs_Breed ) {
    switch (rhs_Breed) {
        case Breed::UNKNOWN_BREED:
            lhs_stream << "Unknown breed";
            break;
        case Breed::MAINE_COON:
            lhs_stream << "Maine Coon";
            break;
        case Breed::MANX:
            lhs_stream << "Manx";
            break;
        case Breed::SHORTHAIR:
            lhs_stream << "Shorthair";
            break;
        case Breed::PERSIAN:
            lhs_stream << "Persian";
            break;
        case Breed::SPHYNX:
            lhs_stream << "Sphynx";
            break;
        default:
            /// @throw out_of_range If the enum is not mapped to a string.
            throw std::out_of_range(PROGRAM_TITLE ": Gender not mapped to a string");
    }
    return lhs_stream;
}
