#include <iostream>
#include <string>

using namespace std;

struct Node {
   string data;
   struct Node *prev;
   struct Node *next;
};

/// @brief Outputs all elements of a double-linked-list
/// @param h head node of double-linked-list
/// @param t tail node of double-linked-list
inline void display(Node* &h, Node* &t);

/// @brief Outputs all elements of a double-linked-list in reverse order
/// @param h head node of double-linked-list
/// @param t tail node of double-linked-list
inline void displayReverse(Node* &h, Node* &t);

/// @brief Appends (at end) a new node to a double-linked list
/// @param h head node of double-linked-list
/// @param t tail node of double-linked-list
/// @param s string data of new node
inline void append(Node* &h, Node* &t, string s);

/// @brief Prepend (at begin) a new node to a double-linked-list
/// @param h head node of double-linked-list
/// @param t tail node of double-linked-list
/// @param s string data of new node
inline void prepend(Node* &h, Node* &t, string s);

/// @brief Adds a node to a double-linked-list in least-to-greatest order
/// @param h head node of double-linked-list
/// @param t tail node of double-linked-list
/// @param s string data of new node
inline void orderedAppend(Node* &h, Node*&t, string s);

/// @brief deletes the first node containing s in the list and returns its data
/// @param h head node of double-linked-list
/// @param s string data of new node
inline void deleteData(Node* &h, Node* &t, string s);


int main()
{
    struct Node* namesH = NULL;
    struct Node* namesT = NULL;
    
    return 0;
}


inline void display(Node* &h, Node* &t)
{
    cout << "Contents of: " << &h << endl;

    //Assign ptr to the first node
    struct Node* ptr = h;

    //While ptr contains a node
    while(ptr)
    {
        cout << ptr->data << endl;
        
        //Assign ptr to the next node
        ptr = ptr->next;
    }
}

inline void displayReverse(Node* &h, Node* &t)
{
   cout << "Reversed Contents of: " << &h << endl;

   //Assign ptr to the last node
   struct Node* ptr = t;

   while(ptr)
   {
      cout << ptr->data << endl;

      //Assign ptr to the previous node
      ptr = ptr->prev;
   }
}

inline void append(Node* &h, Node* &t, string s)
{
    struct Node* newnode = new Node;
    newnode->data = s;
    newnode->next = NULL;

   //List Empty
   if(!h)
   {
      //Assign head and tail to newnode
      h = newnode;
      t = newnode;

      newnode->prev = NULL;

      return;
   }

   newnode->prev = t;

   t->next = newnode;

   t = newnode;
}

inline void prepend(Node* &h, Node* &t, string s)
{

    struct Node* newnode = new Node;

    newnode->data = s;
    newnode->prev = NULL;
    newnode->next = h;

    //If list contains values
    if(h)
    {
        //Assign the prev of the previously 'first' node to new node
        h->prev = newnode;
    }

    //Assign head to new node (new node is now the 'first' element)
    h = newnode;
}

inline void orderedAppend(Node* &h, Node*&t, string s)
{
    struct Node* ptr = h;


    //Regular append if there are no node in head
    if(!h) { append(h, t, s); return; }


    //Iterates until a node is found in which its data is greater than the new data
    do
    {
        if(s < ptr->data) { break; }
        else { ptr = ptr->next; }
    }
    while(ptr);


    //Data greater than all other elements (append to end)
    if(!ptr) { append(h, t, s); return; }

    //Data less than all other elements (prepend to begin)
    if(ptr == h) { prepend(h, t, s); return; }

    //Initializing new node and inserting
    struct Node* newnode = new Node;
    newnode->data = s;
    newnode->prev = ptr->prev;
    newnode->next = ptr;

   //Adjust prev node;
    ptr->prev->next = newnode;
    ptr->prev = newnode;
}

inline void deleteData(Node* &h, Node* &t, string s)
{
   struct Node* ptr = h;

   while(ptr)
   {
      if(ptr->data == s)
      {
         if(ptr->prev)
         {
            ptr->prev->next = ptr->next;
         }
         else
         {
            h = ptr->next;
         }
         
         if(ptr->next)
         {
            ptr->next->prev = ptr->prev;
         }
         else
         {
            t = ptr->prev;
         }

         ptr = NULL;
      }
      else { ptr = ptr->next; }
   }

   delete ptr;
}
