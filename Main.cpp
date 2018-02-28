///Fin
// File/Project Prolog
// Name: Duncan Reeves
// CS 2420 Section 601
// Project: Hash Table
// Date: 10/6/2017 10:01:27 AM
//
// I declare that the following code was written by me or provided 
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive
// a zero on this project if I am found in violation of this policy.
// 
// I also state that the Standard Template Library is NOT used in this project

// I Duncan have not used any code other than my own (or that in the textbook) for this project. I also
// have not used any function or data-structure from the Standard-Template Library. I understand that any
// violation of this disclaimer will result in a 0 for the project.
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "List.h"

using namespace std;


int main()
{
	// build the list<int>
	List<int> intList;
	for (int i = 0; i < 10; i++)
	{
		intList.push_back(i);
		intList.push_front(i);
	}
	cout << "Initial List<int>" << endl;
	intList.PrintList();
	cout << endl;

	// display the list with iterators
	Iterator<int> start = intList.begin();
	Iterator<int> end = intList.end();
	cout << "Displaying List<int> with external iterators" << endl;
	while (start != end)
	{
		cout << *start << " ";
		++start;
	}
	cout << endl << endl;

	// display the list with new for-loop
	// this type of for iterating for-loop was added in c++11
	// for this to work, this list must have both begin() and end() functions
	// which return an iterator to the beginning and end of the list.
	// The returned iterators must implement the following functions:
	//		T operator*()
	//		void operator++()
	//		bool operator!=(Iterator& other)
	// Since out Iterator does, we can use this new for-loop
	// to iterate over the entire list.
	// here's a good explanation of this new for-loop:
	//	https://www.cprogramming.com/c++11/c++11-ranged-for-loop.html
	cout << "Displaying List<int> with new for-loop" << endl;
	for (auto x : intList)
	{
		cout << x << " ";
	}
	cout << endl << endl;

	// remove all 0's, 9's, and 6's
	intList.remove(0);
	intList.remove(9);
	intList.remove(6);
	cout << "Displaying List<int> without 0's, 9's, or 6's" << endl;
	for (auto x : intList)
	{
		cout << x << " ";
	}
	cout << endl << endl;

	// build the list<string>
	List<string> stringList;
	for (int i = 0; i < 3; i++)
	{
		stringList.push_back(to_string(i) + "_string");
		stringList.push_front(to_string(i) + "_string");
	}
	cout << "Initial List<string>" << endl;
	stringList.PrintList();
	cout << endl;

	// display the list with iterators
	Iterator<string> startString = stringList.begin();
	Iterator<string> endString = stringList.end();
	cout << "Displaying List<string> with external iterators" << endl;
	while (startString != endString)
	{
		cout << *startString << " ";
		++startString;
	}
	cout << endl << endl;

	// display the list with new for-loop
	cout << "Displaying List<string> with new for-loop" << endl;
	for (auto x : stringList)
	{
		cout << x << " ";
	}
	cout << endl << endl;

	// remove all "2_string"'s
	stringList.remove("2_string");
	cout << "Displaying List<string> without 2's" << endl;
	for (auto x : stringList)
	{
		cout << x << " ";
	}
	cout << endl << endl;




	getchar();
}