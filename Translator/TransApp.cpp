#include "BST.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <stdlib.h>
using namespace std;
/*
 * TransApp.cpp
 *
 * Description: Translation application
 *
 * Class invariant: type of data file is always string, the datafile must be sorted with accending order
 *
 * Author: Kihyun Byun
 * Date: Nov 28 2019
 */

//invariant:Data does not be changed
//time efficiency:O(n)
string* expand(string *ToBeExpanded,int &Capacity) {
	string* Temp = (string*)malloc(sizeof(string)*(Capacity));
	memcpy(Temp, ToBeExpanded, sizeof(string)*(Capacity));
	ToBeExpanded = (string*)malloc(sizeof(string)*(Capacity * 2));
	for (int i = 0; i < Capacity; i++)
	{
		ToBeExpanded[i] = Temp[i];
	}
	Capacity = Capacity * 2;
	return ToBeExpanded;
}

//poscondition: Sort data to make functions have O(logn) time efficiency in BST class
//precondition: Data must be sorted order with accending order
//invariant: Data does not be changed
//time efficiency:O(nlog2n)
void Resort(string *ToBeSorted, string *Sorted, int start, int end, int &index)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		Sorted[index] = ToBeSorted[mid];
		index++;
		Resort(ToBeSorted, Sorted, start, mid, index);
		Resort(ToBeSorted, Sorted, mid+1, end, index);
	}
}

int main(int argc,char *argv[])
{
	BST<string> *NewBST = new BST<string>();
	string pair;//data formed "A:B"
	string Tword;//translated words
	string Eword;//English words
	ifstream File;
	int Capacity = 100;
	string *array= (string*)malloc(sizeof(string)*(Capacity));
	int index;
	int swit = 1;//switch for display feature or exceptions


	File.open("dataFile.txt");
	if (File.is_open())
	{
		int count = 0;
		while (!File.eof())
		{
			File >> pair;
			if (count >= Capacity)
			{
				array=expand(array, Capacity);
				Capacity = Capacity * 2;
			}
			array[count] = pair;
			count++;
		}
		string *array2 = (string*)malloc(sizeof(string)*(count));
		Resort(array, array2, 0, count-1, index);
		array2[count - 1] = array[count - 1]; //with Resort method, the last element does not go in to the array2
		File.close();

		for (int i = 0; i < count; i++)
		{
			try {
				NewBST->insert(array2[i]);
			}
			catch (ElementAlreadyExistsInBSTException&anException) {
				cout << "insert() unsuccessful because " << anException.what() << endl;
				cout << "removed pair: " << array2[i] << endl;//show what data is removed by exception
				swit = 0;
			}
		}
	}

	if (argv[1])//display feature
	{
		string boolean = argv[1];

		if (boolean == "display")
		{
			swit = 0;
			try {
				NewBST->traverseInOrder();
			}
			catch (ElementDoesNotExistInBSTException&anException) {
				cout << "display unsuccessful because " << anException.what() << endl;
			}
		}
	}

	while (swit!=0&&cin >> Eword)//application for users
	{
		try {
			Tword = NewBST->retrieve(Eword);
			cout << Tword << endl;
		}
		catch (ElementDoesNotExistInBSTException&anException) {
			cout << "***Not Found!***" << endl;
		}

	}
}