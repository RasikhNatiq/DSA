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