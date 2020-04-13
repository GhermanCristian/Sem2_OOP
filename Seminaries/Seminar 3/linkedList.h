#pragma once
#include "list.h"

template <typename TElem>
class LinkedList : public List<TElem> {
	public:
		class Node {
			private:
				TElem info;
				Node* next;

			public:
				Node(TElem newInfo, Node* next = nullptr);
				TElem& getElement() const;
				Node* getNext();
		};

	private:
		Node* first;

	public:
		LinkedList(Node *first = nullptr);
		~LinkedList();
		//LinkedList& operator = (const LinkedList& originalList);
		// and a copy constructor

		void addToVector(const TElem& newElement);
};

template<typename TElem>
inline LinkedList<TElem>::Node::Node(TElem newInfo, Node* next){
	this->info = newInfo;
	this->next = next;
}

template<typename TElem>
inline TElem& LinkedList<TElem>::Node::getElement() const
{
	return this->getElement;
}

template<typename TElem>
inline typename LinkedList<TElem>::Node* LinkedList<TElem>::Node::getNext()
{
	return this->next;
}

template<typename TElem>
inline LinkedList<TElem>::LinkedList(Node* first){
	;
}

template<typename TElem>
inline LinkedList<TElem>::~LinkedList(){
	;
}

template<typename TElem>
inline void LinkedList<TElem>::addToVector(const TElem& newElement){
	Node* newNode = new Node{ newElement };

	if (this->first == nullptr) {

	}
}
