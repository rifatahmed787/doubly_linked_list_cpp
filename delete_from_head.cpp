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

int size(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}



void delete_from_head(Node *&head){
    Node *deleteHead=head;
    
    head = head->next;
    delete deleteHead;
    head->prev=NULL;
}


void delete_from_pos(Node *&head, int pos){
    Node *temp=head;
    for(int i=1; i<=pos-1; i++){
        temp=temp->next;
    }

    Node *deleteNode=temp->next;
    temp->next=temp->next->next;
    temp->next->prev=temp;
    delete deleteNode;
}

void delete_tail(Node *&tail){
    Node *deleteTail=tail;
    tail=tail->prev;
    delete deleteTail;
    tail->next=NULL;
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

    // Node *head = NULL;
    // Node *tail = NULL;

    int pos;
    cin >> pos;
    
    // delete_from_head(head);
    delete_tail(tail);

    print_next(head);
    print_prev(tail);
    return 0;
}