#include <iostream>
using namespace std;
class underflow
{
    //emtpy
};
template <typename Type>
class Node
{
private:
    Type element;
    Node<Type>* next_node;
public:
    Node(Type const& = Type(), Node<Type>* = NULL);
    Type retrieve() const;
    Node<Type>* next() const;
    void setnext(Node<Type>* n);
};

template <typename Type>
Node<Type>::Node(Type const& e, Node* n) :element(e), next_node(n)
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
    int size() const;
    int count(Type const&) const;
    int erase(Type const&);
    Node<Type>* head() const; //
    Node<Type>* tail() const; //
    // Mutators
    void push_front(Type);
    void push_back(Type);
    Type pop_front();

    void display();
};

template <typename Type>
void List<Type>::display()
{
    cout << "\nElements : ";
    for (Node<Type>* ptr = head(); ptr != NULL; ptr = ptr->next()) {
        cout << "\t" << ptr->retrieve();
    }
    cout << "\n";

    cout << "\nHead : " << head();
    cout << "\n";
    cout << "\nElements : ";
    for (Node<Type>* ptr = head(); ptr != NULL; ptr = ptr->next()) {
        cout << "\t" << ptr->next();
    }
    cout << "\n\n";
}


template <typename Type>
List<Type>::List() :list_head(NULL), list_tail(NULL)
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
    return (list_head == NULL);
}

