#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

class Queue
{
    Node *front, *rear;
public:
    Queue()
    {
        front = rear = nullptr;
    }

    void enQueue(int data)
    {
        Node* temp = new Node(data);

        if (rear == nullptr) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void deQueue()
    {
        if (front == nullptr)
            return;

        Node* temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;
        delete (temp);
    }

    int getFront(){
        return front->data;
    }

    int getRear(){
        return rear->data;
    }

    ~Queue(){
        delete front;
        delete rear;
    }
};

int main()
{
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.deQueue();
    q.deQueue();
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.deQueue();
    cout << "Queue Front : " << q.getFront()<<endl;
    cout << "Queue Rear : " << q.getRear();
}
//Output:
//Queue Front : 40
//Queue Rear : 50