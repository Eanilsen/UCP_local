#ifndef TESTFILE_H_0SKXHUYL
#define TESTFILE_H_0SKXHUYL

typedef struct LinkedListNode
{
    int value;
    struct LinkedListNode *next;
} LinkedListNode;

typedef struct
{
    LinkedListNode *head;
} LinkedList;

LinkedList* initialize();

void newNode(LinkedList *list, int val);

void printValue(LinkedListNode *head);

#endif /* end of include guard: TESTFILE_H_0SKXHUYL */
