typedef struct LinkedList LinkedList;
typedef struct Node Node;

struct LinkedList{
	Node* head;
	Node* tail;
	int count;
};

struct Node{
	void* data;
	Node* next;
};

LinkedList createList();
Node* create_node(void* data);
int add_to_list(LinkedList *,Node *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void traverse(LinkedList, void (*)(void *data));
void * getElementAt(LinkedList, int );
int indexOf(LinkedList, void *);
void * deleteElementAt(LinkedList *, int);
int asArray(LinkedList, void **);
LinkedList * filter(LinkedList, int (*)(void *));