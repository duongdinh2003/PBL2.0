#ifndef DSLK_H
#define DSLK_H
#include "MyLib.h"
template <class T>
struct Node
{
	T data;
	Node<T>* Next;
	Node<T>* Pre;
	Node(T data);
	Node CreateNode(T);
	Node();
};
template <class T>
class List {

private:
	int size;
	Node<T>* Head;
	Node<T>* Tail;

public:
	void SetHead(Node<T> *);
	void SetTail(Node <T>*);
	List();
	~List();
	void InsertLast(T);
	T doc_file_node(const char*);
	void Show();
	void Input(const char*);
	template <class T>
	friend istream& operator >> (istream& in, Node<T>&);
	Node<T>* GetHead();
};

template <class T>
void List<T>::SetHead(Node<T> *a) {
	*Head = *a;
}

template <class T> 
void List <T> ::SetTail(Node <T>* a) {
	*Tail = *a;
}


template <class T>
Node<T>::Node(T data)
{
	this->data = data;
	this->Next = this->Pre = NULL;
}

template <class T>
Node<T>::Node()
{
	this->Next = this->Pre = NULL;
}

template <class T>
Node<T> Node<T>::CreateNode(T x)
{
	Node<T>* node = new Node<T>(x);
	node->Next = NULL;
	node->Pre = NULL;
	node->data = x;
	return *node;
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
	if (Head == NULL)
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
T List<T>::doc_file_node(const char* file)
{
	fstream filein;
	filein.open(file, ios::in);
	Node<T>* node = new Node<T>();
	getline(filein, node->data, ',');
	filein >> node->data;
	filein.seekg(2, 1);
	filein >> node->data;
	cin.ignore();
	filein.close();
	return node->data;
}

template <class T>
void List<T>::Show() {
	Node<T>* a = this->Head;
	while (a != NULL) {
		a->data.show();
		a = a->Next;
	}
}

template <class T>
void List<T>::Input(const char* filename)
{
	fstream filein;
	filein.open(filename, ios_base::in);
	Node<T> p;
	while (!filein.eof())
	{
		p.data = doc_file_node(filename);
		Node<T> node = this->Head->CreateNode(p.data);
		this->size++;
	}
	filein.close();
}

template <class T>
istream& operator >> (istream& in, Node<T>& t)
{
	cout << "Nhap data cho t: ";
	in >> t->data;
	return in;
}


template <class T>
Node<T>* List<T>::GetHead()
{
	return this->Head;
}
#endif // !DSLK.H
