/*******************************************************************************
* Shelby Laquitara
* unit2Prog.cpp
*
* This program uses a recursive function that will 
* recieve and return a sum of integers.
********************************************************************************/
#include <iostream> // including the standard library for input/output
#include <string>  // including the standard library for the string class (Ford & Topp, pg. 28)

using namespace std; //using the standard library

int sumDigits(int *integer); //function definition for the sumDigits() method

int main() //main function
{
	//creating a variable called userInput that holds an integer value
	int userInput;
	//creating a variable for the received Input
	int receivedInput;
	//asking for input for non-negative integers
	cout << "Enter a non-negative integer: "; 
	//gets input using cin >>
	cin >> userInput; 
	//using pass-by-refernce to pass integer received into the sumDigits() function
	receivedInput = sumDigits(&userInput);
	//outputs the result to the screen
	cout << "The sum of the digits of " << userInput << " is " << receivedInput << endl;
	system("PAUSE");  // pauses the screen to display results
	return 0;         //exit code to end the program successfully
} //end main() function 

//-------------------------------------------------------------------------------------

//function called sumDigits that receives a pointer to an integer
int sumDigits(int *integer) 
{
	//(Ford & Topp, pg. 149)
	//declaring variables x and y and setting them equal to *integer
	int x, y = *integer;

	//if statement to check if y divied by 10 is equivalent to 0
	if (y / 10 == 0) 
		return y;
	else             //if y is two or more digits long (recursive subtask)
	{
		x = y % 10; 
		y = y / 10;
		return x + sumDigits(&y); //recursive statement calling itself
    }
} // end sumDigits() function

//-----------------------------------------References---------------------------------
// Ford, W., &Topp, W. (2002).Data Structures with C++ Using STL.New Jersey : Prentice - Hall.