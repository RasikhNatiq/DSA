template <typename Type>
void Simple_tree<Type>::depth_first_traversel() const
{
    cout << retrieve() << " ";
    for (Node<Simple_tree*>* ptr = children.head(); ptr != NULL; ptr = ptr->next())
    {
        ptr->retrieve()->depth_first_traversel();
    }
}