#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node* next;
	struct node* prev;
};
typedef struct node Node;


struct list
{
	Node* head;
	Node* tail;
};
typedef struct list List;

List* list_create()
{
	List* new_list = (List*)malloc(sizeof(List));
	new_list->head = NULL;
	new_list->tail = NULL;
	return new_list;
}

void list_print(const List* plist)
{
	Node* ptr = plist->head;
	while (ptr != NULL)
	{
		printf("%d  ", ptr->value);
		ptr = ptr->next;
	}
	printf("\n");
}


void list_add_last(List* plist, int new_value)
{
	Node* pn = (Node*)malloc(sizeof(Node));
	pn->value = new_value;
	pn->next = NULL;
	pn->prev = plist->tail;

	// Отдельно обрабатываем случай пустого списка
	if (plist->head == NULL)
	{
		plist->head = pn;
	}
	else
	{
		plist->tail->next = pn;
	}
	plist->tail = pn;
}

int list_size(const List* plist)
{
	int length = 1;
	Node* ptr = plist->head;

	if (plist->head == NULL)
    {
        return 0;
    }
    else
    {
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
			length++;
		}

	return length;
	}
}

void list_add_first(List* plist, int x)
{
	Node* pn = (Node*)malloc(sizeof(Node));
	pn->value = x;
	pn->next = plist->head;
	pn->prev = NULL;

	// Отдельно обрабатываем случай пустого списка
	if (plist->head == NULL)
	{
		plist->head = pn;
		plist->tail = pn;
	}
	else
	{
		plist->head->prev = pn;
		pn->next = plist->head;
		pn->prev = NULL;

		plist->head = pn;
//		plist->tail->next = pn;
	}
}

int list_remove_first(List* plist)
{
	if(list_size(plist) == 0)
	{
		printf("Error! List is empty!");
		exit(0);
	}
	if(list_size(plist) == 1)
	{
//		Node* remhead = plist->head;
		int remvalue = plist->head->value;
		free(plist->head);
		plist->head = NULL;
		plist->tail = NULL;

		return remvalue;
	}
	else
	{
		int remvalue = plist->head->value;
		Node* remhead = plist->head;
		plist->head = plist->head->next;
		plist->head->prev = NULL;
		free(remhead);

		return remvalue;
	}
}

int list_remove_last(List* plist)
{
	if(list_size(plist) == 0)
	{
		printf("Error! List is empty!");
		exit(0);
	}
	if(list_size(plist) == 1)
	{
//		Node* remhead = plist->head;
		int remvalue = plist->head->value;
		free(plist->head);
		plist->head = NULL;
		plist->head = NULL;

		return remvalue;
	}
	else
	{
		int remvalue = plist->tail->value;
		Node* remtail = plist->tail;
		plist->tail = plist->tail->prev;
		plist->tail->next = NULL;
		free(remtail);

		return remvalue;
	}
}

Node* list_find(const List* plist, int x)
{
	Node* ptr = plist->head;

	while(ptr->next != NULL)
	{
		if(ptr->value == x)
			break;
		ptr = ptr->next;		
	}
	if(ptr->value == x)
		return ptr;
	else
		return NULL;
}

void list_insert_after(Node* a, Node* b)
{
	a->next = b->next;
	b->next = a;

	a->prev = b;
	a->next->prev = a;	
}

int list_remove( Node* p)
{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);		
}

void list_destroy(List* plist)
{
	Node* ptr = plist->head;
	while (ptr != NULL)
	{
		Node* ptrn = ptr->next;
		free(ptr);

		ptr = ptrn;
	}

	free(plist);	
}

/*
void list_print(const List* plist)
{
	Node* ptr = plist->head;
	while (ptr != NULL)
	{
		printf("%d  ", ptr->value);
		ptr = ptr->next;
	}
	printf("\n");
}
*/
void swap_elements(list_element* a, list_element* b)
{
	list_element* pn = (list_element*)malloc(sizeof(list_element));
	pn->value = a->value;
	pn->next = a->next;
	pn->prev = a->prev;

	a->next = b->next;
	b->next = a;
	a->prev = b;
	a->next->prev = a;	

	b->value = pn->value;
	b->next = pn->next;
	b->prev = pn->prev;

	pn->prev->next = pn->next;
	pn->next->prev = pn->prev;
	free(pn);

	b->prev->next = b->next;
	b->next->prev = b->prev;
	free(b);
}

void list_insert_after(Node* a, Node* b)
{
	a->next = b->next;
	b->next = a;

	a->prev = b;
	a->next->prev = a;	
}
int list_remove(Node* p)
{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);		
}

