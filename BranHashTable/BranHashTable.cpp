/*
 * Imlementation file for Bran hash table for recipe
 *
 * Created by: Bran Hagger
 */

#include "BranHashTable.h"

namespace butil {

   BranHashTable::~BranHashTable() {
      delete this->buckets;
      /*
       * Everything else should clean itself up automagically
       * once we delete the buckets.
       */
   }

   LLPayload_t find( uint64_t key ) {
      uint64_t bucket = key % numBuckets;

      BranLinkedList::Iterator iter = buckets[bucket].begin();
      while( iter != buckets[bucket].end() ) {
         BranKVPair * kv = (BranKVPair*)(*iter);
         if ( kv->key == key ) {
            return kv->val;
         }
      }

      return nullptr;
   }

   LLPayload_t remove( uint64_t key ) {
      uint64_t bucket = key % numBuckets;

      BranLinkedList::Iterator iter = buckets[bucket].begin();
      while( iter != buckets[bucket].end() ) {
         BranKVPair * kv = (BranKVPair*)(*iter);
         if ( kv->key == key ) {
            iter.remove();
            LLPayload_t toReturn = kv->val;
            delete kv;
            return toReturn;
         }
      }
   }

}
