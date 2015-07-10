/*
 * A test harness for the simple linked list implementation
 * for the recipe project.
 *
 * Created by: Bran Amour Hagger
 */

#include <stdbool.h>
#include <iostream>

#include "../BranLinkedList.h"

// Generally, using the entire namespace is bad practice,
// but I want to make sure it doesn't break anything to say it.
using namespace butil;

bool createList( void ) {
   BranLinkedList lst;
   return lst.isEmpty();
}

bool pushOneElementList( void ) {
   BranLinkedList lst;
   
   int numOne = 1;
   lst.pushBack( &numOne );
   if ( lst.getSize() != 1 ) {
      std::cout << "size did not match number pushed" << std::endl;
      return false;
   }

   if ( *( ( int * ) lst.popBack() ) != 1 ) {
      std::cout << "pushed one, but did not pop" << std::endl;
      return false;
   }

   if ( lst.getSize() != 0 ) {
      std::cout << "should be empty, but non-zero size" << std::endl;
      return false;
   }

   if ( !lst.isEmpty() ) {
      std::cout << "should be empty, but isn't" << std::endl;
      return false;
   }

   return true;
}

// This method just calls the various tests above.
int main( int argv, char ** argc ) {
   if ( createList() ) {
      std::cout << "List created" << std::endl;
   }

   if ( pushOneElementList() ) {
      std::cout << "One element test passed" << std::endl;
   }
}
