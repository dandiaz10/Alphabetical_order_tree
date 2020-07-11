/*******************************************************************************************
* File Name          : diaztenorio1812_Assignment2.cpp
* Description        : Prog8130 - Assignment 2: Binary tree
*					   This program uses a binary tree to hold and print strings in alphabetic order.
*					   Each input consists of maximum 30 characters.
*
* Author:              Daniela Diaz Tenorio
* Date:					July 11 2020
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Macros to know which child node (right, left or parent) is the node
#define LEFT_CHILD_NODE 0
#define RIGHT_CHILD_NODE 1
#define PARENT_NODE 2

#define STRING_SIZE 30
#define INPUT_SIZE 12

struct nodeData *head = NULL;	// head of the binary tree 

// structure defining a binary tree node.  Lower sorted values will go the the left, higher to the right.
struct nodeData {
	char name[STRING_SIZE];				// character string of the data being stored in the node
	struct nodeData *left = NULL;		// pointer to the next node in the tree that is less than current node OR NULL if empty
	struct nodeData *right = NULL;		// pointer to the next node in the tree that is greater than current node OR NULL if empty
	struct nodeData *up = NULL; //pointer to the parent node to not use recursion
	int rFlag;
};

// inputData obtained from Prog8130AssignDataCreator.exe with student code 1812
const char inputData[][STRING_SIZE] = {
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

// The correct sorted order should be:
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
//   This function stores the data in newNode into a binary tree according to alphabetical order
//		Right node greater value
//		Left node lower value
//
// PARAMETERS    :
//   newString - the string that is to be stored in the binary tree in alphabetica order
//
// RETURNS       :
//   Nothing
void addToBinaryTree(const char newString[]) {
	
	nodeData *currentNode = head;
	nodeData *newNode = NULL;
	int compare = 0;

	newNode = (nodeData*)malloc(sizeof(nodeData)); //asign memory for the new node in the heap
	strcpy_s(newNode->name, newString);    //assing the string value to the structure element name
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->up = NULL;
	
	while (currentNode != NULL) // if there is a value in current node
	{
		compare = strcmp(newNode->name, currentNode->name); //compare strings
		
		if (compare >= 0) { //newNode is grater or equal than current
			if (currentNode->right != NULL) {
				currentNode = currentNode->right;
			}
			else //newNode is less than current
			{
				currentNode->right = newNode;
				newNode->up = currentNode;
				newNode->rFlag = RIGHT_CHILD_NODE;
				currentNode = NULL;
			}

		}
		else //new node is less than current
		{
			if (currentNode->left != NULL) { //if there is a left child node
				currentNode = currentNode->left;
			}
			else // if there is no left child node
			{
				currentNode->left = newNode;
				newNode->up = currentNode; //save its parent address
				newNode->rFlag = LEFT_CHILD_NODE; //save which child node is from its parent
				currentNode = NULL;
			}
			
		}
	}
	
	if (head->name == NULL) // if head is empty assigns new node as head
	{
		head = newNode; // head points to the first element
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->up = NULL;
		newNode->rFlag = PARENT_NODE; // this node doesn't have parent node
	}
	
}

// FUNCTION      : printBinaryTree
//
// DESCRIPTION   :
//   This function prints the entire binary tree out traversing the binary tree in-order without using recursion.
//
// PARAMETERS    :
//   None
//
// RETURNS       :
//   Nothing
void printBinaryTree(void) {
	nodeData *currentNode = head;

	printf("\nBinary tree traversed in-order...\n");
	
		while (currentNode != NULL) //loop that checks if there is something in current node
		{
			if (currentNode->left != NULL) // check if there is a child left node
			{
				currentNode = currentNode->left;
			}
			else //if left node is NULL
			{
				printf("%s\n", currentNode->name);

				while (1) //loop that checks if there is a right node
				{
					if (currentNode->right != NULL)
					{
						currentNode = currentNode->right;
						break; // break the current while loop and go to check left node "loop" - GO TO line146
					}
					else //there is no right node
					{
						while (currentNode->rFlag == RIGHT_CHILD_NODE) // if current node is the right child node of its parent node
						{
							currentNode = currentNode->up;
						}
						if(currentNode->rFlag == LEFT_CHILD_NODE) // if current node is the left child node of its parent node
						{
							currentNode = currentNode->up;
							printf("%s\n", currentNode->name);
						}
						else //if current node is the head of the tree
						{
							printf("End of the tree....\n");
							return; //finish the function
						}
					}
				}
			}
			
		}
}


// FUNCTION      : main
//
// DESCRIPTION   :
//   Pull the data into the binary tree calling addToBinaryTree function
//	 Prints data in alphabetic order calling printBinaryTree
//
// PARAMETERS    :
//   None
//
// RETURNS       : 
//   Int 0

int main() {
	
	int i;

	// put all the data into the binary tree
	for (i = 0; i < INPUT_SIZE; i++)
		addToBinaryTree(inputData[i]);

	// print the entire tree.  It should come out in alphabetical order because of the way it was stored in the tree
	printBinaryTree();

	return 0;
}
