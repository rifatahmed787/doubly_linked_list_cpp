#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string str;
    Node *next;
    Node *prev;

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
    tail = newNode;
}

Node *find_node(Node *head, string str)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->str == str)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void print_list(Node *current, bool forward)
{
    if (current == NULL)
    {
        cout << "Not Available" << endl;
        return;
    }
    if (forward)
    {
        cout << current->str << endl;
    }
    else
    {
       
        if (current->prev != NULL)
        {
            cout << current->prev->str << endl;
        }
        else
        {
            cout << "Not Available" << endl;
        }
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *current = NULL;
    string str;

    
    while (true)
    {
        cin >> str;
        if (str == "end")
            break;
        insert_at_tail(head, tail, str);
    }

    
    int t;
    cin >> t;
    while (t--)
    {
        string command;
        cin >> command;

        if (command == "visit")
        {
            string address;
            cin >> address;
            Node *node = find_node(head, address);
            if (node != NULL)
            {
                current = node;
                cout << current->str << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "next")
        {
            if (current != NULL && current->next != NULL)
            {
                current = current->next;
                cout << current->str << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "prev")
        {
            if (current != NULL && current->prev != NULL)
            {
                current = current->prev;
                cout << current->str << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}
