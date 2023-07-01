#include<stdio.h>

/*
* A simple list that each node stores a int value, so I dont have to figure how to implement this shit, 
* and open  "C completo e total" book each time I need a list in C ANSI.
* Author: Frederico Möller
* Date: 2023 - Jul - 01
*/ 
typedef struct list_node {
	int index;
	int value;
	list_node *next;
};

