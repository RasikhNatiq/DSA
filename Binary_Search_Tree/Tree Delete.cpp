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