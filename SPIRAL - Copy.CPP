#include <iostream>
using namespace std;

class node{
  public:
  int data;
  node* next;
  
  node(int val){
      data=val;
      next=NULL;
  }
};

void insertAtTail(node* &head, int val){
    node* n=new node(val);
    
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp -> next != NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void insertAtHead(node* &head, int val){
    node*n =new node(val);
    n->next=head;
    head=n;
}

void display(node* head){
    node* temp=head;
    
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

node* middleNode(node* head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    node* temp2=head;
    int n=(l/2)+1;
    n--;
    while(n--){
        temp2=temp2->next;
    }
    return temp2;
    
}

int main(){
    node* head2=NULL;
    node* head1=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,6);
    insertAtTail(head1,6);
    insertAtTail(head1,6);
    insertAtTail(head1,6);
    
    
    display(head1);
    node* newhead=middleNode(head1);
    cout<<newhead->data;
    
    
}
