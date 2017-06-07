/********************************************************************************************
* Shelby Laquitara
* unit3-4Prog.cpp
*
* This program stores a list of 15 random integers from 0 to 99 in miniVector v,
* then outputs the vector, sorts the vector in decending order, then outputs the sorted vector.
*********************************************************************************************/
#include <iostream> // including the standard library for input/output
#include <vector>   // including the standard library for the vector class

#include "d_vector.h" //including the vector header file
#include "d_random.h" //including the random header file 

using namespace std;  //using the standard library

template <typename T>  //function definition for the writeMiniVector vector
void writeMiniVector(const miniVector<T>& v);

template <typename T> //function definition for the sortMiniVector vector
void sortMiniVector(miniVector<T>& v);

int main() //main method
{
	//(Ford & Topp, 2002, pg. 206-207)
	miniVector<int> v;  //declaring miniVector<int> v
	randomNumber rnd;   //declaring randomNumber rnd; used to generate a random number

	//declaring integer i, starts at 0, is less than 15 and pre-increments by 1
	for (int i = 0; i < 15; ++i)
	{
		//calling v.push_back(rnd.random(100)) to push 15 entries from 0-99 onto the vector
		v.push_back(rnd.random(100));
	}
	cout << "Original: "; //prints Original: as output
	writeMiniVector(v);   //calling the writeMiniVector to output the vector

	sortMiniVector(v);   //calling the sortMiniVector to sort the vector

	cout << "Sorted: ";  //prints Sorted: as output
	writeMiniVector(v);  //calling the vector to output the sorted vector

	system("PAUSE");     //pauses the screen to display results
	return 0;           //exit code to end the program successfully
} //end main

  //--------------------------------------------------------------------------------------

  // output miniVector v 
  //(Ford & Topp, 2002, pg. 251)
template <typename T>
void writeMiniVector(const miniVector<T>& v)
{
	for (int i = 0; i < v.size(); ++i) //iterate through the vector v
	{
		cout << v[i] << " ";  //output each element to the screen
	} //end for loop

	cout << endl; //ends line
} //end writeMiniVector

  //-------------------------------------------------------------------------------------

  // use insertion sort to place miniVector v in descending order
  // (Ford & Topp, 2002, pg. 203-205)
template <typename T>
void sortMiniVector(miniVector<T>& v)
{
	//i starts at 1, i is less than v.size and increases by one
	for (int i = 1; i < v.size(); ++i)
	{
		//j starts at i, j is greater than 0 and sorts in descending order
		for (int j = i; j > 0; --j)
		{
			// sorting the elements of vector v.
			// Locate insertion point by scanning downward 
			// as long as v[j] is greater than v[j-1]
			if (v[j] > v[j - 1])
			{
				T target = v[j];   //looking for correct position to locate target
				v[j] = v[j - 1];   //shift elements up list to make room for insertion
				v[j - 1] = target; //the location is found; insert target
			}
			else
			{
				break;
			}
		}
	}
} //end sortMiniVector

  //-----------------------------------------References---------------------------------
  // Ford, W., &Topp, W. (2002).Data Structures with C++ Using STL.New Jersey : Prentice - Hall.