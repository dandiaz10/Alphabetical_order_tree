//Assignment 2 Daniela Diaz
//now the binary tree can be created
//we are mising the traverse part to print the tree in order
//I will create a different branch to work on the print part
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodeData *head = NULL;	// head of the binary tree

// structure defining a binary tree node.  Lower sorted values will go the the left, higher to the right.
struct nodeData {
	char name[30];				// character string of the data being stored in the node
	struct nodeData *left = NULL;		// pointer to the next node in the tree that is less than current node OR NULL if empty
	struct nodeData *right = NULL;		// pointer to the next node in the tree that is greater than current node OR NULL if empty
	struct nodeData *up = NULL; //pointer to the higher level node to not use recursion
	int rFlag;
};

// inputData obtained from Prog8130AssignDataCreator.exe with student code 1812
const char inputData[][30] = {
		{ "eomsq"},
		{ "mjcjx"},
		{ "yhgyu"},
		{ "ggqih"},
		{ "waxrb"},
		{ "oedwf"},
		{ "aujtx"},
		{ "kjxof"},
		{ "bngua"},
		{ "gjymo"},
		{ "bonyd"},
		{ "gacli"}
};

// The correct sorted order using a binary tree is:
//      aujtx
//      bngua
//      bonyd
//      eomsq
//      gacli
//      ggqih
//      gjymo
//      kjxof
//      mjcjx
//      oedwf
//      waxrb
//      yhgyu


// FUNCTION      : addToBinaryTree
//
// DESCRIPTION   :
//   This function will store the data in newNode into a binary tree according to alphabetical order
//
// PARAMETERS    :
//   newString - the string that is to be stored in the binary tree in alphabetica order
//
// RETURNS       :
//   Nothing
void addToBinaryTree(const char newString[]) {
	// add code to put items into binary tree in alphabetical order here
	// consider using strcmp library function to decide if a name is greater or less than
	printf("\nHead is %s \n", head->name);
	nodeData *currentNode = NULL;
	nodeData *newNode = NULL;
	int compare = 0;

	currentNode = head;
	newNode = (nodeData*)malloc(sizeof(nodeData));
	strcpy_s(newNode->name, newString);    //assing the string value to the structure element
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->up = NULL;
	
	printf("newstring is %s \n", newNode->name);
	

	while (currentNode != NULL)
	{
		printf("current string is %s \n", currentNode->name);
		printf("upper node is %s \n", currentNode->up);
		compare = strcmp(newNode->name, currentNode->name);
		
		if (compare >= 0) { //newNode is grater or equal than current
			if (currentNode->right != NULL) {
				currentNode = currentNode->right;
			}
			else //newNode is less than current
			{
				printf("added to right.................\n");
				currentNode->right = newNode;
				newNode->up = currentNode;
				newNode->rFlag = 1;
				currentNode = NULL;
			}

		}
		else
		{
			if (currentNode->left != NULL) {
				currentNode = currentNode->left;
			}
			else
			{
				printf("added to left.................\n");
				currentNode->left = newNode;
				newNode->up = currentNode;
				newNode->rFlag = 0;
				currentNode = NULL;
			}
			
		}
	}
	
	if (head->name == NULL) 
	{
		head = newNode; // head points to the first element
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->up = NULL;
	}
	
}

// FUNCTION      : printBinaryTree
//
// DESCRIPTION   :
//   This function will print the entire binary tree out.  You can choose to print
//   it using recursion but more marks will be awarded if you do it non recursively.
//
// PARAMETERS    :
//   None
//
// RETURNS       :
//   Nothing
void printBinaryTree(void) {
	// add code to print data in order starting at the "head" pointer



}



int main() {
	

	int i;

	// put all the data into the binary tree
	for (i = 0; i < 12; i++)
		addToBinaryTree(inputData[i]);

	// print the entire tree.  It should come out in alphabetical order because of the way it was stored in the tree
	printBinaryTree();

	return 0;
}
