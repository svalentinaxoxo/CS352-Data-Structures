/********************************************************************************************
* Shelby Laquitara
* unit5-6Prog.cpp
*
* This program inserts and sort data into a list, 
* then removes each name one at a time and displays them to the screen.
*********************************************************************************************/
#include <iostream>     //including the standard library for input/output
#include <string>       //including the standard library for the string class

using namespace std;    //using the standard library

//(Allain, 2011)
struct AddressNode     //creating a structure called AddressNode
{
	string name;       //declaring a string for name
	AddressNode* next; //declaring a pointer called AddressNode that points to the next element
};//end struct Addressnode

//------------------------------------------------------------------------------- ABook
//creating a class called ABook
class ABook 
{
public:
	ABook() //default constructor
	{
		topPtr = NULL;                           //creates an empty list
	}
	//Abook Methods
	ABook(string newname, AddressNode* topPtr); //1. method for default constructor 
	void Insert(string NewItem);			    //2. Add item to the Linked List
	void SortedInsert(string NewItem);		    //3. Add item to the Linked List (sorted)
	void Remove(string& item);	//4. Removes the element from the top of the stack and then returns the item
	~ABook();				   //5. Destructor. Removes all elements from the list.

private:                       
	AddressNode* topPtr;       //pointer to the top of the list

}; //end class ABook

//------------------------------------------------------------------------------- Abook::ABook
//method for default Constructor
ABook::ABook(string newname, AddressNode* topPtr = 0)
{
	topPtr = NULL; //creates an empty list
} //end ABook Default Constructor 

//------------------------------------------------------------------------------- ABook::Insert
//method for adding item to the Linked List
//(Ford & Topp, pg. 445 - 446)
void ABook::Insert(string NewItem)
{
	//add items to linked list
	AddressNode* newNode = new AddressNode;		//creates a new item
	newNode->name = NewItem;					//give the new item data
	newNode->next = topPtr;						//points to next link
	topPtr = newNode;							//topPtr is now newNode
}//end ABook::Insert Method

//------------------------------------------------------------------------------- ABook::SortedInsert
//method for adding sorted item to the Linked List
//(Ford & Topp, pg. 442-446, 469)
void ABook::SortedInsert(string NewItem)
{
	AddressNode* curr;                            //pointer to the current node
	AddressNode* newNode = new AddressNode;       //pointer to new Node assigned to new addressNode 
	newNode->name = NewItem;                      //give the new item data

	if (topPtr == NULL || topPtr->name.compare(NewItem) >= 0)
	{
		newNode->next = topPtr;                   //points to next node
		topPtr = newNode;                         //topPtr is now newNode
	} //end if statement
	else
	{
		curr = topPtr;                            //sets curr to topPtr

		while (curr->next != NULL && curr->next->name.compare(NewItem)<0)
		{
			curr = curr->next;                   //advance curr node
		} //end while loop
		newNode->next = curr->next;              //step 1: adding nodes
		curr->next = newNode;                    //step 2: update curr to point at newNode
	} //end else
}//end ABook::SortedInsert Method

//-------------------------------------------------------------------------------- ABook::Remove
//method for removing element from the top of the stack and returning the item
//(Ford & Topp, pg. 447)
void ABook::Remove(string& item)
{
	if (topPtr != NULL)        //if topPtr is empty
	{
		item = topPtr->name;
		topPtr = topPtr->next;
	} //end if statement
} //end ABook::Remove Method

//--------------------------------------------------------------------------------- ABook::~ABook
//method for Destructor which removes all elements from the list
//(Unit 6 Lecture - Linked List (pg. 3)
ABook::~ABook() 
{
	while (topPtr != NULL)      //if topPtr is empty
	{
		AddressNode *newNode = topPtr->next;
		delete newNode;         //delete all elements in the last node 
		newNode = topPtr;       //newNode is now topPtr
	} //end while loop
} //end ABook destructor

//--------------------------------------------------------------------------------- main
//Main Method
int main() 
{
	ABook Book;					    //1. Declaring a new List
	string newName;				    //2. Declaring a string called newName
	string nameToRemove;		    //3. Declaring a string called nameToRemove

	Book.Insert("Precious");		//4.  Insert Precious into list.
	Book.SortedInsert("Ken");		//5.  Insert Ken into listed (sorted)
	Book.SortedInsert("Eileen");	//6.  Insert Eileen into list (sorted)
	Book.SortedInsert("Frank");		//7.  Insert Frank into list (sorted)

	cout << "Sorted List: " << endl; //prints Sorted List: as output 

	for (int i = 0; i < 4; i++)      //for loop to remove names one at a time
	{
		//8. using Book.Remove to remove each name, one at a time
		Book.Remove(nameToRemove);
		cout << nameToRemove << endl; //displays names to screen as output 
	} //end for loop

	system("PAUSE");                  //9. pauses the screen to display results
	return 0;		                  //exit code to end the program successfully
}//end main method

//----------------------------------References-----------------------------------------------
/*Allain, A. (2011). Lesson 15: Singly linked lists in C++. 
	Retrieved from CProgramming.com: http://www.cprogramming.com/tutorial/lesson15.html */
//Ford, W., & Topp, W. (2002). Data Structures with C++ Using STL. New Jersey: Prentice - Hall.
//Unit 6 Lecutre Notes - Linked List 