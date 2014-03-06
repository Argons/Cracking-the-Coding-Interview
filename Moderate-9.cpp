#include <iostream>
using namespace std;

// Since XML is very verbose, you are given a way of encoding it where each tag 
// gets mapped to a pre-defined integer value. 
// The language/grammar is as follows:
// Element --> Element Attr* END Element END [aka, encode the element tag, then
//             its attributes, then tack on an END character, then encode its 
//             children, then another end tag]
// Attr  --> Tag Value [assume all values are strings]
// END   --> 01
// Tag   --> some predefined mapping to int
// Value --> string value END
// Write code to print the encoded version of an xml element.

// FOLLOW UP
// Is there anything else you could do to compress this even further?



int main() {
    
    return 0;
}
