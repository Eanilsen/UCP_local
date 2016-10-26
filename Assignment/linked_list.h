#ifndef LINKED_LIST_H_0SKXHUYL
#define LINKED_LIST_H_0SKXHUYL

typedef struct LinkedListNode
{
    void *data;
    struct LinkedListNode *next;
    struct LinkedListNode *previous;
} LinkedListNode;

typedef struct
{
    LinkedListNode *head;
    LinkedListNode *tail;
    int size;
} LinkedList;

LinkedList* initialize();

void append(LinkedList *list, void *data);

void prepend(LinkedList *list, void *data);

void firstNode(LinkedList *list, void *data);

void freeList(LinkedList *list);

LinkedListNode* findNode(LinkedList *list, int index);

void deleteNode(LinkedList *list, int index);

LinkedListNode *pop(LinkedList *list, int index);


#endif /* end of include guard: LINKED_LIST_H_0SKXHUYL */
