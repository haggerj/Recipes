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
      BranLinkedListNode * newNode = nullptr;

      try {
         newNode = new BranLinkedListNode();
      } catch ( std::bad_alloc& ba ) {
         return false;
      }

      newNode->val = toAdd;
      newNode->prev = this->tail;

      if ( this->head == nullptr ) {
        this->head = newNode;
        this->tail = newNode;
      } else {
        this->tail->next = newNode;
        this->tail = newNode;
      }
   
      ++this->size;
      return true;
   }

   bool BranLinkedList::pushFront( LLPayload_t toAdd ) {
      BranLinkedListNode * newNode = nullptr;

      try {
         newNode = new BranLinkedListNode();
      } catch ( std::bad_alloc& ba ) {
         return false;
      }

      newNode->val = toAdd;
      newNode->next = this->head;

      if ( this->tail == nullptr) {
         this->tail = newNode;
         this->head = newNode;
      } else {
         this->head->prev = newNode;
         this->head = newNode;
      }

      ++this->size;
      return true;
   }

   LLPayload_t BranLinkedList::peekFront( void ) {
      if ( this->head == nullptr ) {
         return nullptr;
      }

      return this->head->val;
   }

   LLPayload_t BranLinkedList::popFront( void ) {
      if ( this->head == nullptr ) {
         return nullptr;
      }

      BranLinkedListNode * oldHead = this->head;
      this->head = this->head->next;      
      if ( this-> head != nullptr ) {
         this->head->prev = nullptr;
      } else {
         this->tail = nullptr;
      }
      --this->size;

      LLPayload_t value = oldHead->val;
      delete oldHead;
      return value;
   }

   LLPayload_t BranLinkedList::peekBack( void ) {
      if ( this->tail == nullptr ) {
         return nullptr;
      }

      return this->tail->val;
   }

   LLPayload_t BranLinkedList::popBack( void ) {
      if ( this->tail == nullptr ) {
         return nullptr;
      }

      BranLinkedListNode * oldTail = this->tail;
      this->tail = this->tail->prev;
      if ( this->tail != nullptr ) {
         this->tail->next = nullptr;
      } else {
         this->head = nullptr;
      }
      --this->size;

      LLPayload_t value = oldTail->val;
      delete oldTail;
      return value;
   }

   bool BranLinkedList::isEmpty( void ) {
      return this->head == nullptr;
   }

   unsigned int BranLinkedList::getSize( void ) {
      return this->size;
   }

   BranLinkedList::~BranLinkedList() {
      while ( !( this->isEmpty() ) ) {
         BranLinkedListNode * temp = this->head;
         this->head = this->head->next;

         /* 
          * We are almost certainly leaking memory for whatever
          * was stored in the list here, but we can't do anything
          * about that.
          *
          * Let's at least clean up our own stuff, though.
          */
          delete temp;
      }
   }

   BranLinkedList::Iterator BranLinkedList::begin( void ) {
      return BranLinkedList::Iterator( this->head );
   }

   BranLinkedList::Iterator BranLinkedList::end( void ) {
      return BranLinkedList::Iterator( nullptr );
   }

   BranLinkedList::Iterator& BranLinkedList::Iterator::operator++() {
      if ( this->mylst != nullptr ) {
         this->mylst = this->mylst->next;
      }
      return *this;
   }

   BranLinkedList::Iterator BranLinkedList::Iterator::operator++(int) {
      BranLinkedList::Iterator tmp(this->mylst);
      ++(*this);
      return tmp;
   }

   LLPayload_t& BranLinkedList::Iterator::operator*() {
      return this->mylst->val;
   }

   bool BranLinkedList::Iterator::operator==( const 
        BranLinkedList::Iterator& other ) {
      return this->mylst == other.mylst;
   }

   bool BranLinkedList::Iterator::operator!=( const
        BranLinkedList::Iterator& other ) {
      return this->mylst != other.mylst;
   }

}
