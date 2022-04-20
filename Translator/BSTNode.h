#pragma once
#include <string>
using namespace std;
/*
 * BSTNode.h
 *
 * Description: Node class for BST.
 *
 * Class invariant:
 *
 * Author: Kihyun Byun
 * Date: Nov 28 2019
 */
template <class ElementType>
class BSTNode {
public:
	ElementType element_key;
	ElementType element_value;
	ElementType element;
	BSTNode* left;
	BSTNode* right;

	BSTNode(ElementType NewElement)
	{
		element = NewElement;
		left = NULL;
		right = NULL;
	}
	BSTNode()
	{
		left = NULL;
		right = NULL;
	}
};