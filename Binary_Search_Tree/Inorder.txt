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