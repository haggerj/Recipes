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

}
