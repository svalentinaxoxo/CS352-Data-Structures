/*****************************************************************************************************
* Shelby Laquitara
* unit7Prog.cpp
*
* This program implements a Binary Search Tree that will accept integers: 35, 18, 48, 72, 60, and 25.
* It asks user for input and search tree utilizes integer input, returns true if integer is found in tree,
* and returns false is integer is not found in tree.
*****************************************************************************************************/
#include <iostream> //including the standard library for input/output

using namespace std; //using the standard library 

struct tree_node //creating a structure, defined as tree_node to implement the binary tree
{
	int data;                  //declaring an variable of type integer called data 
	tree_node *leftChild;	   //left subtree
	tree_node *rightChild;     //right subtree
}; //end struct tree_node

//-------------------------------------------------------------------------------- prototypes
tree_node *insert(tree_node *root, int key); //insert method
bool search(tree_node *tree, int key);       //search method

//-------------------------------------------------------------------------------- main
//(Ford & Topp)
int main()
{
	int arr[] = { 35, 18, 48, 72, 60, 25 };	//decalaring an array with inital values of 35,18,48,72,60,25
	int number;								//declaring a variable called number of type integer 
	tree_node *tree = NULL;		 //tree node pointing to tree is set to empty
	tree = insert(tree, 35);	 //using the insert method to enter the number 35 into the tree
	tree = insert(tree, 18);	 //using the insert method to enter the number 18 into the tree
	tree = insert(tree, 48);	 //using the insert method to enter the number 48 into the tree
	tree = insert(tree, 72);	 //using the insert method to enter the number 72 into the tree
	tree = insert(tree, 60);	 //using the insert method to enter the number 60 into the tree
	tree = insert(tree, 25);	 //using the insert method to enter the number 25 into the tree

	cout << "Enter Integer to search for : ";	//prompts user to enter a integer for search for 
	cin >> number;								//store the number entered as a variable called number

	if (search(tree, number))					//if number if found in tree, print true
		cout << "True" << endl;
	else
		cout << "False" << endl;				//else print false 

	cout << "Enter Integer to search for : ";	//prompts user to enter a integer for search for 
	cin >> number;								//store the number entered as a variable called number

	if (search(tree, number))					//if number if found in tree, print true
		cout << "True" << endl;
	else
		cout << "False" << endl;				//else print false 
	system("pause");							//pauses the screen to display results
	return 0;									//exit code to end the program successfully
} //end main

//-------------------------------------------------------------------------------- tree_node *insert
//(Ford & Topp)
tree_node *insert(tree_node *root, int key)
{
	int n;								 //declaring variable n of type int

	tree_node *tempNode = new tree_node; //tree node pointer to tempNode and allocate a new tree node 
	tree_node *current = root;           //tree node pointer to current and set to root
	tree_node *parent;                   //tree node pointer to parent

	tempNode->data = key;                //insert tempNode as Data and set it as the key 
	tempNode->leftChild = NULL;          //insert tempNode as left child and set it as empty 
	tempNode->rightChild = NULL;         //insert tempNode as right child and set it as empty

	//if tree is empty, create tempNode
	if (root == NULL)
		return tempNode;
	while (1)
	{
		parent = current; //update the parent pointer than go to the left or the right

		//go to the left of the tree
		if (key<current->data)
		{
			if (current->leftChild != NULL)
				current = current->leftChild;
			else
			{
				n = 1;
				break;
			}
		} //end if
		else
		{
			//go to the right of the tree
			if (current->rightChild != NULL)
				current = current->rightChild;
			else
			{
				n = 2;
				break;
			}
		}
	} //end while loop

	if (n == 1)
	{
		current->leftChild = tempNode; //insert to the left 
	} //end if 
	else
	{	 
		current->rightChild = tempNode; //insert to the right
	} //end else
	return root;
} //end insert 

//-------------------------------------------------------------------------------- bool search
//(Allain, 2001)
bool search(tree_node *tree, int key)
{
	while (tree != NULL)             //tree is not empty
	{
		if (tree->data == key)       //if number if found in tree, return true
			return true;
		else if (tree->data>key) 
			tree = tree->leftChild; //else go to left tree
		else
			tree = tree->rightChild; //else go to right tree
	}
	return false; //not found in tree, return false
} //end search

//----------------------------------References-----------------------------------------------
/*Allain, A. (2011). Binary Trees in C++: Part 1.
Retrieved from CProgramming.com: http://www.cprogramming.com/tutorial/lesson18.html */
//Ford, W., & Topp, W. (2002). Data Structures with C++ Using STL. New Jersey: Prentice - Hall.