#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct DoublyLinkedList{
    Node* head;
    Node* tail;
} DoublyLinkedList;

void createList(DoublyLinkedList** list){
    *list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    (*list)->head = NULL;
    (*list)->tail = NULL;
}

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int getLengthNode(DoublyLinkedList* list){
    Node* current = list->head;
    int length = 0;
    while(current != NULL){
        length++;
        current = current->next;
    }
    return length;
}

void unshiftNode(DoublyLinkedList** list, int data){
    Node* newNode = createNode(data);
    if((*list)->head == NULL){
        (*list)->head = newNode;
        (*list)->tail = newNode;
    }
    else{
        newNode->next = (*list)->head;
        (*list)->head->prev = newNode;
        (*list)->head = newNode;
    }
}

void shiftNode(DoublyLinkedList** list){
    if((*list)->head == (*list)->tail){
        (*list)->head = NULL;
        (*list)->tail = NULL;
        free((*list)->head);
    }
    else{
        Node* temp = (*list)->head;
        (*list)->head = (*list)->head->next;
        free(temp);
    }
}

void pushNode(DoublyLinkedList** list, int data){
    Node* newNode = createNode(data);
    newNode->next = (*list)->head;
    (*list)->head->prev = newNode;
    (*list)->head = newNode;
}

void insertNodeAt(DoublyLinkedList** list, int index, int data){
    int length = getLengthNode(*list);
    if(index < 0 || index > length) return;
    if(index == 0){
        unshiftNode(list, data);
        return;
    }
    if(index == length){
        pushNode(list, data);
        return;
    }
    Node* current = (*list)->head;
    Node* newNode = createNode(data);
    for(int i = 0; i < index - 1; i++){
        current = current->next;
    }
    Node* nextNode = current->next;
    current->next = newNode;
    newNode->prev = current;
    newNode->next = nextNode;
}

void printListNode(DoublyLinkedList* list){
    Node* current = list->head;
    while(current!= NULL){
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(){
    DoublyLinkedList* list = NULL;
    createList(&list);
    unshiftNode(&list, 10);
    unshiftNode(&list, 20);
    unshiftNode(&list, 30);
    insertNodeAt(&list, 1, 50);
    printListNode(list);
    return 0;
}
