#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack createStack(void){
	LinkedList* list = calloc(sizeof(LinkedList),1);
	Stack stack = {list,&list->tail};
	return stack;
}

int push(Stack* s1, void *data){
	Node *n1 = create_node(data);
	int count = s1->list->count;
	add_to_list(s1->list,n1);
	if(s1->list->count == count+1){
		return s1->list->count;
	}
	return -1;
}

void * pop(Stack* s){
	void *deleted;
	deleted = deleteElementAt(s->list,s->list->count-1); 
	return deleted;
}
