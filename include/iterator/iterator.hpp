#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <stack>
#include "../node/binarynode.hpp"
template <typename ST>
class Iterator {
	void fillStack(BinaryNode<ST>* current){
		if(current){
			currents.push(current);
			if(current->left){
				fillStack(current->left);
			}
		}
	}
protected:
	std::stack<BinaryNode<ST>* > currents;
	
public:
	Iterator(BinaryNode<ST>* current){
		fillStack(current);
	};
	Iterator<ST> operator=(Iterator<ST> other);
	Iterator<ST> operator++();
	bool empty();
	typename ST::T operator*();
};  

template <typename ST>
Iterator<ST> Iterator<ST>::operator=(Iterator<ST> other){
	currents = other.currents;
	return *this;
}

template <typename ST>
bool Iterator<ST>::empty(){
	return currents.empty();
}
template <typename ST>
typename ST::T Iterator<ST>::operator*(){
	return currents.top()->data;
}

template <typename ST>
Iterator<ST> Iterator<ST>::operator++(){
	BinaryNode<ST>* top = currents.top();
	currents.pop();
	fillStack( top->right );
	return *this;
}
#endif
