#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    node* next;
};

struct Queue
{
    node *front;
    node *rear;
};

node* newNode(int k)
{
    node* temp = new node();
    temp->key = k;
    temp->next = NULL;
    return temp;
}

Queue* createQueue()
{
    Queue* q = new Queue();
    q->front = q->rear = NULL;
    return q;
}

void enQueue(Queue* q, int k)
{
    node* temp = newNode(k);
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

node* deQueue(Queue* q)
{
    if (q->front == NULL) { cout<<"Queue is empty.\n"; return NULL; }
    node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) { q->rear = NULL; cout<<"Queue is now empty.\n"; }
    return temp;
}

int main()
{
    Queue* q = createQueue();
    enQueue(q, 10);     cout<<q->front->key<<' '<<q->rear->key<<endl;
    enQueue(q, 20);     cout<<q->front->key<<' '<<q->rear->key<<endl;
    enQueue(q, 30);     cout<<q->front->key<<' '<<q->rear->key<<endl;
    deQueue(q);         cout<<q->front->key<<' '<<q->rear->key<<endl;
    deQueue(q);         cout<<q->front->key<<' '<<q->rear->key<<endl;
    enQueue(q, 70);     cout<<q->front->key<<' '<<q->rear->key<<endl;
    enQueue(q, 40);     cout<<q->front->key<<' '<<q->rear->key<<endl;
    enQueue(q, 50);     cout<<q->front->key<<' '<<q->rear->key<<endl;
    deQueue(q);         cout<<q->front->key<<' '<<q->rear->key<<endl;
    deQueue(q);         cout<<q->front->key<<' '<<q->rear->key<<endl;
    deQueue(q);         cout<<q->front->key<<' '<<q->rear->key<<endl;
    deQueue(q);
    return 0;
}
