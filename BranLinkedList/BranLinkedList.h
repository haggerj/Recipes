/*
 * A simple linked list implementation for Recipe project
 * Created by: Bran Amour Hagger
 */

#ifndef BRAN_LINKED_LIST
#define BRAN_LINKED_LIST

namespace butil {

   typedef void* LLPayload_t;

   class Bran_Linked_List_Node {
      friend class Bran_Linked_List;
   
      private:
         void * val;
         Bran_Linked_List * next;
   }

   class Bran_Linked_List {
      public:
         int push_back(LLPayload_t toAdd);
         LLPayload_t pop_front(void);
         LLPayload_t peek_front(void);
         
         int push_front(LLPayload_t toAdd);
         LLPayload_t pop_back(void);
         LLPayload_t peek_back(void);
         
         unsigned int getSize(void);

         class Iterator {
            public:
                Iterator(Bran_Linked_List * lst) : mylst(lst) {}
		~Iterator();
                
                bool operator==(const Iterator& other);
                bool operator!=(const Iterator& other);
                Iterator& operator++();
                Iterator& operator++(int);
                LLPayload_t& operator*();
            private:
               Bran_Linked_List * mylst;
         };

         Iterator begin();
         Iterator end();

      private:
         Bran_Linked_List_Node * head;
         Bran_Linked_List_Node * tail;
         unsigned int size;
   };
}

#endif // BRAN_LINKED_LIST
