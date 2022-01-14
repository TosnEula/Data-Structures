#include "Node.h"
#include <iostream>

#ifndef BINARYTREE_H
#define BINARYTREE_H

template <typname T>
class Tree
{
	Node<T> *root;
	int8_t compare (T data1, T data2)
	{
		if (data1<data2)
			return 1;
		else
			return -1;
	}
public:
	Tree()
	{
		root = nullptr;
	}
	
	void recursiveAdd(Node<T> *p, T data)
	{
		if(compare(p->getData(),data) == -1)
		{
			if(p->getLeft() ==nulptr)
			{
				p->setLeft(new Node<T>(data));
				return;
			}
			else
			{
				recursiveAdd(p->getLeft(), data);
			}
		}
		else
		{
			if (p->getRight() ==nulptr)
			{
				p->setRight(new Node<T>(data))
				return;
			}
			else
			{
				recursiveAdd(p->getRight(),data);
			}
		}
	}
	
	addNode(T data)
	{
		if (root == nulptr)
			root = new Node<T>(data);	
		else
		{
			Node<T> *p =root;
			recursiveAdd(p,data);
		}

		
	}
	
}


#endif //BINARYTREE_H