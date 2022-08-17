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
    Node<t> *front, *rear;int size=0;
public:
    Queue()
    {
        front = rear = nullptr;
    }

    void enQueue(t data)
    {
        size++;
        bool enter= false;
        Node<t>* target = new Node<t>(data);

        if (rear == nullptr) {
            front = rear = target;
            return;
        }
        Node<t>* prev = front;
        Node<t>* current = front;

        while (prev->data >= target->data){//p=5 t=4
            target->next = prev;
            front=target;
            prev=target;
            if(prev->data==target->data)return;
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
        size--;
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

    int getSize(){
        return size;
    }

    ~Queue(){
        delete front;
        delete rear;
    }
};

int main()
{
    Queue<int> q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(10);
    q.enQueue(8);
    q.enQueue(5);
    q.enQueue(1);
    q.enQueue(2);
    q.display();
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    cout<<q.getSize()<<endl;
    q.deQueue();
    q.display();
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    cout<<q.getSize()<<endl;
}