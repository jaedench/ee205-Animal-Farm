///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   05_Apr_2022
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

class Cat {
private:  ///////////////////////// Member Variables /////////////////////////
    char name[MAX_CAT_NAME];  ///< Cat's name
    enum Gender gender;              ///< Cat's gender
    enum Breed breed;               ///< Cat's breed
    bool isFixed;            ///< If the cat is fixed, return true
    Weight weight;              ///< Cat's weight: Must be greater than 0 or -1 if unknown.

public:  /////////////////////// Public Member Variables ///////////////////////
    Cat *next;                ///< The next pointer for a linked list

private:  /////////////////////////// Private Methods //////////////////////////
    void zeroOutMemberData();         ///< Make all member data zero

public:  //////////////////////////// Constructors /////////////////////////////
    Cat();     ///< Create a cat with all default values.

    /// Create a cat with the minimum fields necessary to have a valid cat
    Cat(const char *newName, const Gender newGender, const Breed newBreed, const Weight newWeight);

    /// Zero out all of the member data
    virtual ~Cat();

public:  ////////////////////////// Getters & Setters //////////////////////////
    const char *getName() const noexcept; ///< Get Cat's name
    void setName(const char *newName);   ///< Set Cat's name. Name length must be greater than 0 and it must
    ///< be less than or equal to the MAX_CAT_NAME.

    Gender getGender() const noexcept;  ///< Get Cat's gender
    Breed getBreed() const noexcept;    ///< Get Cat's breed
    bool isCatFixed() const noexcept;      ///< If the cat is fixed, return true
    void fixCat() noexcept;             ///< Spay or neuter the cat
    Weight getWeight() const noexcept;  ///< Cat's weight: Must be greater than 0 or -1 if unknown
    void setWeight(Weight newWeight);   ///< Set newWeight of the cat


protected:  ////////////////////// Protected Methods ///////////////////////////
public:
    void setGender(Gender newGender);  ///< Set cat's gender
    void setBreed(Breed newBreed);  ///< Set cat's breed

public:  /////////////////////////// Public Methods ////////////////////////////
    bool print() const noexcept;    ///< Print a cat
    bool validate() const noexcept;  ///< Check to see if the Cat object is valid

public:  /////////////////////// Static Public Methods /////////////////////////
    // Static methods must be `const`
    static bool validateName(const char *newName);  ///< Check if `newName` is valid
    static bool validateGender(const Gender newGender); ///< Check if `newGender` is valid
    static bool validateBreed(const Breed newBreed); ///< Check if 'newBreed` is valid
    static bool validateWeight(const Weight newWeight); ///< Check if `newWeight` is valid
};