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
};
#endif
