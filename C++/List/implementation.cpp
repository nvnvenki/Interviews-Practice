#include <iostream>
#include "header.h"
using namespace std;

node::node(int x):key(x),link(0)
{
}

queue::queue():front(0),rear(0)
{
}

queue::~queue()
{
        node *temp = front;
        while(temp)
        {
//                cout << temp -> key << endl;
                node *cur = temp;
                temp = temp -> link;
                delete cur;
        }
}

void queue::add(int x)
{
        node *temp = new node(x);
        if(rear == 0) // empty queue
        {
                rear = front = temp;
        }
        else
        {
                rear = rear -> link = temp;
        }
}

int queue::remove()
{
        node *temp = front;
        int n = front -> key;
        front = front -> link;
        delete temp;
        if(front == 0)
        {
                rear = 0;
        }
        return n;
}

bool queue::empty()
{
        return front == 0;
}
