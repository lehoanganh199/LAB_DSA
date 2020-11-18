#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

// #pragma pack(1)

struct d_NODE {
    int key;
    d_NODE* pNext;
    d_NODE* pPrev;
};

struct d_List {
    d_NODE* pHead;
    d_NODE* pTail;
};

// Initialize a node from a given integer.
d_NODE* createNode(int value);

// Initialize a list from a given integer.
d_List* createList(int value);

// Check if the list is empty or not.
bool isEmpty(d_List* dList);

// Add a node at the front of a given List.
bool addHead(d_List* &dList, int value);

// 3. Add a node before a given node.
bool insertBefore(d_List* &dList, d_NODE* &node, int value);

// 4. Add a node after a given node.
bool insertAfter(d_List* &dList, d_NODE* &node, int value);

// 5. Add a node at the end of a given List.
bool addTail(d_List* &dList, int value);

// 6. Remove a node at the front of a given List. 
void removeHead(d_List* &dList);

// 7. Remove a node at the end of a given List. 
void removeTail(d_List* &dList);

// 8. Remove the first node with given value.
void removeFirstValue(d_List* &dList, int value);

void removeAll(d_List* &dList);

#endif