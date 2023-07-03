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

void insert(int pos, int new_value, list* lt) {
	node* nd, * nd_prev, * new_node;
	nd = lt->header;
	nd_prev = lt->header;
	if (abs(pos) > lt->len) {
		printf("\n Out of Range \n");
	}
	else {
		if (pos < 0) {
			pos = lt->len + pos;
		}
		if (lt->len == pos)
			append(new_value, lt);
		else {
			new_node = (node*)malloc(sizeof(node));
			new_node->value = new_value;
			for (int i = 0; i < pos; i++, nd = nd->next) {
				nd_prev = nd;
			}
			new_node->next = nd;
			new_node->index = pos;
			if (pos == 0) {
				lt->header = new_node;
			}
			else {
				nd_prev->next = new_node;
			}
			for (; nd->next != NULL; nd = nd->next) {
				nd->index++;
			}
			nd->index++;
			lt->len++;
		}
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
	insert(2, 88, lst1);
	printf("\n Insert 88 feito \n");
	print_list(lst1);
	insert(4, 4, lst1);
	printf("\n Insert 4 feito \n");
	print_list(lst1);
	insert(6, 12, lst1);
	printf("\n Insert 12 feito \n");
	print_list(lst1);

}