int main()
{
	List* plist = list_create();
	for(int i = 1; i <= 20; i++)
	{
		list_add_last(plist, i);
	}
	list_print(plist);

	Node* element1;
	printf("Looking for element 7:\n");
	element1 = list_find(plist, 7);
	if(element1 != NULL)
		printf("%d\n", element1->value);
	else
		printf("NULL\n");

	Node* element2;
	printf("Looking for element 10:\n");
	element2 = list_find(plist, 10);
	if(element2 != NULL)
		printf("%d\n", element2->value);
	else
		printf("NULL\n");

	swap_elements(element1, element2);
		list_print(plist);

/*
	printf("Removing all elements:\n");
	for(int i = 1; i <= 20; i++)
	{
		int x = list_remove_last(plist);
		printf("Removing: %d\n", x);
	}

	printf("Adding new 20 elements:\n");
	for(int i = 1; i <= 10; i++)
	{
		list_add_first(plist, i);
//		printf("k %d\n", i);
		list_add_last(plist, i * i);
//		printf("kk %d\n", i);
	}
	list_print(plist);

	printf("Removing all elements again:\n");
	for(int i = 1; i <= 20; i++)
	{
		int x = list_remove_first(plist);
		printf("Removing: %d\n", x);
	}

	printf("Adding new 10 elements:");
	for(int i = 1; i <= 10; i++)
	{
		list_add_last(plist, i);
	}
	list_print(plist);
	
	printf("Looking for element 7:\n");
	Node* element = list_find(plist, 7);

	printf("Inserting 5 elements after 7:\n");
	for(int i = 1; i <= 5; i++)
	{
		list_insert_after(plist, element, 100 + i);
	}
	list_print(plist);

	list_destroy(plist);
*/
// Это мой отладочный код, оставил его так как подумал, что он может быть вам полезен в проверке
// Здесь проверяются практически все условия во всех функциях
/*
	printf("Number of elements = %d\n", list_size(plist));

	list_add_first(plist, 30);
	list_print(plist);
	printf("Number of elements = %d\n", list_size(plist));

	printf("Element removed from the beginning = %d\n", list_remove_first(plist));
	list_print(plist);
	printf("Number of elements = %d\n", list_size(plist));

	printf("Element removed from the beginning = %d\n", list_remove_first(plist));
	list_print(plist);
	printf("Number of elements = %d\n", list_size(plist));

	printf("Element removed from the end = %d\n", list_remove_last(plist));
	list_print(plist);
	printf("Number of elements = %d\n", list_size(plist));

	printf("Element removed from the end = %d\n", list_remove_last(plist));
	list_print(plist);
	printf("Number of elements = %d\n", list_size(plist));

	Node* element;
	printf("Looking for element 7:\n");
	element = list_find(plist, 7);
	if(element != NULL)
		printf("%d\n", element->value);
	else
		printf("NULL\n");

	list_insert_after(plist, element, 555);
	list_print(plist);
	printf("Number of elements = %d\n", list_size(plist));

	list_insert_after(plist, element, 660);
	list_print(plist);
	printf("Number of elements = %d\n", list_size(plist));

	printf("Looking for element 555:\n");
	element = list_find(plist, 555);
	if(element != NULL)
		printf("%d\n", element->value);
	else
		printf("NULL\n");

	list_insert_after(plist, element, 660);
	list_print(plist);
	printf("Number of elements = %d\n", list_size(plist));

	printf("Looking for element 18:\n");
	element = list_find(plist, 18);
	if(element != NULL)
		printf("%d\n", element->value);
	else
		printf("NULL\n");

	list_insert_after(plist, element, 105);
	list_print(plist);
	printf("Number of elements = %d\n", list_size(plist));

	printf("Looking for element 105:\n");
	element = list_find(plist, 105);
	if(element != NULL)
		printf("%d\n", element->value);
	else
		printf("NULL\n");

	list_insert_after(plist, element, 110);
	list_print(plist);
	printf("Number of elements = %d\n", list_size(plist));

	printf("Looking for element 13:\n");
	element = list_find(plist, 13);
	if(element != NULL)
		printf("%d\n", element->value);
	else
		printf("NULL\n");

	printf("Deleted element = %d\n", list_remove(plist, element));

	list_print(plist);
	printf("Number of elements = %d\n", list_size(plist));

	printf("Looking for element 12:\n");
	element = list_find(plist, 12);
	if(element != NULL)
		printf("%d\n", element->value);
	else
		printf("NULL\n");

	printf("Deleted element = %d\n", list_remove(plist, element));

	list_print(plist);
	printf("Number of elements = %d\n", list_size(plist));

	printf("Looking for element 14:\n");
	element = list_find(plist, 14);
	if(element != NULL)
		printf("%d\n", element->value);
	else
		printf("NULL\n");

	printf("Deleted element = %d\n", list_remove(plist, element));

	list_print(plist);
	printf("Number of elements = %d\n", list_size(plist));

	list_destroy(plist);
	printf("List successfully destroyed");
*/
}