///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file Node.cpp
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   19_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "Node.h"
#include "config.h"

bool Node::operator>(const Node &rightSide) {
    return false;
}

void Node::dump() const {
    PRINT_HEADING_FOR_DUMP;
    FORMAT_LINE_FOR_DUMP( "Node", "this") << this << std::endl;
    FORMAT_LINE_FOR_DUMP( "Node", "next" ) << next << std::endl;
}

bool Node::validate() const noexcept {
    if( next == nullptr ) {
        return true;  /// `nullptr` is a valid value for the next pointer.
    }
    /// @internal Perform a rudimentary recursive loop test and ensure
    ///           the next pointer does not refer back to itself.
    ///           This also has the benefit of dereferencing the
    ///           next pointer and ensuring it points to a valid address.
    if( next == next->next ) {
        std::cout << PROGRAM_NAME << ": Recursive loop detected:  next points to itself!" ;
    return false;
    }
    return true;
}


bool Node::compareByAddress(const Node* node1, const Node* node2) {
    if ( node1 > node2 ) {
        return true;
    }
    return false;
}
