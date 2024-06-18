#include <iostream>
#include <stack>
using namespace std;

class underflow
{

};

class overflow
{

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
    void push_front(Type);
    void push_back(Type);
    Type pop_front();
};
template <typename Type>
List<Type>::List() :list_head(nullptr), list_tail(nullptr)
{
    // empty constructor
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
    void reverseQueue(Queue<int>& Queue);
};

template <typename Type>
Queue<Type>::~Queue()
{
    while (empty() != 1)
    {
        list.pop_front();
    }
}


template <typename Type>
Type Queue<Type>::front() const {
    if (empty()) {
        throw underflow();
    }
    return list.front();
}

template <typename Type>
Type Queue<Type>::pop() {
    if (empty()) {
        throw underflow();
    }
    return list.pop_front();
}



template <typename Type>
bool Queue<Type>::empty() const {
    return list.empty();
}

template <typename Type>
void Queue<Type>::push(Type const& obj) {
    list.push_back(obj);
}

template <typename Type>
void Queue<Type>::reverseQueue(Queue<int>& Q)
{
    stack<int> Stack;
    while (!Q.empty()) {
        Stack.push(Q.front());
        Q.pop();

    }
    while (!Stack.empty()) {
        Q.push(Stack.top());
        Stack.pop();
        while (!Q.empty()) {
            cout << "\nReverse: " << Q.front() << "  ";
            Q.pop();
        }
    }
}

int main()
{
    Queue<int> Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);
    Q.push(40);
    Q.push(50);
    Q.push(60);
    Q.push(70);
    Q.push(80);
    Q.push(90);
    Q.push(100);
    Q.reverseQueue(Q);
    return 0;
}