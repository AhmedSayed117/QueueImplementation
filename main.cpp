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
        bool enter= false;
        Node* target = new Node(data);

        if (rear == nullptr) {
            front = rear = target;
            return;
        }
        Node* prev = front;
        Node* current = front;

        while (prev->data > target->data){//p=5 t=4
            target->next = prev;
            front=target;
            prev=target;
        }

        while (current->data < target->data){//c=3 t=4
            prev = current;
            current = prev->next;
            enter= true;
            if (!current)goto endpoint;
        }
        endpoint:
        if (enter)
        {
            prev->next=target;
            target->next=current;
        }

        Node* temp = front;
        rear = front;
        while (temp){
            temp=temp->next;
            if (!temp)return;
            rear=temp;
        }
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

    void display(){
        Node* temp = front;
        while (temp){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;
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
    q.enQueue(7);
    q.enQueue(8);
    q.enQueue(9);
    q.enQueue(5);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(90);
    q.enQueue(80);
    q.display();
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    q.deQueue();
    q.display();
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
}