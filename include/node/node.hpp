#ifndef NODE_HPP
#define NODE_HPP
template <typename ST>
struct Node{
	typedef typename ST::T T;
	T data;
	Node(){};
	Node( T data)
		: data(data)
	{};
	virtual void killSelf()=0;
	virtual ~Node()=0;
};

template <typename ST>
Node<ST>::~Node(){
	delete this;
}

#endif
