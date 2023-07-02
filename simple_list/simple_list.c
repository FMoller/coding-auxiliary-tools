#include<stdio.h>

#include<stdio.h>
#include<stdlib.h>

/*
* A simple list that each node stores a int value, so I dont have to figure how to implement this shit,
* and open  "C completo e total" book each time I need a list in C ANSI.
* Author: Frederico Möller
* Date: 2023 - Jul - 01
*/

/*
* A list node
*/
struct list_node {
	int index;
	int value;
	struct list_node* next;
};
typedef struct list_node node;


struct list_s {
	node* header;
	node* tail;
	int len;
};
typedef struct list_s list;

/*
* Insert a new element on the end of the list
* reg_value = the value of the element to be included on the list
* lt = the list
*/
void append(int node_val, list* lt) {
	node* new_node;
	new_node = (node*)malloc(sizeof(node));
	new_node->value = node_val;
	new_node->next = NULL;
	if (lt->len == 0) {
		lt->header = new_node;
		lt->tail = new_node;
	}
	else {
		lt->tail->next = new_node;
		lt->tail = new_node;
	}
	new_node->index = lt->len;
	lt->len++;
}
list* newList() {
	list* new_list = (list*)malloc(sizeof(list));
	new_list->header = NULL;
	new_list->tail = NULL;
	new_list->len = 0;
	return new_list;
}

void print_list(list* lt) {
	node* nd;
	printf("Index \t\t Value\n");
	for (nd = lt->header; nd != NULL; nd = nd->next) {
		printf("%d \t\t %d \n", nd->index, nd->value);
	}
}

int main() {
	printf("Test");
	list* lst1 = newList();
	append(4, lst1);
	append(11, lst1);
	append(13, lst1);
	print_list(lst1);
	append(8, lst1);
	printf("\n 8 adicionado\n");
	print_list(lst1);

}

