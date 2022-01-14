#ifndef Node_H
#define Node_H

template typename T
class Node
{
	T data;
	Node *left;
	Node *right;
	
	public:
	Node()
	{
		left = right = nullptr;
	}
	
	Node (T data)
	{
		this->data = data;
		left = right = nullptr;
	}
	
	
	
}


#endif //Node_H