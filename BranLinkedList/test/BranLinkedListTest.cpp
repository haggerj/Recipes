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

bool pushMultipleElementsList(void) {
   BranLinkedList lst;

   unsigned arr [] = { 1, 2, 3, 4, 5 };

   if ( !lst.isEmpty() ) {
      std::cout << "list should be empty to start" << std::endl;
      return false;
   }

   for ( unsigned i = 0; i < 5; ++i ) {
      lst.pushBack( &arr[i] );
      if ( lst.getSize() != i + 1 ) {
         std::cout << "size not incremented properly" << std::endl;
         return false;
      }
   }

   for ( unsigned i = 0; i < 5; ++i ) {
      unsigned * val = (unsigned *)lst.popFront();
      if ( *val != i+1 ) {
         std::cout << "did not pop correct value" << std::endl;
         return false;
      }

      if ( lst.getSize() != 4 - i ) {
         std::cout << "size not decremented properly" << std::endl;
         return false;
      }
   }

   return true;
}

bool pushFrontMultipleElementsList(void) {
   BranLinkedList lst;

   unsigned arr [] = { 1, 2, 3, 4, 5 };

   if ( !lst.isEmpty() ) {
      std::cout << "list should be empty to start" << std::endl;
      return false;
   }

   for ( unsigned i = 0; i < 5; ++i ) {
      lst.pushFront( &arr[i] );
      if ( lst.getSize() != i + 1 ) {
         std::cout << "size not incremented properly" << std::endl;
         return false;
      }
   }

   for ( unsigned i = 0; i < 5; ++i ) {
      unsigned * val = (unsigned *)lst.popBack();
      if ( *val != i+1 ) {
         std::cout << "did not pop correct value" << std::endl;
         return false;
      }

      if ( lst.getSize() != 4 - i ) {
         std::cout << "size not decremented properly" << std::endl;
         return false;
      }
   }

   return true;
}

bool peekBackTest( void ) {
   int one = 1;
   int two = 2;

   BranLinkedList lst;
   lst.pushBack( &one );
   lst.pushBack( &two );

   int * val = (int *)lst.peekBack();
   if ( *val != 2 ) {
      std::cout << "Peek returned front element instead of back" << std::endl;
      return false;
   }

   if ( lst.getSize() != 2 ) {
      std::cout << "peek accidentally decremented size" << std::endl;
      return false;
   }

   val = (int *)lst.popBack();
   if ( *val != 2 ) {
      std::cout << "element popped after peek does not match" << std::endl;
      return false;
   }

   return true;
}

bool peekFrontTest( void ) {
   int one = 1;
   int two = 2;

   BranLinkedList lst;
   lst.pushFront( &one );
   lst.pushFront( &two );

   int * val = (int *)lst.peekFront();
   if ( *val != 2 ) {
      std::cout << "peek returned back element instead of front" << std::endl;
      return false;
   }

   if ( lst.getSize() != 2 ) {
      std::cout << "peek accidentally decremented size" << std::endl;
      return false;
   }

   val = (int *)lst.popFront();
   if ( *val != 2 ) {
      std::cout << "element popped after peek does not match" << std::endl;
      return false;
   }

   return true;
}

bool peekEmptyList( void ) {
   BranLinkedList lst;

   if ( lst.peekFront() != nullptr ) {
      std::cout << "peek front on empty list returned non-null" << std::endl;
      return false;
   }

   if ( lst.peekBack() != nullptr ) {
      std::cout << "peek back on empty list returned non-null" << std::endl;
      return false;
   }

   return true;
}

bool popEmptyList( void ) {
   BranLinkedList lst;

   if ( lst.popBack() != nullptr ) {
      std::cout << "pop back on empty list returned non-null" << std::endl;
      return false;
   }

   if ( lst.popFront() != nullptr ) {
      std::cout << "pop front on empty list returned non-null" << std::endl;
      return false;
   }

   return true;
}

// Note that this test should not memory leak
bool deleteNonEmptyList( void ) {
   int arr [] = { 1, 2, 3 };

   BranLinkedList * lst = new BranLinkedList();
   for ( int i = 0; i < 3; ++i ) {
      lst->pushBack( &arr[ i ] );
   }

   delete lst;
   return true;
}

// This method just calls the various tests above.
int main( int argv, char ** argc ) {
   if ( createList() ) {
      std::cout << "List created" << std::endl;
   }

   if ( pushOneElementList() ) {
      std::cout << "One element test passed successfully" << std::endl;
   }

   if ( pushMultipleElementsList() ) {
      std::cout << "Multiple element test passed successfully" << std::endl;
   }

   if ( pushFrontMultipleElementsList() ) {
      std::cout << "Push front test passed successfully" << std::endl;
   }

   if ( peekFrontTest() ) {
      std::cout << "Peek front test passed successfully" << std::endl;
   }

   if ( peekBackTest() ) {
      std::cout << "Peek back test passed successfully" << std::endl;
   }

   if ( peekEmptyList() ) {
      std::cout << "Peek empty list passed successfully" << std::endl;
   }

   if ( popEmptyList() ) {
      std::cout << "Pop empty list passed successfully" << std::endl;
   }

   if ( deleteNonEmptyList() ) {
      std::cout << "Delete non-empty list passed successfully (but check valgrind)" << std::endl;
   }

}
