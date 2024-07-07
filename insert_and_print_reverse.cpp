#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

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

void insert_at_position(Node *&head, Node *&tail, int pos, int v)
{
  

    Node *newNode = new Node(v);
    Node *temp = head;
    for (int i = 1; i < pos; i++)
    {
        if (temp == NULL)
            return; 
        temp = temp->next;
    }

    newNode->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    else
    {
        tail = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void print_node(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void print_reverse(Node *tail)
{

    Node *temp = tail;

    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int t;

    cin >> t;
    while (t--)
    {
        int pos, val;
        cin >> pos >> val;

        if (pos == 0)
        {
            insert_at_head(head, tail, val);
            print_node(head);
            print_reverse(tail);
        }
        else if (pos > size(head))
        {
            cout << "Invalid" << endl;
        }
        else
        {
            insert_at_position(head, tail, pos, val);
            print_node(head);
            print_reverse(tail);
        }
    }

    return 0;
}