template <typename Type>
void List<Type>::push_front(Type n)
{
    Node<Type>* new_node = new Node<Type>(n, head());
    list_head = new_node;
    if (list_tail == NULL)
    {
        list_tail = list_head;
    }
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
        throw underflow();
    }
    return head()->retrieve();
}
template <typename Type>
Type List<Type>::back() const {
    if (empty())
    {
        throw underflow();
    }
    return tail()->retrieve();
}
template <typename Type>
Type List<Type>::pop_front()
{
    if (empty())
    {
        throw underflow();
    }

    Type e = front();
    Node<Type>* ptr = list_head;
    list_head = list_head->next();
    delete ptr;
    if (list_head == NULL)
    {
        list_tail = NULL;
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
int List<Type>::size() const
{
    int node_count = 0;
    for (Node<Type>* ptr = head(); ptr != NULL; ptr = ptr->next()) {
        node_count++;
    }
    return node_count;
}
template <typename Type>
int List<Type>::count(Type const& n) const
{
    int node_count = 0;
    for (Node<Type>* ptr = head(); ptr != NULL; ptr = ptr->next()) {
        if (ptr->retrieve() == n) {
            ++node_count;
        }
    }
    return node_count;
}
template <typename Type>
int List<Type>::erase(Type const& n)
{
    int node_count = 0;
    if (front() == n)
    {
        pop_front();
        node_count++;
    }
    Node<Type>* previous = head();
    for (Node<Type>* ptr = head(); ptr != NULL; ptr = ptr->next())
    {
        if (ptr->retrieve() == n)
        {
            previous->setnext(ptr->next());
            node_count++;
        }
        previous = ptr;
    }
    //    if(back()==n)
    //    {
    //       // list_tail=previous;
    //       //cout<<previous->retrieve();
    //    }
    return node_count;
}



template <typename Type>
class Queue {
private:
    List<Type> list;
public:
    bool empty() const;
    Type front() const;
    void push(Type const&);
    Type pop();
};
template <typename Type>
bool Queue<Type>::empty() const
{
    return list.empty();
}
template <typename Type>
Type Queue<Type>::front() const
{
    if (empty())
    {
        cout << "\nQueue is empty";
        return -1;
    }
    return list.front();
}
template <typename Type>
void Queue<Type>::push(Type const& obj)
{
    list.push_back(obj);
}
template <typename Type>
Type Queue<Type>::pop()
{
    if (empty())
    {
        cout << "\nQueue is empty";
    }
    return list.pop_front();
}

template <typename Type>
class Simple_tree
{
private:
    Type element;
    Simple_tree* parent_node;
    List<Simple_tree*> children;
public:
    Simple_tree(Type const& = Type(), Simple_tree* = NULL);
    void depth_first_traversel() const;
    void breath_first_traversel() const;
    Type retrieve() const;
    Simple_tree* parent() const;
    Simple_tree* child(int n) const;
    int degree() const;
    bool is_root() const;
    bool is_leaf() const;
    int size() const;
    int height() const;
    void insert(Type const&);
    void attach(Simple_tree*);
    void detach();
};
template <typename Type>
Simple_tree<Type>::Simple_tree(Type const& obj, Simple_tree* p) :element(obj), parent_node(p)
{
    // Empty constructor
}
template <typename Type>
Type Simple_tree<Type>::retrieve() const
{
    return element;
}
template <typename Type>
Simple_tree<Type>* Simple_tree<Type>::parent() const
{
    return parent_node;
}
template <typename Type>
bool Simple_tree<Type>::is_root() const
{
    return (parent() == NULL);
}
template <typename Type>
int Simple_tree<Type>::degree() const
{
    return children.size();
}
template <typename Type>
bool Simple_tree<Type>::is_leaf() const
{
    return (degree() == 0);
}
template <typename Type>
Simple_tree<Type>* Simple_tree<Type>::child(int n) const
{
    if (n < 0 || n >= degree())
    {
        return NULL;
    }
    Node<Simple_tree*>* ptr = children.head();
    for (int i = 1; i < n; ++i)
    {
        ptr = ptr->next();
    }
    return ptr->retrieve();
}
template <typename Type>
void Simple_tree<Type>::insert(Type const& obj)
{
    children.push_back(new Simple_tree(obj, this));
    //cout<< children.back()->retrieve();
}
template <typename Type>
void Simple_tree<Type>::attach(Simple_tree<Type>* tree)
{
    if (!tree->is_root())
    {
        tree->detach();
    }
    tree->parent_node = this;
    children.push_back(tree);
}

template <typename Type>
void Simple_tree<Type>::detach()
{
    if (is_root())
    {
        return;
    }
    parent()->children.erase(this);
    parent_node = NULL;
}
template <typename Type>
int Simple_tree<Type>::size() const
{
    int s = 1;
    for (Node<Simple_tree*>* ptr = children.head(); ptr != NULL; ptr = ptr->next())
    {
        s += ptr->retrieve()->size();
    }
    return s;
}
template <typename Type>
int Simple_tree<Type>::height() const
{
    int h = 0;
    for (Node<Simple_tree*>* ptr = children.head(); ptr != NULL; ptr = ptr->next())
    {
        h = std::max(h, 1 + ptr->retrieve()->height());
    }
    return h;
}

template <typename Type>
void Simple_tree<Type>::depth_first_traversel() const
{
    cout << retrieve() << " ";
    for (Node<Simple_tree*>* ptr = children.head(); ptr != NULL; ptr = ptr->next())
    {
        ptr->retrieve()->depth_first_traversel();
    }
}

template <typename Type>
void Simple_tree<Type>::breath_first_traversel() const
{
    Queue<Simple_tree*> q;
    q.push(this);
    while (!q.empty())
    {
        Simple_tree* p = q.pop();
        cout << p->retrieve() << "\t";
        for (Node<Simple_tree*>* ptr = p->children.head(); ptr != NULL; ptr = ptr->next())
        {
            q.push(ptr->retrieve());
        }
    }

}



int main()
{
    Simple_tree<int>* tree = new Simple_tree<int>(5);
    cout << tree->retrieve();
    cout << "Tree size:" << tree->size();
    cout << "\nTree height:" << tree->height();
    cout << "\nCheck root:" << tree->is_root();
    cout << "\nCheck leaf:" << tree->is_leaf();
    cout << "\nDegree:" << tree->degree();


    cout << "\nRoot Data:" << tree->retrieve();
    tree->insert(3);
    tree->insert(8);
    tree->insert(9);
    cout << "\nChild data:" << tree->child(1)->retrieve();
    cout << "\nChild data:" << tree->child(2)->retrieve();
    cout << "\nChild data:" << tree->child(0)->retrieve();
    cout << "\nCheck root:" << tree->is_root();
    cout << "\nCheck leaf:" << tree->is_leaf();
    cout << "\nCheck tree child root?" << tree->child(0)->is_root();
    cout << "\nTree size:" << tree->size();
    cout << "\nTree height:" << tree->height();
    cout << "\nDegree:" << tree->degree();

    Simple_tree<int>* tmp = tree->child(0);
    tmp->detach();
    cout << "\nDegree:" << tree->degree();
    cout << "\nCheck leaf:" << tree->is_leaf();

    Simple_tree<int>* tree2 = new Simple_tree<int>(7);
    cout << "\nCheck tree 2 root:" << tree->is_root();
    tree->attach(tree2);
    cout << "\nTree size:" << tree->size();
    cout << "\nTree height:" << tree->height();
    cout << "\nDegree:" << tree->degree();
    cout << "\nCheck tree 2 root:" << tree->is_root();
    cout << "\nTree 2 Child data:" << tree->child(0)->retrieve() << endl;

    Simple_tree<int>* tree3 = new Simple_tree<int>(9);
    tree3->attach(tree);
    cout << "\nTree 3 after attaching tree 1:";
    cout << "\nTree 3 size:" << tree3->size();
    cout << "\nTree 3 height:" << tree3->height();
    cout << "\nDegree:" << tree3->degree();
    tree3->attach(tree2);
    cout << "\nTree 3 after attaching tree 1:";
    cout << "\nTree 3 size:" << tree3->size();
    cout << "\nTree 3 height:" << tree3->height();
    cout << "\nDegree:" << tree3->degree();
    cout << "\nDFS ";
    tree3->depth_first_traversel();
    return 0;
}