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