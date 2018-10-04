/*
 * file: test.cpp
 * author: Jhony Angulo
 * date: 24-09-2018
 */
#include "binarytree.hpp"
#include "./iterator/iterator.hpp"
using namespace std;
struct Number{
	typedef double T;
};


int main(){
	// Probaste tu eliminar bien? Con un árbol grande está generando un bucle infinito
	// Probaste tu iterator? Te faltó el operador !=
	// No implementaste el destructor de tu árbol
	BinaryTree<Number> p;
	p.addElement( 10);
	p.addElement( 5);
	p.addElement( 4);
	p.addElement( 7);
	p.addElement( 6);
	p.addElement( 20);
	p.addElement( 32);
	p.printInOrder();
	cout << p.weight() << "\n";
	p.deleteElement(8 );
	p.deleteElement(12 );
	p.deleteElement(10 );
	cout << p.weight() << "\n";
	p.printInOrder();
	return 0;
}
