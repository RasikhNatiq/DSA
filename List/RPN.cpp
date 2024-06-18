#include <iostream>
using namespace std;
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
	Node<Type>* head() const; //
	// Mutators
	void push_front(Type);
	Type pop_front();
};
template <typename Type>
List<Type>::List() :list_head(nullptr), list_tail(nullptr)
{
	// empty constructor
}

template <typename Type>
bool List<Type>::empty() const
{
	return (list_head == nullptr);
}


template <typename Type>
Node<Type>* List<Type>::head() const {
	return list_head;
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
		list_tail = nullptr;
	}
	return e;
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
class stack
{
	List<Type> lis;
public:
	bool empty() const;
	Type top() const;
	void push(Type const&);
	Type pop();
};

template <typename Type>
bool stack<Type>::empty() const
{
	return lis.empty();
}
template <typename Type>
void stack<Type>::push(Type const& obj)
{
	lis.push_front(obj);
}
template <typename Type>
Type stack<Type>::pop()
{
	if (empty())
	{
		cout << "\nEMPTY\n";
	}
	else
	{
		return lis.pop_front();
	}
}
template <typename Type>
Type stack<Type>::top() const
{
	if (empty())
	{
		cout << "\nEMPTY\n";
	}
	else
	{
		return lis.front();
	}
}
int priority(char ch)
{
	if (ch == '/' || ch == '*')
	{
		return 2;
	}
	else if (ch == '+' || ch == '-')
	{
		return 1;
	}
}

int main()
{

	stack <char> stk;
	string str;
	cout << "Enter The Expression : ";
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if ((int)str[i] > 47 && (int)str[i] < 58)
		{
			cout << str[i];
		}

		else if (str[i] == '(')
		{
			stk.push(str[i]);
		}

		else if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')
		{
			step4:
			if (stk.empty())
			{
				stk.push(str[i]);
			}
			else if (stk.top() == '(')
			{
				stk.push(str[i]);
			}
			else if (priority(str[i]) > priority(stk.top()))
			{
				stk.push(str[i]);
			}
			else
			{
				cout << stk.pop();
				goto step4;
			}
		}

		else if (str[i] == ')')
		{
			while (!stk.empty())
			{
				if (stk.top() != '(')
				{
					cout << stk.pop();
				}

				else if (stk.top() == '(')
				{
					stk.pop();
					break;
				}
			}
		}
	}

	while (!stk.empty())
	{
		cout << stk.pop();
	}
	return 0;
}