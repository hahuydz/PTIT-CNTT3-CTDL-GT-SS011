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

void printListNode(DoublyLinkedList* list){
    Node* current = list->head;
    while(current!= NULL){
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int findByValue(DoublyLinkedList* list, int dataSearch){
    Node* current = list->head;
    while(current != NULL){
        if(current->data == dataSearch){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main(){
    DoublyLinkedList* list = NULL;
    createList(&list);
    list->head = createNode(10);
    Node* node1 = createNode(20);
    Node* node2 = createNode(30);
    Node* node3 = createNode(40);
    list->tail = createNode(50);
    list->head->next = node1;
    node1->prev = list->head;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = list->tail;
    list->tail = node3;
    printListNode(list);
    int dataSearch;
    printf("Nhập giá trị cần tìm kiếm: ");
    scanf("%d", &dataSearch);
    int result = findByValue(list, dataSearch);
    result ? printf("True") : printf("False");
    return 0;
}
