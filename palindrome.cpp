#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node *next=NULL;
    Node *prev=NULL;

    Node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};


void insert_at_tail(Node *&head, Node *&tail, int v)
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

bool is_Palindrome(Node *head, Node *tail){
  Node *i=head;
  Node *j=tail;
  while(i!=j && i->prev!=j){
    if(i->val!=j->val){
        return false;
    }
     i = i->next;
     j = j->prev;
  }
  return true;
}
 
int main(){
    Node *head=NULL;
    Node *tail=NULL;
    int val;
  

    while(true){
        cin>>val;
        if(val==-1)break;
        insert_at_tail(head, tail, val);
    }  

    if(is_Palindrome(head, tail)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}