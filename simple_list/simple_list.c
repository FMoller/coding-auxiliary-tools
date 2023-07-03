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

/*
* A list
*/
struct list_s {
	node* header;
	node* tail;
	int len;
};
typedef struct list_s list;

/*
* List "constructor"
*/
list* newList() {
	list* new_list = (list*)malloc(sizeof(list));
	new_list->header = NULL;
	new_list->tail = NULL;
	new_list->len = 0;
	return new_list;
}

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


/*
* Prints the list lt
*/
void print_list(list* lt) {
	node* nd;
	printf("Index \t\t Value\n");
	for (nd = lt->header; nd != NULL; nd = nd->next) {

		printf("%d \t\t %d \n", nd->index, nd->value);
	}
}

/*
* Insert a new node in a given position
* pos = position in the list, it can be a negative values, what would mean counting the position from the end.
* The list values aftert the pos will be shifted one pos.
* new_value = the value to be inserted
* lt = the list
*/
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

/*
* Get a node from a position in a list
* pos = the position of the node, it can be negative numbers, what mean the positions in backward
*/
node* get_fromPos(int pos, list* lt) {
	if (pos >= lt->len || pos < -(lt->len)) {
		printf("Position exceeds list lenght");
		exit(-1);
	}
	else {
		node* nd = lt->header;
		if (pos < 0) {
			pos = lt->len + pos;
		}
		for (int i = 0; i < pos; i++, nd = nd->next) {}
		return nd;
	}
}

node* find(int value, list* lt) {
	for (node* nd = lt->header; nd != NULL; nd = nd->next) {
		if (nd->value == value) {
			return nd;
		}
	}
	printf("\n Value not found in the list");
	return NULL;
}

/*
* Just deletes a node given a position, does not try connect the prev node to the next one. used just to delete the list
*/
void just_del_pos(int pos, list* lt) {
	free(get_fromPos(pos, lt));
}

/*
* Deletes the list from the memory
*/
void del_list(list* lt) {
	for (int i = lt->len - 1; i >= 0; i--) {
		just_del_pos(i, lt);
	}
	//free(lt);
	printf("\n List Deleted");
}



int main() {
	for (int i = 0; i < 3000000000; i++);
	printf("Test");
	list* lst1 = newList();
	node* teste;
	for (int i = 0; i < 3000000000; i++);
	printf("\n 8 adicionado\n");
	for (int i = 0; i < 3000000000; i++);
	for (int i = 0; i < 10000; i++) {
		append(i, lst1);
	}
	//print_list(lst1);
	append(4, lst1);
	append(11, lst1);
	append(13, lst1);
	//print_list(lst1);
	append(3, lst1);
	//printf("\n 3 adicionado\n");
	for (int i = 0; i < 3000000000; i++);
	//print_list(lst1);
	insert(2, 88, lst1);
	//printf("\n Insert 88 feito \n");
	//print_list(lst1);
	insert(4, 4, lst1);
	//printf("\n Insert 4 feito \n");
	//print_list(lst1);
	insert(6, 12, lst1);
	//printf("\n Insert 12 feito \n");
	//print_list(lst1);
	teste = get_fromPos(2, lst1);
	//printf("\n Pos 2 da lista eh %d", teste->value);
	teste = get_fromPos(-1, lst1);
	printf("\n Pos -1 da lista eh %d", teste->value);
	printf("\n ************* \n HEADER INDEX %d\n ************* \n", lst1->header->index);
	teste = find(4, lst1);
	printf("\n\n list len = %d", lst1->len);
	if (teste != NULL) {
		printf("\n the first position of 4 in the list is %d", teste->index);
	}

	for (int i = 0; i < 3000000000; i++);
	del_list(lst1);
	print_list(lst1);
	for (int i = 0; i < 9000000000; i++);

}