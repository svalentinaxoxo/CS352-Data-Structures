/********************************************************************
* Shelby Laquitara 
* stringProg.cpp
*
* This program uses strings to get input and manipulate the output.
********************************************************************/
#include <iostream> // including the standard library for input/output
#include <string>  // including the standard library for the string class (Ford & Topp, pg. 28)

using namespace std; //using the standard library

void inputData(string &myString); //function prototype for the inputData method
void outputData(string newName); //function prototype for the outputData method

int main()				   //main method
{
	string myString;	  //declaring a string called myString

	inputData(myString);  //passing myString into the inputData() method

	outputData(myString); //passing myString into the outputData() method

	cout << endl << endl; //starts a new line

	return 0;			  //exit code to end the program successfully
} // end main method

//function used to input Data: calling by reference (&)
void inputData(string &myString)
{
	//prompts user to enter their full name
	cout << "Please enter your full name in this format:\n Last, First MiddleName\n" << endl;
	getline(cin, myString);		         //Reads a line from cin into mystring to get input 

	int first, last, middle;			 // breaking the names into 3 seperate variables
	int comma, secondComma, totalLength; // other variables that will be used for error testing
	
	//(Ford & Topp, pg. 32).
	comma = myString.find(",");			    // using find() method to find the comma in string
	secondComma = myString.rfind(",");      // used to only allow one comma
	totalLength = myString.length();	    // gets the total length of the name
	first = myString.find(' ');				// finds the first space
	middle = myString.find(' ', first + 1); // finds the middle space
	last = myString.find(' ', middle + 1);	// finds the last space

	//while loop to test if data is inputted correctly and generate error message if not.
	while ((comma == -1) || (comma != secondComma) || ((secondComma + 2) >= 
		middle) || (first == 0) || (last != -1))
	{
		cout << "\n\nError: Please follow the correct format and only place a comma in-between Last and First name!! \n" << endl;
		cout << "Try again: \n\n Please enter your full name in this format:\nLast, First MiddleName\n" << endl;
        getline(cin, myString);					//Reads a line from cin into mystring to get input 

		// (Ford & Topp, pg. 32).
		comma = myString.find(",");				// using find() method to find the comma in string
		secondComma = myString.rfind(",");      // used to only allow one comma
		totalLength = myString.length();	    // gets the total length of the name
		first = myString.find(' ');				// finds the first space
		middle = myString.find(' ', first + 1); // finds the middle space
		last = myString.find(' ', middle + 1);	// finds the last space
	} //end while 

	// (Ford & Topp, pg. 32-33).
	string x = myString.substr(0, comma);	//using substr() method to generate a substring for x
	x.insert(0, " ");						// using insert() method to insert x into the string
	// using substr to extract the pieces from y
	string y = myString.substr(first + 1, (middle - first));
	// using substr to extract the pieces from z
	string z = myString.substr(middle + 1, (totalLength - middle));

	// using string concatenation to reassemble the string to overwrite the string with new value
	myString.insert(x.length() + y.length() + 1, " " + z.substr(0, 1));
	myString.erase();					// erases the old string (Ford & Topp, pg. 33)
	myString.append(y);					// appends the separated parts to new empty string y
	myString.append(z);					// appends the separated parts to new string z
	myString.append(x);					// appends the separated parts to new string x
} //end inputData() method 

void outputData(string newName)		   // method to output the data: calling by value
{
	cout << "\n Thank you, your name is:" << endl << endl;

	cout << newName << endl << endl;   // outputting the new string to the screen using cout 

	system("PAUSE");                   // pauses the screen to display results
} //end outputData() method

//                                     References -
//Ford, W., &Topp, W. (2002).Data Structures with C++ Using STL.New Jersey : Prentice - Hall.