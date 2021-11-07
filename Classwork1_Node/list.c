#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int value;
    struct node* next;
};
typedef struct node Node;


Node* list_create ()
{
    return NULL;
}

int list_size(const Node* head)
{
	int length = 1;
	const Node* ptr = head;
	if (head == NULL)
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

// Передайм указатель head в функцию по указателю
// так как head может измениться внутри функции (если head == NULL)
void list_add_last(Node** p_head, int x)
{
    // Выделяем память на новый элемент
    Node* p_new_node = malloc(sizeof(Node));
    p_new_node->value = x;
    p_new_node->next = NULL;
    
    // Создаём указатель на первый элемент
    Node* ptr = *p_head;
    if (ptr == NULL)
    {
        *p_head = p_new_node;
    }
    else
    {
        // Идём до последнего элемента
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = p_new_node;
    }
}
int list_remove_last(Node** p_head)
{
	Node* ptr = *p_head;

	if(list_size(*p_head) == 0)
	{
		printf("Error! The list is empty!");
		exit(1);
	}

	if(list_size(*p_head) == 1)
	{
		int r_ptr = ptr->value;
		ptr->next = NULL;
		free(ptr);
		
		return r_ptr;
	}
	else
	{
		while (ptr->next->next != NULL)
	            ptr = ptr->next;

	    Node* r_ptrn = ptr->next;
	    int r_ptrv = ptr->value;
	    ptr->next = NULL;
	    free(r_ptrn);
	    return r_ptrv;
	}
}

void list_add_first(Node** p_head, int x)
{
	Node* p_new_node = malloc(sizeof(Node));
    p_new_node->value = x;
    p_new_node->next = *p_head;

    *p_head = p_new_node;
}

int list_remove_first(Node** p_head)
{
	Node* r_head = *p_head;

	if(list_size(*p_head) == 0)
	{
		printf("Error! The list is empty!");
		exit(1);
	}
	else
	{
		*p_head = (*p_head)->next;

		int r_value = r_head->value;
		free(r_head);

		return r_value;
	}
}

int list_destroy(Node* head)
{
	Node* ptr = head;

	while (ptr->next != NULL)
	{
		Node* r_node = ptr;
		ptr = ptr->next;
		free(r_node);
	}
	free(ptr);
}

void list_print(const Node* head)
{
	const Node* ptr = head;

	while(ptr->next != NULL)
	{
		printf("%d ", ptr->value);
		ptr = ptr->next;
	}
	printf("%d ", ptr->value);
}


int main()
{
    Node* head = list_create();

    printf("Adding 20 elements:\n");
    for (int i = 0; i < 20; ++i)
        list_add_first(&head, i);
    list_print(head);
    printf("\nList size = %d\n\n", list_size(head));

    printf("Removing 5 first elements elements and 5 last elements:\n");
    for (int i = 0; i < 5; ++i)
    {
        list_remove_first(&head);
        list_remove_last(&head);
    }
    list_print(head);
    
    list_destroy(head);
    
}
