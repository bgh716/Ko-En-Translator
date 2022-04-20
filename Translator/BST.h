#pragma once
#include <string>
using namespace std;
#include "ElementAlreadyExistsInBSTException.h"
#include "ElementDoesNotExistInBSTException.h"
#include <iostream>
/*
 * BST.h
 *
 * Description: Data collection Binary Search Tree ADT class.
 *              Link-based implementation.
 *
 * Class invariant: It is always a BST and takes data(element) always string with "A:B" form.(if not change the Findkey and FindValue functions).
 *
 * Author: Kihyun Byun
 * Date: Nov 28 2019
 */

 // Put your code here! 

#include "BSTNode.h"



template <class ElementType>
class BST {

private:

	BSTNode<ElementType>* root;
	int ElementCount;

	// Put your code here!

	//time efficiency: O(n)
	void removeAllR(BSTNode<ElementType>* current)
	{
		if (current != NULL)
		{
			if (current->left != NULL)
			{
				removeAllR(current->left);
			}
			if (current->right != NULL)
			{
				removeAllR(current->right);
			}
			delete current;
			current = NULL;
		}
	}

	//precondition:data must be string and "A:B" formed
	//time efficiency:O(1)
	string findKey(const string& element)
	{
		int count = 0;
		char c = element[count];
		while (c != ':')
		{
			count++;
			c = element[count];
		}
		return element.substr(0,count);
	}

	//precondition:data must be string and "A:B" formed
	//time efficiency:O(1)
	string findValue(const string& element)
	{
		int count = 0;
		char c = element[count];
		while (c != ':')
		{
			count++;
			c = element[count];
		}
		return element.substr(count + 1);
	}

	// Utility methods
	//precondition:data must be string and "A:B" formed
	//invariant:duplication is not allowed
	//time efficiency:O(log2n)
	bool insertR(const ElementType& element, BSTNode<ElementType>* current)
	{
		ElementType key = findKey(element);
		ElementType value = findValue(element);
		bool result;
		if (ElementCount == 0)
		{
			root->element = element;
			root->element_key = key;
			root->element_value = value;
			result = true;
			return result;
		}

		if (current->element_key == key)
		{
			result = false;
			return result;
		}
		else if (current->left== NULL&& current->element_key > key)
		{
			current->left = new BSTNode<ElementType>(element);
			current->left->element_key = key;
			current->left->element_value = value;
			result = true;
			return result;
		}
		else if (current->right == NULL && current->element_key < element)
		{
			current->right = new BSTNode<ElementType>(element);
			current->right->element_key = key;
			current->right->element_value = value;
			result = true;
			return result;
		}
		else
		{
			if (current->element_key > key)
				result = insertR(element, current->left);
			else if (current->element_key < key)
				result = insertR(element, current->right);
		}
		return result;
	}

	//precondition:Node must have key and values
	//time efficiency:O(log2n)
	ElementType& retrieveR(const ElementType& targetElement, BSTNode<ElementType>* current) const throw(ElementDoesNotExistInBSTException)
	{
		if (ElementCount == 0)
			throw ElementDoesNotExistInBSTException("Element does not exist in the BST");


		if (current->element_key == targetElement)
		{
			return current->element;
		}
		else if (current->left == NULL && current->right == NULL)
		{
			throw ElementDoesNotExistInBSTException("Element does not exist in the BST");
		}
		else
		{
			if (current->element_key > targetElement&&current->left != NULL)
				return retrieveR(targetElement, current->left);
			else if (current->element_key < targetElement&&current->right != NULL)
				return retrieveR(targetElement, current->right);
			else
				throw ElementDoesNotExistInBSTException("Element does not exist in the BST");
		}
	}

	//time efficiency:O(n)
	void traverseInOrderR(BSTNode<ElementType>* current) const
	{
		if (current != NULL)
		{

			if (current->left != NULL)
			{
				traverseInOrderR(current->left);
			}
			cout << current->element << endl;
			if (current->right != NULL)
			{
				traverseInOrderR(current->right);
			}
		}

	}


public:
	// Constructors and destructor:
	BST(){
		root = new BSTNode<ElementType>();
		ElementCount = 0;
		root->left = NULL;
		root->right = NULL;
	}                               // Default constructor
	BST(ElementType& element) {
		root = new BSTNode<ElementType>(element);
		ElementCount = 1;
		root->left = NULL;
		root->right = NULL;
	}// Parameterized constructor 
	BST(const BST<ElementType>& aBST) {
		root = aBST->root;
		ElementCount = aBST->ElementCount;
	}// Copy constructor 
	~BST() {
		removeAllR(root);
		ElementCount = 0;
	}// Destructor 

	// BST operations:

	// Time efficiency: O(1)
	int getElementCount() const {
		return ElementCount;
	}

	// Time efficiency: O(log2 n)
	void insert(const ElementType& newElement) throw(ElementAlreadyExistsInBSTException) {
		bool Check = insertR(newElement, root);
		if (Check)
		{
			ElementCount++;
		}
		else
			throw ElementAlreadyExistsInBSTException("Element already exists in the BST");
	}

	// Time efficiency: O(log2 n)
	ElementType& retrieve(const ElementType& targetElement) throw(ElementDoesNotExistInBSTException) {
		try {
			ElementType& result = retrieveR(targetElement, root);
			return result;
		}
		catch (ElementDoesNotExistInBSTException&anException) {
			throw ElementDoesNotExistInBSTException("Element does not exist in the BST");
		}

	}

	// Time efficiency: O(n)
	void traverseInOrder() const throw(ElementDoesNotExistInBSTException)
	{
		if(ElementCount==0)
			throw ElementDoesNotExistInBSTException("Element does not exist in the BST");
		else
			traverseInOrderR(root);
	}

};