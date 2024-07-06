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


void insert_at_tail(Node*&head, Node*&tail, int val){
    Node *newNode=new Node(val);
   if (head == NULL)
    {
        head=newNode;
        tail=newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

bool print_the_comparision(Node *head1, Node *head2){
  bool flag=true;
  while(head1!=NULL && head2!=NULL){
    if(head1->val != head2->val){
      flag=false;
      break;
    }
    head1=head1->next;
    head2=head2->next;
    
  }
  return flag;
  
};
 
int main(){
    Node *head1=NULL;
    Node *tail1=NULL;
    int val1;
  

    while(true){
        cin>>val1;
        if(val1==-1)break;
        insert_at_tail(head1, tail1, val1);
    }

    
    Node *head2=NULL;
    Node *tail2=NULL;
    int val2;

    while(true){
        cin>>val2;
        if(val2==-1)break;
        insert_at_tail(head2, tail2, val2);
    }


    if(print_the_comparision(head1, head2)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }

    
    return 0;
}