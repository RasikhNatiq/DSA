#include <iostream>
using namespace std;

template <typename Type>
class Binary_node
{
protected:
    Type element;
    Binary_node* left_tree;
    Binary_node* right_tree;
public:
    Binary_node(Type const&);
    Type retrieve() const;
    Binary_node* left() const;
    void setleft(Binary_node<Type>* obj);
    Binary_node* right() const;
    void setright(Binary_node<Type>* obj);
    bool empty() const;
    bool is_leaf() const;
    int size() const;
    int height() const;
    void clear(Binary_node<Type>*);

};

template <typename Type>
Binary_node<Type>::Binary_node(Type const& obj) :element(obj), left_tree(NULL), right_tree(NULL)
{
    // Empty constructor
}

template <typename Type>
Type Binary_node <Type>::retrieve() const
{
    return element;
}

template <typename Type>
Binary_node<Type>* Binary_node <Type>::left() const
{
    return left_tree;
}
template <typename Type>
void Binary_node <Type>::setleft(Binary_node<Type>* obj)
{
    left_tree = obj;
}

template <typename Type>
Binary_node<Type>* Binary_node <Type>::right() const
{
    return right_tree;
}

template <typename Type>
void Binary_node <Type>::setright(Binary_node<Type>* obj)
{
    right_tree = obj;
}
template <typename Type>
bool Binary_node <Type>::empty() const
{
    return (this == NULL);
}

template <typename Type>
bool Binary_node <Type>::is_leaf() const
{
    return !empty() && left()->empty() && right()->empty();
}

template <typename Type>
int Binary_node <Type>::size() const
{
    return empty() ? 0 : 1 + left()->size() + right()->size();
}

template <typename Type>
int Binary_node <Type>::height() const
{
    return empty() ? -1 : 1 + std::max(left()->height(), right()->height());
}

template <typename Type>
void Binary_node <Type>::clear(Binary_node<Type>* ptr_to_this)
{
    if (empty())
    {
        return;
    }
    left()->clear(left_tree);
    right()->clear(right_tree);
    delete this;
    ptr_to_this = NULL;
}
template <typename Type>
class Binary_tree
{
private:
    Binary_node<Type>* root_node;

public:
    Binary_tree();
    Binary_node<Type>* root() const;
    bool empty() const;
    int size() const;
    int height() const;
    void insert(Type obj);
};

template <typename Type>
Binary_tree<Type>::Binary_tree() :root_node(NULL)
{
    // Empty constructor
}

template <typename Type>
Binary_node<Type>* Binary_tree<Type>::root() const
{
    return root_node;
}

template <typename Type>
bool Binary_tree<Type>::empty() const
{
    return (root_node == NULL);
}

template <typename Type>
int Binary_tree<Type>::size() const
{
    return (root() == NULL) ? 0 : root()->size();
}

template <typename Type>
int Binary_tree<Type>::height() const
{
    return (root() == NULL) ? -1 : root()->height();
}

template <typename Type>
void Binary_tree<Type>::insert(Type obj)
{
    Binary_node<Type>* n = new Binary_node<Type>(obj);
    if (root()->empty())
    {
        root_node = n;
    }
    else if (root()->left() == NULL)
    {
        root()->setleft(n);
    }
    else if (root()->right() == NULL)
    {
        root()->setright(n);
    }
    else
    {
        Binary_node<Type>* r = root();
        if (r->left()->height() > r->right()->height())
        {
            while (r->right() != NULL)
            {
                r = r->right();
            }
            r->setright(n);
        }
        else
        {
            while (r->left() != NULL)
            {
                r = r->left();
            }
            r->setleft(n);
        }

    }

}
template <typename Type>
void inorder(Binary_node<Type>* r)
{
    if (r != NULL)
    {
        inorder(r->left());
        cout << r->retrieve() << "\t";
        inorder(r->right());
    }
}

template <typename Type>
void preorder(Binary_node<Type>* r)
{
    if (r != NULL)
    {
        cout << r->retrieve() << "\t";
        preorder(r->left());
        preorder(r->right());
    }
}

template <typename Type>
void postorder(Binary_node<Type>* r)
{
    if (r != NULL)
    {
        postorder(r->left());
        postorder(r->right());
        cout << r->retrieve() << "\t";
    }
}


int main()
{
    Binary_tree<int> b;
    cout << "Empty = " << b.empty() << endl;
    cout << "Size = " << b.size() << endl;
    cout << "Height = " << b.height() << endl;
    b.insert(8);
    b.insert(18);
    b.insert(28);
    b.insert(12);
    b.insert(10);
    b.insert(0);
    cout << "\nEmpty = " << b.empty() << endl;
    cout << "Size = " << b.size() << endl;
    cout << "Height = " << b.height() << endl;
    cout << "\nInorder:";
    inorder(b.root());
    cout << "\nPostorder:";
    postorder(b.root());
    cout << "\nPreorder:";
    preorder(b.root());
    cout << endl;
    return 0;
}