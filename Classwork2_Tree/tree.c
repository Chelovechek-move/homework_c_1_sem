#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// Бинарное дерево поиска
// Binary search tree (BST)
struct node
{
	int value;
	struct node* left;
	struct node* right;
};
typedef struct node Node;

#include "prettyprint.h"



// Функция bst_insert вставляет элемент в бинарное дерево поиска
// и возвращает указатель на корень этого дерева
// (если дерево было пустым, то root изменится)
// Чтобы использовать: root = bst_insert_return(root, 100)
Node* bst_insert(Node* root, int x)
{
	if (root == NULL)
	{
		root = (Node*)malloc(sizeof(Node));
		root->value = x;
		root->left = NULL;
		root->right = NULL;
	}
	else if (x < root->value)
	{
		root->left = bst_insert(root->left, x);
	}
	else if (x > root->value)
	{
		root->right = bst_insert(root->right, x);
	}
	return root;
}

void bst_destroy(Node* root)
{
	if (root != NULL)
	{
		bst_destroy(root->left);
		bst_destroy(root->right);
		free(root);
	}
}

Node* create_test_tree()
{
	Node* test = NULL;
	test = bst_insert(test, 20);
	test = bst_insert(test, 15);
	test = bst_insert(test, 60);
	test = bst_insert(test, 5);
	test = bst_insert(test, 10);
	test = bst_insert(test, 40);
	test = bst_insert(test, 80);
	test = bst_insert(test, 25);
	test = bst_insert(test, 50);
	test = bst_insert(test, 90);
	return test;
}

Node* create_random_tree(int num_of_elements)
{
	Node* test = NULL;
	for (int i = 0; i < num_of_elements; i++)
		test = bst_insert(test, rand() % 1000);
	return test;
}

int bst_size(const Node* root)
{
	if(root == NULL)
		return 0;
	else
		return bst_size(root->left) + bst_size(root->right) + 1;
}

int max(int a, int b)
{
	if(a >= b)
		return a;
	else
		return b;
}

int bst_height(const Node* root)
{
	if(root == NULL)
		return 0;
	else
		return 1 + max(bst_height(root->left), bst_height(root->right));
}

Node* bst_get_min(Node* root)
{
	while(root->left != NULL)
		root = root->left;

	return root;
}

void bst_print_dfs(const Node* root)
{
	if(root == NULL)
	{
		return;
	}
	bst_print_dfs(root->left);
	printf("%d ", root->value);
	bst_print_dfs(root->right);
}

Node* bst_search(const Node* root, int val)
{
	if(root == NULL || val == root->value)
		return root;
	if(val < root->value)
		return bst_search(root->left, val);
	else
		return bst_search(root->right, val);
}


int main()
{
	srand(time(0));

	Node* root = create_test_tree();
//	Node* root = create_random_tree(10);
//	bst_insert(root, 70);
	print_ascii_tree(root);

	int size = bst_size(root);
	printf("%d\n", size);

	int height = bst_height(root);
	printf("%d\n", height);

	printf("%d\n", bst_get_min(root)->value);

	bst_print_dfs(root);
	printf("\n");

//  g это число, которое я хочу найти в дереве, если поменять его например на 2,
//  то NULL корректно выводится
	
	int g = 90;

	if(bst_search(root, g) == NULL)
		printf("NULL\n");
	else
		printf("%d\n", bst_search(root, g)->value);

	printf("OK\n");
	return 0;
}
