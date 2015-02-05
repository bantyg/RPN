#include <stdio.h>
#include "linkedList.h"
#include <string.h>
#include <stdlib.h>

LinkedList createList(int data){
	LinkedList l1 = {NULL,NULL,0};
	return l1;
}

Node* create_node(void* data){
	Node *n1 = malloc(sizeof(Node));
	n1->data = data;
	n1->next = NULL;
	return n1;
}

int add_to_list(LinkedList *l1,Node *n1){
	if((*l1).head==NULL){
		(*l1).head = n1;
		(*l1).tail = n1;
	}
	else{
		l1->tail->next = n1;
		(*l1).tail = n1;
	}
	(*l1).count++;
	return 0;
}

void *get_first_element(LinkedList list){
	return list.head;
}

void *get_last_element(LinkedList list){
	return list.tail;
}

void traverse(LinkedList list, void (*func)(void* data)) {
	Node* walker = list.head;
	while(walker!=NULL){
		func(&(walker->data));
		walker = walker->next;
	}
}

void * getElementAt(LinkedList l1, int index ){
	int i;
	Node* walker = l1.head;
	if(index>=l1.count){
		return NULL;
	}
	for ( i = 0; i<index; i++){
		walker = walker->next;
	}
		return &(walker->data);
}

int indexOf(LinkedList l1, void *data){
	int i,flag;
	Node* walker = l1.head;
	int walkerIndex;
	for (i = 0; i < l1.count-1; i++){	
		if((char)walker->data == *(char*)data){
			flag=i;
			return flag;
		}
		walker = walker->next;
	}
	return -1;
}


int asArray(LinkedList l1, void **array){
	int i,count=0;
	Node* walker = l1.head;
	*array = malloc(sizeof(Node)*l1.count);
	for (i = 0; i < l1.count; ++i){
		array[i] = walker->data;
		walker = walker->next;
		count++;
	}
	return count;
}

LinkedList * filter(LinkedList l1, int (*operation)(void *ele)){
	int i;
	LinkedList *filteredList=malloc(sizeof(l1));
	Node* walker = l1.head;
	for(i=0;i<l1.count;++i){
		if(operation(walker->data)){
			add_to_list(filteredList, walker);	
		} 
		walker=walker->next;
	}
	return filteredList;
}

void * deleteElementAt(LinkedList *list, int index){
	int i;
	void* data;
	Node* listHead =list->head;
	Node* previousNode=NULL;
	
	if(index>=list->count||index<0) return NULL;
	for(i=0;i<index;i++){
		previousNode = listHead;
		listHead=listHead->next;
	}
	if(list->tail==listHead) list->tail=previousNode;
	data= listHead->data;
	previousNode?(previousNode->next =listHead->next):(list->head =list->head->next);
	list->count--;
	free(listHead);
	return data;
}