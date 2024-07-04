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

void inser_at_tail(Node *&head, Node *&tail, int v)
{
    Node *newNode = new Node(v);

    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
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

    Node *head = NULL;
    Node *tail = NULL;

    int val;
    
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        inser_at_tail(head, tail, val);
    }

    print_next(head);
    print_prev(tail);
    return 0;
}