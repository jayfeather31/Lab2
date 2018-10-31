// ListProcessor.cpp
// Spencer Romberg
// COSC 2030, Fall Semester
// 9/24/18
// Exercise the List class with verbose Node constructor
//   and destructor.

#include "LinkedList.h"


int main()
{
	List cows;
	cout << "cows list  :  " << cows << endl << endl;

	cows.insertAsFirst(1.23);
	cows.insertAsFirst(2.34);
	cout << "cows list  :  " << cows << endl;     
	cout << "cows in list : " << cows.size() << endl;                   //shows how long the list is
	cout << "sum of cows in list : " << cows.sum() << endl << endl;     //adds the sum of cows

	cows.removeFirst();
	cout << "cows list  :  " << cows << endl;
	cout << "cows in list : " << cows.size() << endl;
	cout << "sum of cows in list : " << cows.sum() << endl << endl;

	List horses(cows);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl << endl;

	horses.removeFirst();
	horses.insertAsFirst(5.67);
	cows.insertAsFirst(6.78);
	cows.insertAsLast(2.2);                                             //sets the last part of cows as 2.2
	cout << "cows list  :  " << cows << endl;
	cout << "cows in list : " << cows.size() << endl;
	cout << "sum of cows in list : " << cows.sum() << endl;
	cout << "horses list:  " << horses << endl << endl << endl;

	List pigs;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	pigs = cows;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	pigs = horses;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	cout << "End of code" << endl;

	system("pause");
	return 0;
}

