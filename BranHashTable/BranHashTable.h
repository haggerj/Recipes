/*
 * A simple hash table header file for the Recipe project.
 * Again, libraries exist, but that doesn't teach you much.
 *
 * Uses serial chaining instead of probing, for help with
 * serialization later.
 *
 * Created by: Bran Hagger
 */

#ifndef BRAN_HASH_TABLE
#define BRAN_HASH_TABLE

#include "../BranLinkedList.h"
#include <new>

namespace butil {

   /*
    * Multiple classes are going to want key-value pairs (this, sets,
    * etc.). Since none of these classes should expose the key value
    * pairs to their users (at least, not without careful consideration),
    * lets just make a KV pair into a struct.
    *
    * The alternative is individually listing each class that uses a KVPair
    * as a struct here, which is just too messy.
    */
   struct BranKVPair {
      uint64_t key;
      LLPayload_t val;
   };

   class BranHashTable {
      public:
         // Implementing the default constructor here because it uses
         // list initialization
         BranHashTable() : numBuckets(113) {
            /*
             * Since these are linked lists and not pointers to linked
             * lists, each linked list should be default initialized
             * after this statement. We don't need to initialize them
             * individually.
             */
            buckets = new BranLinkedList[numBuckets];
         }
         ~BranHashTable();
         LLPayload_t add( uint64_t key, LLPayload_t val);
         LLPayload_t remove( uint64_t key );
         LLPayload_t find( uint64_t key );

         class Iterator {
            public:
               Iterator( BranHashTable * table, unsigned startBucket ) : 
                         myTable(table), bucket(startBucket) {
                  if ( startBucket < myTable.numBuckets ) {
                     bucketIter = (*myTable)[startBucket].begin();
                  } else {
                     bucketIter = (*myTable)[myTable->numBuckets - 1].end();
                  }
               }
               ~Iterator() {}

               bool operator==(const Iterator& other);
               bool operator!=(const Iterator& other);
               Iterator& operator++();
               Iterator operator++(int);
               LLPayload_t& operator*();
            private:
               BranHashTable * myTable;
               unsigned bucket;
               BranLinkedList::Iterator bucketIter;
         }

         Iterator begin(void);
         Iterator end(void);

      private:
         /*
          * Under the hood, buckets will be the pointer to the first
          * element of an array of linked lists numBuckets long.
          */
         BranLinkedList * buckets;
         unsigned numBuckets;
   };
}

#endif // BRAN_HASH_TABLE
