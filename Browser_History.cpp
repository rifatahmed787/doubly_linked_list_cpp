#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string str;
    Node *next = NULL;
    Node *prev = NULL;

    Node(string str)
    {
        this->str = str;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, string str)
{
    Node *newNode = new Node(str);

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

    while (temp != NULL)
    {
        cout << "the str is:" << temp->str << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int t;
    cin >> t;

    while (t--)
    {

        string str, end = "end";
        while (true)
        {
            cin>>str;
            cout<<"the str"<<str;
            if (str == end)
                break;
            insert_at_tail(head, tail, str);
        }

        print_next(head);
    }

    return 0;
}