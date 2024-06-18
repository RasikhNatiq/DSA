#include <iostream> 
using namespace std;

class underflow {

};
class overflow {

};
template <typename Type>
class Node
{
private:
	Type element;
	Node<Type>* next_node;
public:
	Node(Type = 0, Node<Type>* = nullptr);
	Type retrieve() const;
	Node<Type>* next() const;
	void setnext(Node<Type>* n);
};

template <typename Type>
Node<Type>::Node(Type e, Node* n) :element(e), next_node(n)
{
	// empty constructor
}
template <typename Type>
Type Node<Type>::retrieve() const {
	return element;
}
template <typename Type>
Node<Type>* Node<Type>::next() const {
	return next_node;
}
template <typename Type>
void Node<Type>::setnext(Node<Type>* n)
{
	next_node = n;
}


template <typename Type>
class List {
private:
	Node<Type>* list_head;
	Node<Type>* list_tail;
public:
	List();
	~List();

	// Accessors
	bool empty() const;
	Type front() const;  //
	Type back() const;  //
	Node<Type>* head() const; //
	Node<Type>* tail() const; //
	// Mutators
	void push_back(Type);
	void push_front(Type);
	Type pop_front();
	void Display();
};

template <typename Type>
List<Type>::List() :list_head(nullptr), list_tail(nullptr)
{
	// empty constructor
}
template <typename Type>
Node<Type>* List<Type>::head() const {
	return list_head;
}
template <typename Type>
Node<Type>* List<Type>::tail() const {
	return list_tail;
}
template <typename Type>
bool List<Type>::empty() const
{
	return (list_head == nullptr);
}
template <typename Type>
void List<Type>::push_front(Type n)
{
	Node<Type>* new_node = new Node<Type>(n, head());
	list_head = new_node;
	if (list_tail == nullptr)
	{
		list_tail = list_head;
	}
	list_tail->setnext(list_head);
}
template <typename Type>
void List<Type>::push_back(Type n)
{
	if (head() == NULL)
	{
		push_front(n);
	}
	else
	{
		Node<Type>* new_node = new Node<Type>(n);
		list_tail->setnext(new_node);
		list_tail = new_node;
	}
	list_tail->setnext(list_head);

}
template <typename Type>
Type List<Type>::front() const {
	if (empty())
	{
		//throw underflow();
		return -1;
	}
	return head()->retrieve();
}
template <typename Type>
Type List<Type>::back() const {
	if (empty())
	{
		//throw underflow();
		return -1;
	}
	return tail()->retrieve();
}
template <typename Type>
Type List<Type>::pop_front()
{
	if (empty()) {
		return -1;
	}

	Type e = front();
	Node<Type>* ptr = list_head;
	list_head = list_head->next();
	delete ptr;
	if (list_head == nullptr)
	{
		list_tail == nullptr;
	}
	return e;
}
template <typename Type>
void List<Type>::Display()
{
	for (Node<Type>* ptr1 = list_head; ptr1 != nullptr; ptr1 = ptr1->next())
	{
		cout << ptr1->retrieve() << endl;
	}
}
template <typename Type>
List<Type>::~List()
{
	while (!empty())
	{
		pop_front();
	}
}




template <typename Type>
class Queue {
private:
	List<Type> list;
public:
	~Queue();
	bool empty() const;
	Type front() const;
	void push(Type const&);
	Type pop();
	void display()
	{
		list.Display();
	}
};
template <typename Type>
Queue<Type>::~Queue() {

}
template <typename Type>
bool Queue<Type>::empty() const {
	return list.empty();
}
template <typename Type>
Type Queue<Type>::front() const {
	if (empty()) {
		throw underflow();
	}
	return list.front();
}
template <typename Type>
void Queue<Type>::push(Type const& obj) {

	list.push_back(obj);
}
template <typename Type>
Type Queue<Type>::pop() {
	if (empty()) {
		throw underflow();
	}
	return list.pop_front();
}

int main()
{
	Queue<int> q;
	q.push(34);
	q.push(33);
	q.push(22);
	q.push(76);
	q.push(32);
	q.display();

}