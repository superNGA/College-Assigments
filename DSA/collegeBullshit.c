#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <cstdint>

typedef struct doubleLinkedList_t {
	int data;			// 0x8
	struct doubleLinkedList_t* p_Prev;	// 0x10
	struct doubleLinkedList_t* p_Next;	// 0x18
}node;

// insertion
// deletion
// searching

struct DLLManager_t {
	node* pHead;
	int size;
};

void __fastcall initialize		(struct DLLManager_t* obj);
bool __fastcall insertStart		(struct DLLManager_t* obj, int data);
bool __fastcall insertEnd		(struct DLLManager_t* obj, int data);
bool __fastcall insertAtIndex	(struct DLLManager_t* obj, int index, int data);
void __fastcall display			(struct DLLManager_t* obj);
bool __fastcall deleteAtIndex	(struct DLLManager_t* obj, int index);
bool __fastcall deleteStart		(struct DLLManager_t* obj);
bool __fastcall deleteEnd		(struct DLLManager_t* obj);

int main(void) {
	struct DLLManager_t a;
	initialize(&a);
	insertStart(&a, 1);
	insertStart(&a, 2);
	insertStart(&a, 3);
	insertAtIndex(&a, 100, 9);
	insertEnd(&a, 4);
	insertEnd(&a, 5);
	insertEnd(&a, 6);
	display(&a);

	return 0;
}


void __fastcall display(struct DLLManager_t* obj) {
	node* temp = obj->pHead;
	while (temp->p_Next != obj->pHead) {
		printf("%d<->", temp->data);
		temp = temp->p_Next;
	}
	printf("%d\n", temp->data);
}


void __fastcall initialize(struct DLLManager_t* obj) {
	obj->pHead = NULL;
	obj->size = 0;
}


bool __fastcall insertStart(struct DLLManager_t* obj, int data) {
	return insertAtIndex(obj, 0, data);
}


bool __fastcall insertEnd(struct DLLManager_t* obj, int data) {
	return insertAtIndex(obj, obj->size + 1, data);
}


bool __fastcall insertAtIndex(struct DLLManager_t* obj, int index, int data) {

	if (obj == NULL) {
		printf("Not initialized or bad obj pointer\n");
		return false;
	}
	obj->size++;

	node* pNewNode = (node*)malloc(sizeof(node));
	if (pNewNode == NULL) {
		printf("failed malloc @ %d\n", index);
		return false;
	}
	pNewNode->data = data;

	// adding first element
	if (obj->size == 1) {
		obj->pHead = pNewNode;
		obj->pHead->p_Next = obj->pHead;
		obj->pHead->p_Prev = obj->pHead;
		printf("first node added -> %d\n", data);
		return true;
	}

	// choosing which direction will take least ammount of iterations
	bool ForwardDirection = (index <= obj->size / 2);
	node* TEMP_pHead = obj->pHead;

	// iterating FORWARD
	if (ForwardDirection) {		
		for (int i = 0; i < index; i++) { 
			TEMP_pHead = TEMP_pHead->p_Next;
		}
	}
	// iterating BACKWARD
	else {
		for (int i = 0; i < obj->size - index; i++) {
			TEMP_pHead = TEMP_pHead->p_Prev;
		}
	}

	// adding element to linked list
	if (!index) { // at start
		obj->pHead = pNewNode;
		
		pNewNode->p_Next = TEMP_pHead;
		pNewNode->p_Prev = TEMP_pHead->p_Prev;
		
		pNewNode->p_Prev->p_Next = pNewNode;
		pNewNode->p_Next->p_Prev = pNewNode;
	}
	else { // at end & at index
		TEMP_pHead->p_Prev->p_Next = pNewNode;
		pNewNode->p_Prev = TEMP_pHead->p_Prev;
		TEMP_pHead->p_Prev = pNewNode;
		pNewNode->p_Next = TEMP_pHead;
	}

	printf("data added : %d\n", data);
	return true;
}


bool __fastcall deleteStart(struct DLLManager_t* obj) {
	return deleteAtIndex(obj, 0);
}


bool __fastcall deleteEnd(struct DLLManager_t* obj) {
	return deleteAtIndex(obj, obj->size - 1);
}


bool __fastcall deleteAtIndex(struct DLLManager_t* obj, int index) {

	if (obj == NULL || index >= obj->size) {
		printf("Invalid index\n");
		return false;
	}

	// choosing which direction will take least ammount of iterations
	bool ForwardDirection = (index <= obj->size / 2);
	node* TEMP_pHead = obj->pHead;

	// iterating FORWARD
	if (ForwardDirection) {
		for (int i = 0; i < index; i++) {
			TEMP_pHead = TEMP_pHead->p_Next;
		}
	}
	// iterating BACKWARD
	else {
		for (int i = 0; i < obj->size - index; i++) {
			TEMP_pHead = TEMP_pHead->p_Prev;
		}
	}

	TEMP_pHead->p_Next->p_Prev = TEMP_pHead->p_Prev;
	TEMP_pHead->p_Prev->p_Next = TEMP_pHead->p_Next;

	// Adjusting head if deleted
	if (!index) {
		obj->pHead = TEMP_pHead->p_Next;
	}
	free(TEMP_pHead);
	obj->size--;
	printf("DELETED @ %d\n", index);
	return true;
}