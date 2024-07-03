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

void insert_at_head(Node *&head, Node *&tail, int v)
{
    Node *newNode = new Node(v);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insert_at_position(Node *head, int pos, int v)
{
    Node *newNode = new Node(v);

    Node *temp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = temp;
}

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
    // Node *head = new Node(10);
    // Node *a = new Node(20);
    // Node *b = new Node(30);
    // Node *c = new Node(40);
    // Node *tail = c;

    // head->next = a;
    // a->prev = head;
    // a->next = b;
    // b->prev = a;
    // b->next = c;
    // c->prev = b;

    Node *head = NULL;
    Node *tail = NULL;

    int pos;
    cin >> pos;
    int val;
    cin >> val;

    if (pos == 0)
    {
        insert_at_head(head, tail, val);
    }
    else if (pos == size(head))
    {
        inser_at_tail(head, tail, val);
    }
    else if (pos >= size(head))
    {
        cout << "Invalid position" << endl;
    }
    else
    {
        insert_at_position(head, pos, val);
    }

    print_next(head);
    print_prev(tail);
    return 0;
}