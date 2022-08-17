#include <bits/stdc++.h>
using namespace std;

template<class t>
struct Node {
    t data;
    Node* next;
    Node(t d)
    {
        data = d;
        next = nullptr;
    }
};
template<class t>
class Queue
{
    Node<t> *front, *rear;
public:
    Queue()
    {
        front = rear = nullptr;
    }

    void enQueue(t data)
    {
        bool enter= false;
        Node<t>* target = new Node<t>(data);

        if (rear == nullptr) {
            front = rear = target;
            return;
        }
        Node<t>* prev = front;
        Node<t>* current = front;

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

        Node<t>* temp = front;
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

        Node<t>* temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;
        delete (temp);
    }

    void display(){
        Node<t>* temp = front;
        while (temp){
            cout<<temp->data;
            (temp->next)?cout<<"->":cout<<"";
            temp=temp->next;
        }
        cout<<endl;
    }

    t getFront(){
        return front->data;
    }

    t getRear(){
        return rear->data;
    }

    ~Queue(){
        delete front;
        delete rear;
    }
};

int main()
{
    Queue<string> q;
    q.enQueue("Ahmed");
    q.enQueue("mohaned");
    q.enQueue("mahmoud");
    q.display();
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
}