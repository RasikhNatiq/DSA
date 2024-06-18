#include <iostream>
using namespace std;

class underflow
{

};

class overflow
{

};

template<typename Type>
class Queue
{
private:
    int queue_size;
    int ifront;
    int iback;
    int array_capacity;
    Type* array;

public:
    Queue(int = 5);
    bool empty() const;
    Type front() const;
    void push(Type const&);
    Type pop();

};

template <typename Type>
Queue<Type>::Queue(int n) :

    queue_size(0),
    iback(-1),
    ifront(0),
    array_capacity(std::max(1, n)),
    array(new Type[array_capacity]) {

    // Empty constructor
}

template <typename Type>
bool Queue<Type>::empty() const {
    return (queue_size == 0);
}

template <typename Type>
Type Queue<Type>::front() const {
    if (empty()) {
        throw underflow();
    }
    return array[ifront];
}

template <typename Type>
void Queue<Type>::push(Type const& obj) {
    if (queue_size == array_capacity) {
        throw overflow();
    }
    ++iback;
    array[iback] = obj;
    ++queue_size;
}
template <typename Type>
Type Queue<Type>::pop() {
    if (empty()) {
        throw underflow();
    }

    --queue_size;
    if (ifront == array_capacity)
    {
        ifront = 0;
    }
    ++ifront;
    return array[ifront - 1];
}



int main()
{
    Queue<int> q;
    cout << q.empty();
    q.push(3);
    cout << "\n Front of the queue after push(3): " << q.front();
    q.push(6);
    cout << "\n Front of the queue after push(6): " << q.front();
    q.push(8);
    q.push(9);
    cout << "\n Poping the value: " << q.pop();
    q.push(15);
    q.push(16);
    cout << "\n Front of the queue after push(8): " << q.front();
    cout << "\n Poping the value: " << q.pop();
    cout << "\n Poping the value: " << q.pop();
    cout << "\n Front of the queue two pop operations: " << q.front();
    cout << endl << q.empty();
    return 0;
}