#include<stdio.h>
#include<stdlib.h>
#include<stddef.h> // size_t

/*
* File Name: simple_list.c
* Description: A simple list that each node stores a int value, so I dont have to figure how to implement this thing,
* and open  "C completo e total" book each time I need a list in C ANSI.
* Author: Frederico Möller
* Created: 2023 - Jul - 01
* Copyright MIT license
* Modification History:
* 2025 - Fev -12 - Updated the file description and excluded the index member of a node
*/

/*
* A list node
*/
struct list_node {
	int data;
	struct list_node* next;
};
typedef struct list_node node_s;

/*
* A list
*/
struct list_s {
	node_s* head;
	node_s* tail;
	size_t len;
};
typedef struct list_s list_simple;

/*
* List "constructor"
*/
list_simple* newListSimple() {
	list_simple* new_list_simple = (list_simple*)malloc(sizeof(list_simple));
	if (new_list_simple == NULL) {
		//In case of no memory left
        printf(stderr, "Error: Memory allocation failed!\n");  
        return NULL; 
    }
	new_list_simple->head = NULL;
	new_list_simple->tail = NULL;
	new_list_simple->len = 0;
	return new_list_simple;
}

/*
* Insert a new element on the end of the list
* reg_value = the value of the element to be included on the list
* lt = the list
*/
void append(int node_data, list_simple* lt) {
	node_s* new_node;
	new_node = (node_s*)malloc(sizeof(node_s));
	if (new_node == NULL) {
		//In case of no memory left
        printf(stderr, "Error: Memory allocation failed!\n");  
        return 1; 
    }
	new_node->data = node_data;
	new_node->next = NULL;
	if (lt->len == 0) {
		lt->head = new_node;
		lt->tail = new_node;
	}
	else {
	lt->tail->next = new_node;
	lt->tail = new_node;
	}
	lt->len++;
	return 0;
}


/*
* Prints the list lt
*/
void print_list(list_simple* lt) {
	if(lt==NULL){
		printf("Error: List pointer is Null\n");
		return;
	}
	node_s* nd;
	size_t count = 0;
	if(lt->len >0){
		printf("Position \t Data\n");
		for (nd = lt->head; nd != NULL; nd = nd->next) {
			printf("%d \t %d \n",count,nd->data);
			count++;
		}
	}
	else{
		printf("The list is empty\n");
	}
}

/*
* Insert a new node in a given position
* pos = position in the list, it can be a negative values, what would mean counting the position from the end.
* The list values aftert the pos will be shifted one pos.
* new_data = the data to be inserted
* lt = the list
*/
void insert(int pos, int new_data, list_simple* lt) {
	node_s* nd, * nd_prev, * new_node;
	nd = lt->head;
	nd_prev = lt->head;
	if(lt==NULL){
		
		printf("Error: List pointer is Null\n");
		return;
	}
	if (abs(pos) > lt->len) {
		printf("Error: Out of Range \n");
		return;
	}
	else {
		if (pos < 0) {
			pos = lt->len + pos;
		}
		if (lt->len == pos)
			append(new_data, lt);
		else {
			new_node = (node_s*)malloc(sizeof(node_s));
			new_node->data = new_data;
			if (new_node == NULL) {
				//In case of no memory left
				printf(stderr, "Error: Memory allocation failed!\n");  
				return; 
			}
			for (size_t i = 0; i < pos; i++, nd = nd->next) {
				nd_prev = nd;
			}
			new_node->next = nd;
			if (pos == 0) {
				lt->head = new_node;
			}
			else {
				nd_prev->next = new_node;
			}
			lt->len++;
		}
	}
}

/*
* Get a node from a position in a list
* pos = the position of the node, it can be negative numbers, what mean the positions in backward
*/
node_s* get_fromPos(int pos, list_simple* lt) {
	if(lt==NULL){
		
		printf("Error: List pointer is Null\n");
		return;
	}
	if (pos >= lt->len || pos < -(lt->len)) {
		printf("Position exceeds list lenght");
		exit(-1);
	}
	else {
		node_s* nd = lt->header;
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
	free(get_fromPos(pos,lt));
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

/*
*  Removes the first node with the value, returns its index and repair the list returns -1 if value not found
*/
int remove(int val, list* lt) {
	node* before = lt->header;
	node* nd;
	int index = -1;
	for (nd = lt->header; nd != NULL;before = nd, nd = nd->next) {
		if (nd->value == val) {
			index = nd->index;
			break;
		}
	}
	if (index == -1) {
		return index;
	}
	if (nd->index == 0) {
		lt->header = nd->next;
	}
	else {
		before->next = nd->next;
	}
	free(nd);
	return index;
}

list* copy_list(list* ls) {
	list* cp_ls = newList();
	for (node* nd = ls->header; nd != NULL; nd = nd->next) {
		append(nd->value, cp_ls);
	}

	return cp_ls;
}


int main() {
	//for (int i = 0; i < 3000000000; i++);
	//printf("Test");
	list* lst1 = newList();
	list* lst2 = newList();
	//node* teste;
	//for (int i = 0; i < 3000000000; i++);
	//printf("\n 8 adicionado\n");
	//for (int i = 0; i < 3000000000; i++);
	//for (int i = 0; i < 10000; i++){
	//	append(i, lst1);
	//}
	//print_list(lst1);
	append(4, lst1);
	append(11, lst1);
	append(13, lst1);
	//print_list(lst1);
	append(3, lst1);
	append(11, lst1);
	lst2 = copy_list(lst1);
	printf("\n################################\n");
	print_list(lst1);
	remove(11, lst1);
	printf("\n################################\n");
	print_list(lst1);
	printf("\n################################\n");
	print_list(lst2);

	//printf("\n 3 adicionado\n");
	//for (int i = 0; i < 3000000000; i++);
	//print_list(lst1);
	//insert(2, 88, lst1);
	//printf("\n Insert 88 feito \n");
	//print_list(lst1);
	//insert(4, 4, lst1);
	//printf("\n Insert 4 feito \n");
	//print_list(lst1);
	//insert(6, 12, lst1);
	//printf("\n Insert 12 feito \n");
	//print_list(lst1);
	//teste = get_fromPos(2, lst1);
	//printf("\n Pos 2 da lista eh %d", teste->value);
	//teste = get_fromPos(-1, lst1);
	//printf("\n Pos -1 da lista eh %d", teste->value);
	//printf("\n ************* \n HEADER INDEX %d\n ************* \n",lst1->header->index);
	//teste = find(4, lst1);
	//printf("\n\n list len = %d", lst1->len);
	//if (teste != NULL) {
	//	printf("\n the first position of 4 in the list is %d", teste->index);
	//}
	
	//for (int i = 0; i < 3000000000; i++);
	//del_list(lst1);
	//print_list(lst1);
	//for (int i = 0; i < 9000000000; i++);

}