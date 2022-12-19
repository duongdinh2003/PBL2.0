/*#include "DSLK.h"
#include <iostream>
using namespace std;

template <class T>
Node<T>::Node(T data)
{
	this->data = data;
	this->Next = this->Pre = nullptr;
}

template <class T>
List<T>::List() {
	this->Head = this->Tail = NULL;
	this->size = 0;
}

template <class T>
List<T>::~List() {

}

template <class T>
void List<T>::InsertLast(T x) {
	Node<T>* node = new Node<T>(x);
	if (Head == nullptr)
	{
		this->Head = this->Tail = node;
		this->size++;
		return;
	}
	this->Tail->Next = node;
	node->Pre = this->Tail;
	this->Tail = node;
	this->size++;

}

template <class T>
void List<T>::Show() {
/*	if (this->Head == NULL) {
		throw "Danh sach rong";
	}
	while (this->Head != NULL) {
		cout << this->Head->data << " ";
		this->Head = this->Head->Next;
	//	cout << "ko";
	}
}*/