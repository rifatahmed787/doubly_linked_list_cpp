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

void reverse_node(Node *head, Node *tail) {
    Node *i = head;
    Node *j = tail;
    while (i != j && i->prev != j) {
        swap(i->val, j->val);
        i = i->next;
        j = j->prev;
    }
}

void print_reverse(Node *head)
{
    Node *temp = head;
    cout << "Print reverse: ";
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
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

    reverse_node(head, tail);
    print_reverse(head);
    return 0;
}
