#ifndef BINARYNODE_HPP
#define BINARYNODE_HPP

#include "node.hpp"

template <typename ST>
struct BinaryNode: public Node<ST>{
	typedef typename ST::T T;
	BinaryNode* left;
	BinaryNode* right;
	BinaryNode(BinaryNode* left=nullptr, BinaryNode* right=nullptr)
		: Node<ST>(), left(left), right(right)
	{};
	BinaryNode(T  data, BinaryNode* left=nullptr, BinaryNode* right=nullptr)
		:  Node<ST>(data), left(left), right(right)
	{};
	void killSelf(){
		if(left) left->killSelf();
		if(right) right->killSelf();
		delete this;
	}
};
#endif
