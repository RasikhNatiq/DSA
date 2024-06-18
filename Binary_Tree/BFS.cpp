template <typename Type>
void Binary_tree<Type>::currentlevel(Binary_node<Type>* root, int k)
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
void Binary_tree<Type>::bfs(Binary_node<Type>* root)
{
    for (int i = 1; i <= height()+1; i++)
    {
        currentlevel(root, i);
    }
}