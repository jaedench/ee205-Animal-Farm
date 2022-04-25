///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file Animal.cpp
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cassert>
#include <stdexcept>
#include <iomanip>

#include "config.h"
#include "Animal.h"
#include "Gender.h"
#include "Weight.h"

///////////// Constants /////////////////
const std::string Animal::KINGDOM_NAME = "Animalia";

/////////////// Constructors ///////////////////
// Minimum fields.
Animal::Animal(const Weight::t_weight newMaxWeight, const std::string &newClassification,
               const std::string &newSpecies) {
    weight.setMaxWeight(newMaxWeight);
    classification = newClassification;
    species = newSpecies;
}

// All fields.
Animal::Animal(const Gender newGender, const Weight::t_weight newWeight, const Weight::t_weight newMaxWeight,
               const std::string &newClassification, const std::string &newSpecies) {
    setGender(newGender);
    weight.setWeight(newWeight);
    weight.setMaxWeight(newMaxWeight);
    classification = newClassification;
    species = newSpecies;
}

///////////////////// Getters and Setters /////////////////////
// Getters.
std::string Animal::getKingdom() const noexcept {
    return KINGDOM_NAME;
}

std::string Animal::getClassification() const noexcept {
    return classification;
}

std::string Animal::getSpecies() const noexcept {
    return species;
}

Gender Animal::getGender() const noexcept {
    return gender;
}

Weight::t_weight Animal::getWeight() const noexcept {
    return weight.getWeight();
}

// Setters.
void Animal::setWeight(const Weight::t_weight newWeight) {
    weight.setWeight(newWeight);
}

/////////////////// Static Public Methods ////////////////////
bool Animal::validateClassification(const std::string &checkClassification) noexcept {
    // Classification cannot be empty
    if( checkClassification.empty()) {
        return false;
        // std::cout << PROGRAM_NAME << ": Classification cannot be empty." << std::endl;
    }
#ifdef DEBUG
    // compare strings using animal classes
    if( checkClassification.compare("Mammalian")==0) {
        return true;
    }
    if( checkClassification.compare("Vermes")==0) {
        return true;
    }
    if( checkClassification.compare("Insecta")==0) {
        return true;
    }
    if( checkClassification.compare("Pisces")==0) {
        return true;
    }
    if( checkClassification.compare("Amphibians")==0) {
        return true;
    }
    if( checkClassification.compare("Aves")==0) {
        return true;
    }
    if( checkClassification.compare("Agnatha")==0) {
        return true;
    }
    if( checkClassification.compare("Chrondrichtyes")==0) {
        return true;
    }
    if( checkClassification.compare("Osteichthyes")==0) {
        return true;
    }
    if( checkClassification.compare("Reptilia")==0) {
        return true;
    }
    std::cout << checkClassification << "is not an animal class." << std::endl;
#endif
    return true;
}

bool Animal::validateSpecies(const std::string &checkSpecies) noexcept {
    // Species cannot be empty
    if( checkSpecies.empty()) {
        return false;
        //std::cout << PROGRAM_NAME << ": Species cannot be empty." << std::endl;
    }
    return true;
}

/////////////// Protected Methods /////////////////////
// Setters.
void Animal::setGender(const Gender newGender) {
    if( gender != Gender::UNKNOWN_GENDER ) {
        throw std::logic_error(PROGRAM_NAME ": The gender is already set and cannot be changed.");
    }
    Animal::gender = newGender;
}

///////////////////// Methods ////////////////////////
// dump
void Animal::dump() const noexcept {
    Node::dump();
    FORMAT_LINE_FOR_DUMP( "Animal", "this" )           << this                << std::endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "kingdom" )        << getKingdom()        << std::endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "classification" ) << getClassification() << std::endl;
    FORMAT_LINE_FOR_DUMP( "Animal", "species" )        << getSpecies()        << std::endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "gender" )         << getGender()         << std::endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "weight" )         << getWeight() << " out of " << weight.getMaxWeight() << weight.getWeightUnit() << std::endl;
    FORMAT_LINE_FOR_DUMP( "Animal", "species" )        << getSpecies()        << std::endl ;
}

// validate
bool Animal::validate() const noexcept {
    if( !validateClassification( getClassification())) {
        return false;
    }
    if( !validateSpecies( getSpecies() )) {
        return false;
    }
    if(KINGDOM_NAME.compare("Animalia")!=0) {
        return false;
    }
    if( !weight.isWeightValid(getWeight()) ) {
        return false;
    }
    if(!Node::validate()) {
        return false;
    }
    return true;
}
