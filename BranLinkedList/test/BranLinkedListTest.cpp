/*
 * A test harness for the simple linked list implementation
 * for the recipe project.
 */

#include <stdbool.h>
#include <iostream>

#include "../BranLinkedList.h"

// Generally, using the entire namespace is bad practice,
// but I want to make sure it doesn't break anything to say it.
using namespace butil;

void createList( void ) {
   BranLinkedList lst();
   std::cout << "List created" << std::endl;
}

// This method just calls the various tests above.
int main( int argv, char ** argc ) {
   createList();
}
