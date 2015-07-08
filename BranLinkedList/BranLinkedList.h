/*
 * A simple linked list implementation for Recipe project
 * 
 * Yes, it would be better to ust use std::vector, but the point
 * is to practice C++.
 *
 * Created by: Bran Amour Hagger
 */

#ifndef BRAN_LINKED_LIST
#define BRAN_LINKED_LIST

#include <stdbool.h>

namespace butil {

   typedef void* LLPayload_t;

   class BranLinkedListNode {
      friend class BranLinkedList;
   
      private:
         LLPayload_t val;
         BranLinkedListNode * next;
         BranLinkedListNode * prev;
   }

   class BranLinkedList {
      public:
         // Default constructor should be generated automatically.

         bool pushBack(LLPayload_t toAdd);
         LLPayload_t popFront(void);
         LLPayload_t peekFront(void);
         
         bool pushFront(LLPayload_t toAdd);
         LLPayload_t popBack(void);
         LLPayload_t peekBack(void);
         
         unsigned int getSize(void);

         class Iterator {
            public:
                Iterator(BranLinkedList * lst) : mylst(lst) {}
		~Iterator();
                
                bool operator==(const Iterator& other);
                bool operator!=(const Iterator& other);
                Iterator& operator++();
                Iterator& operator++(int);
                LLPayload_t& operator*();
            private:
               BranLinkedList * mylst;
         };

         Iterator begin(void);
         Iterator end(void);

      private:
         BranLinkedListNode * head;
         BranLinkedListNode * tail;
         unsigned int size;
   };
}

#endif // BRAN_LINKED_LIST
