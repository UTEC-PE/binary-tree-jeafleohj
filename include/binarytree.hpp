
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>

#include "node/binarynode.hpp"

template <typename ST>
class BinaryTree{
	typedef typename ST::T T;
	BinaryNode<ST>* root;

	void printInOrder(const BinaryNode<ST>* head){
		if(head != nullptr){
			if( root->left )
				printInOrder(head->left);
			std::cout << head->data << " ";
			if( root->right )
				printInOrder(head->right);
		}
	}

	void printPreOrder(const BinaryNode<ST>* head){
		if(head){
			std::cout << head->data << " ";
			if( head->left )
				printPreOrder(head->left);
			if( head->right )
				printPreOrder(head->right);
		}		
	}
	void printPostOrder(const BinaryNode<ST>* head){
		if(head){
			if( head->left )
				printPostOrder(head->left);
			if( head->right )
				printPostOrder(head->right);
			std::cout << head->data << " ";
		}		
	}
	
public:
	BinaryTree()
		: root()
	{};
	void addElement(T value){
		if( root == nullptr ){
			root = new BinaryNode<ST>(value);

		}else{
			BinaryNode<ST>* it = root;
			BinaryNode<ST>* pos = nullptr;
			while(it){
				pos = it;
				if( it->data > value){
					it = it->left;
				}else{
					it = it->right;
				}
			}
			if( value < pos->data ){
				pos->left = new BinaryNode<ST>(value);
			}else{
				pos->right = new BinaryNode<ST>(value);
			}
		}
	}
	void printInOrder(){
		printInOrder(root);
		std::cout << "\n";
	}
	void printPreOrder(){
		printPreOrder(root);
		std::cout << "\n";
	}
	void printPostOrder(){
		printPostOrder(root);
		std::cout << "\n";
	}
};

#endif
