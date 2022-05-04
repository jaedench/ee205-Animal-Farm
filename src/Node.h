///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file Node.h
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   19_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream> // For cout

#include "config.h"

/// A generic Node class.
///
/// May be used as a base class for a number of data
/// structures.

class Node {
    friend class List;
    friend class SinglyLinkedList;
    
protected: /////////////////// Protected Members //////////////
    Node* next = nullptr;
    ///< Point to the next Node in the list or `nullptr`
    ///< if it's the last Node in the list.

public: ///////////////////// Public Methods //////////////////
    virtual bool operator>( const Node& rightSide);
    /// Compare two nodes:  Is the left greater than the right?
    ///
    /// @param rightSide The `this` member is the left side of the `>` operator.
    ///                  `rightSide` is the right side of the `>` operator.
    /// @return `true` if `leftSide > rightSide`

    virtual void dump() const;
    /// Output the contents of this object
    ///
    /// #### Sample Output
    /// @code
    ///     ==============================================
    ///     Node    this                0x7ffeeaa7e580
    ///     Node    next                0
    /// @endcode
    ///

    virtual bool validate() const noexcept;
    /// Check the Node.
    ///
    /// This method checks the Node.  If something is not right,
    /// print out a message and stop the validation.  It will not throw an
    /// exception.
    ///
    /// @return True if the Node is healthy

protected: ///////////////// Static Methods ////////////////
    static bool compareByAddress( const Node* node1, const Node* node2 );
    /// A generic comparison based on the memory address of the object.
    ///
    /// Functions (like sorting) may want to compare two nodes.
    /// This is a good default comparison.  Other functions may choose to
    /// implement their own, more interesting, comparison functions and they can
    /// override the `>` operator.
    ///
    /// This allows us to separate the algorithm from the data.
    /// We can code an algorithm to operate on a virtual Node > operator and
    /// allow the descendants of Node to override `>` and implement their own
    /// ordering.
    ///
    /// @return true if `node1 > node2`
};