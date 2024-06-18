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