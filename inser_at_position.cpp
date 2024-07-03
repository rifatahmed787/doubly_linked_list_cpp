#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next = NULL;
    Node *prev = NULL;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


void insert_at_position(Node *head, int pos, int v){
    Node *newNode=new Node(v);

    Node *temp=head;
    for(int i=1; i<=pos-1; i++){
        temp=temp->next;
    }

    newNode->next=temp->next;
    temp->next=newNode;
    newNode->next->prev=newNode;
    newNode->prev=temp;
}


void print_next(Node *head)
{
    Node *temp = head;
    cout << "Print next:";
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void print_prev(Node *tail)
{
    Node *temp = tail;
    cout << "Print prev:";
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
}

int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *tail = c;

    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
    
    insert_at_position(head, 2, 100);

    print_next(head);
    print_prev(tail);
    return 0;
}