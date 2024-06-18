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