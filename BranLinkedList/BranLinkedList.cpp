/*
 * A simple linked list implementation for Recipe project
 * Created by: Bran Hagger
 */

#include <stdbool.h>
#include <new> // std::badalloc

#include "BranLinkedList.h"

namespace butil {

   bool BranLinkedList::pushBack( LLPayload_t toAdd ) {
      // This must be new'ed, because it will continue to exist.
      // Deleted in destructor or on pop
      BranLinkedListNode * newNode = NULL;

      try {
         newNode = new BranLinkedListNode();
      } catch ( std::badalloc& ba ) {
         return false;
      }

      newNode->val = toAdd;
      newNode->prev = this->tail;

      if ( this->head == NULL ) {
        this->head = newNode;
        this->tail = newNode;
      } else {
        this->tail->next = newNode;
        this->tail = newNode;
      }
   
      ++size;
      return true;
   }

   bool BranLinkedList::pushFront( LLPayload_t toAdd ) {
      BranLinkedList Node * newNode = NULL;

      try {
         newNode = new BranLinkedListNode();
      } catch ( std::badalloc& ba ) {
         return false;
      }

      newNode->val = toAdd;
      newNode->next = this->head;

      if ( this->tail == NULL) {
         this->tail = newNode;
         this->head = newNode;
      } else {
         this->head->prev = newNode;
         this->head = newNode;
      }

      ++size;
      return true;
   }

   unsigned int BranLinkedList::getSize( void ) {
      return this->size;
   }

}
