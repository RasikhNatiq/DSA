#include <iostream>
#include<queue>
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
    void setdata(Type obj);
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
void Binary_node <Type>::setdata(Type obj)
{
    element = obj;
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
class Binary_Search_tree
{
private:
    Binary_node<Type>* root_node;

public:
    Binary_Search_tree();
    Binary_node<Type>* root() const;
    bool empty() const;
    int size() const;
    int height() const;
    void insert(Type obj);
    Binary_node<Type>* search(Type obj);
    void currentlevel(Binary_node<Type>* root, int k);
    void bfs(Binary_node<Type>* root);
    void  BreadthFirstTravseral(Binary_node<Type>* root);

};

template <typename Type>
Binary_Search_tree<Type>::Binary_Search_tree() :root_node(NULL)
{
    // Empty constructor
}

template <typename Type>
Binary_node<Type>* Binary_Search_tree<Type>::root() const
{
    return root_node;
}

template <typename Type>
bool Binary_Search_tree<Type>::empty() const
{
    return (root_node == NULL);
}

template <typename Type>
int Binary_Search_tree<Type>::size() const
{
    return (root() == NULL) ? 0 : root()->size();
}

template <typename Type>
int Binary_Search_tree<Type>::height() const
{
    return (root() == NULL) ? -1 : root()->height();
}

template <typename Type>
Binary_node<Type>* maximum(Binary_node<Type>* n)
{
    while (n->right() != NULL)
    {
        n = n->right();
    }
    return n;
}

template <typename Type>
Binary_node<Type>* minimum(Binary_node<Type>* n)
{
    while (n->left() != NULL)
    {
        n = n->left();
    }
    return n;
}

template <typename Type>
Binary_node<Type>* Binary_Search_tree<Type>::search(Type obj)
{
    if (root() == NULL || root()->retrieve() == obj)
    {
        return root();
    }
    else
    {
        Binary_node<Type>* r = root();
        while (r != NULL && r->retrieve() != obj)
        {
            if (obj < r->retrieve())
            {
                r = r->left();
            }
            else if (obj > r->retrieve())
            {
                r = r->right();
            }
        }
        return r;
    }
}
template <typename Type>
void Binary_Search_tree<Type>::currentlevel(Binary_node<Type>* root, int k)
{
    if (root == NULL)
        return;
    if (k == 1)
        cout << root->retrieve() << " ";
    else if (k > 1)
    {
        currentlevel(root->left(), k - 1);
        currentlevel(root->right(), k - 1);
    }
}
template <typename Type>
void Binary_Search_tree<Type>::bfs(Binary_node<Type>* root)
{
    for (int i = 1; i <= height() + 1; i++)
    {
        currentlevel(root, i);
    }
}

template <typename Type>
void Binary_Search_tree<Type>::insert(Type obj)
{
    Binary_node<Type>* n = new Binary_node<Type>(obj);
    Binary_node<Type>* r = root_node;
    Binary_node<Type>* p = root_node;
    if (root()->empty())
    {
        root_node = n;
    }
    else
    {
        while (!r->empty())
        {
            p = r;
            if (obj < r->retrieve()) //less than root
            {
                r = r->left();
            }
            else                  //greater than root
            {
                r = r->right();
            }
        }

        if (obj < p->retrieve()) //leftchild
        {
            p->setleft(n);
        }
        else                  //rightchild
        {
            p->setright(n);
        }
    }
}
template <typename Type>
void  Binary_Search_tree<Type>::BreadthFirstTravseral(Binary_node<Type>* root)
{
    queue<Binary_node<Type>*> q;

    if (!root) {
        return;
    }
    for (q.push(root); !q.empty(); q.pop()) {
        Binary_node<Type>* temp_node = q.front();
        cout << temp_node->retrieve() << " ";

        if (temp_node->left()) {
            q.push(temp_node->left());
        }
        if (temp_node->right()) {
            q.push(temp_node->right());
        }
    }
}

template <typename Type>
void tree_delete(Binary_node<Type>* r, Type obj)
{
    Binary_node<Type>* p = r;
    while (r != NULL)
    {
        if (obj == r->retrieve())              //element found (node to be deleted found)
        {
            cout << "element found ";
            if (r->is_leaf())                //node is leaf/no child
            {
                cout << "nochild ";
                if (r->retrieve() > p->retrieve())
                {
                    p->setright(NULL);
                }
                else if (r->retrieve() < p->retrieve())
                {
                    p->setleft(NULL);
                }
                delete r;
            }
            else if (r->left() == NULL)     //one child(right)
            {
                cout << "right child ";
                if (r->retrieve() > p->retrieve())
                {
                    p->setright(r->right());
                }
                else if (r->retrieve() < p->retrieve())
                {
                    p->setleft(r->right());
                }
            }
            else if (r->right() == NULL)    //one child(left)
            {
                cout << "left child ";
                if (r->retrieve() > p->retrieve())
                {
                    p->setright(r->left());
                }
                else if (r->retrieve() < p->retrieve())
                {
                    p->setleft(r->left());
                }
            }
            else                            //two children
            {
                cout << "two child ";
                Binary_node<Type>* temp = minimum(r->right());
                r->setdata(temp->retrieve());
                tree_delete(r->right(), temp->retrieve());
            }
            return;
        }
        else if (obj < r->retrieve())   //less than root
        {
            p = r;
            r = r->left();
        }
        else if (obj > r->retrieve())  //greater than root
        {
            p = r;
            r = r->right();
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
    Binary_Search_tree<int> b;
    cout << "IS EMPTY = " << b.empty() << endl;
    cout << "SIZE = " << b.size() << endl;
    cout << "HEIGHT = " << b.height() << endl;
    b.insert(8);
    b.insert(18);
    b.insert(28);
    b.insert(12);
    b.insert(10);
    b.insert(0);
    b.insert(15);
    b.insert(16);
    cout << "\nIS EMPTY = " << b.empty() << endl;
    cout << "SIZE = " << b.size() << endl;
    cout << "HEIGHT = " << b.height() << endl << endl;
    cout << "Inorder  :";
    inorder(b.root());

    cout << "\nPostorder:";
    postorder(b.root());
    cout << "\nPreorder :";
    preorder(b.root());
    cout << endl;
    cout << "\nMaximum: " << maximum(b.root())->retrieve() << endl;
    cout << "Minimum: " << minimum(b.root())->retrieve() << endl;
    cout << "Found it: " << b.search(12)->retrieve() << endl;
    cout << "Deleting: ";
    tree_delete(b.root(), 8);
    cout << "\nInorder  :";
    inorder(b.root());
    cout << "\n\nBFS: ";
    b.bfs(b.root());
    cout << "\n\BreadthFirstTravseral: ";
    b.BreadthFirstTravseral(b.root());
    return 0;
}