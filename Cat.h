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

#include <string>

#include "config.h"
#include "Gender.h"
#include "Mammal.h"

/// Felis Catus
///
/// There's no `setGender()` and `setBreed()` methods.  Under normal
/// circumstances, they would be passed in the constructor and never changed
/// afterwards.
///
/// In the real world, it's impossible to change the breed of a cat, however,
/// in actual databases, there are times when a breed is mis-entered and
/// needs to be corrected.


class Cat : public Mammal {
public: ///////////// Constants //////////////////
    static const std::string SPECIES_NAME;
    static const Weight::t_weight MAX_WEIGHT;

protected:  ///////////////////////// Member Variables /////////////////////////
    std::string name ;        ///< The name of the cat
    bool isFixed ;            ///< `true` if the cat is fixed/neutered

public:  //////////////////////////// Constructors /////////////////////////////
    /// Create a Cat with the minimum fields necessary to have a valid Cat
    /// Why can't this be defined in the .cpp file??
    explicit Cat( const std::string& newName ) : Mammal( MAX_WEIGHT, SPECIES_NAME ) {
        if( !validateName( newName) ) {
            /// @throws out_of_range If the Cat doesn't have a name
            throw std::out_of_range( "Cats must have a name" );
        }
        name = newName;
        isFixed = false;

        Cat::validate();
    }

    /// Create a Cat, populating *all* of the member variables
    Cat( const std::string&         newName
            ,const Color            newColor
            ,const bool             newIsFixed
            ,const Gender           newGender
            ,const Weight::t_weight newWeight
    ) : Mammal( newColor, newGender, newWeight, MAX_WEIGHT, SPECIES_NAME ) {
        if( !validateName( newName) ) {
            /// @throws out_of_range If the Cat doesn't have a name
            throw std::out_of_range( "Cats must have a name" );
        }
        name = newName;
        isFixed = newIsFixed;

        Cat::validate();
    }

public:  ////////////////////////// Getters & Setters //////////////////////////
    std::string getName() const noexcept ;        ///< Get the Cat's name
    void setName( const std::string& newName );   ///< Set the Cat's name.  The name must not be empty.

    bool isCatFixed() const noexcept ;      ///< Return `true` if the cat is fixed/neutered
    void fixCat() noexcept ;                ///< Spay or neuter the cat

public:  /////////////////////////// Public Methods ////////////////////////////
    std::string speak() const noexcept override;  ///< Say `Meow`.
    void dump() const noexcept override;          ///< Print the contents of this object (and its parents)
    bool validate() const noexcept override;      ///< Check to see if the Cat object is valid

public:  /////////////////////// Static Public Methods /////////////////////////
    // Static methods are `const` by default
    static bool validateName( const std::string& newName ) ;  ///< Check if `newName` is valid
};



// ========================================= Old Code ===============================================
/*
private:  ///////////////////////// Member Variables /////////////////////////
char name[MAX_CAT_NAME];  ///< Cat's name
//enum Gender gender;              ///< Cat's gender
//enum Breed breed;               ///< Cat's breed
bool isFixed;            ///< If the cat is fixed, return true
t_weight weight;              ///< Cat's weight: Must be greater than 0 or -1 if unknown.

public:  /////////////////////// Public Member Variables ///////////////////////
Cat *next;                ///< The next pointer for a linked list

private:  /////////////////////////// Private Methods //////////////////////////
void zeroOutMemberData();         ///< Make all member data zero

public:  //////////////////////////// Constructors /////////////////////////////
Cat();     ///< Create a cat with all default values.

/// Create a cat with the minimum fields necessary to have a valid cat
Cat(const char *newName, const Gender newGender, const Breed newBreed, const t_weight newWeight);

/// Zero out all of the member data
virtual ~Cat();

public:  ////////////////////////// Getters & Setters //////////////////////////
const char *getName() const noexcept; ///< Get Cat's name
void getName(const char *newName);
void setName(const char *newName );   ///< Set Cat's name. Name length must be greater than 0 and it must
///< be less than or equal to the MAX_CAT_NAME.

Gender getGender() const noexcept;  ///< Get Cat's gender
Breed getBreed() const noexcept;    ///< Get Cat's breed
bool isCatFixed() const noexcept;      ///< If the cat is fixed, return true
void fixCat() noexcept;             ///< Spay or neuter the cat
t_weight getWeight() const noexcept;  ///< Cat's weight: Must be greater than 0 or -1 if unknown
void setWeight(t_weight newWeight);   ///< Set newWeight of the cat


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
static bool validateWeight(const t_weight newWeight); ///< Check if `newWeight` is valid
 */
