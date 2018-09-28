#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>

#include "node/binarynode.hpp"
#include "iterator/iterator.hpp"

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

	int weight(const BinaryNode<ST>* current){
		if( current ){
			return  1 + weight(current->left) + weight(current->right);
		}
		return 0;
	}

	T minimun(BinaryNode<ST>* current, BinaryNode<ST> **&position){
		position = &current;
		while((*position)->left){
			position = &((*position)->left);
		}
		return (*position)->data;
	}

	T maximun(BinaryNode<ST>* current, BinaryNode<ST> **&position){
		position = &current;
		while((*position)->right){
			position = &((*position)->right);
		}
		return (*position)->data;
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

	bool deleteElement(T value){
		BinaryNode<ST>** pos;
		if( find(value, pos)){
			BinaryNode<ST> **m, *tmp;
			if( (*pos)->right ){
				tmp = (*pos);
				minimun( (*pos)->right, m);
				(*pos)->data = (*m)->data;
				if( (*pos)->right == (*m)){
					(*pos) = (*m);
					(*pos)->left = tmp->left;
				}
				delete (*m);
				(*m) = nullptr;
			}else if( (*pos)->left ){
				tmp = (*pos);
				maximun( (*pos)->left, m);
				(*pos)->data = (*m)->data;
				if( (*pos)->left == (*m)){
					(*pos) = (*m);
					(*pos)->left = tmp->left;
				}
				delete tmp;
				(*m) = nullptr;
			}else{
				delete (*pos);
				(*pos) = nullptr;
			}
			return true;
		}
		return false;
	}
	
	bool find(T value, BinaryNode<ST>** &position){
		position = &root;
		while( (*position)  ){
			if( (*position)->data == value){
				return true;
			}
			else if( (*position)->data > value  ){
				position = &(*position)->left;
			}
			else{
				position = &(*position)->right;
			}
		}
		return false;
	}
	
	int weight(){
		return weight(root);
	}
	//iterator inorder
	//Altura Del Arbol
	void printInOrder(){
		Iterator<ST> i = begin();
		for( ; !i.empty() ;++i){
			std::cout << (*i) << " ";
		}
		//printInOrder(root);
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

	Iterator<ST> begin(){
		Iterator<ST> b(root);
		return b;
	}

	Iterator<ST> end(){
		Iterator<ST> e(nullptr);
		return e;
	}
};

#endif
