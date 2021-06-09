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

void insertAtHead(node* &head, int val){
    node* n=new node(val);
    
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    
    node* temp=head;
    
    while(temp->next != head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}

void insertAtTail(node* &head, int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    
    node* n=new node(val);
    node* temp=head;
    
    while(temp->next != head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}

void display(node* head){
    node* temp=head;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    }while(temp != head);
    
    cout<<endl;
}

int length(node* head){
     node* temp=head;
     int count=0;
    do{
        count++;
        temp=temp->next;
    }while(temp != head);
    
    return count;
}

void half(node* &head){
    int halfWay;
   if(length(head)%2==0){
       halfWay=length(head)/2;
   }
   else{
       halfWay=length(head)/2 + 1;
   }
   node*temp=head;
   node* head1=head;
   node* head2;
   int count=1;
   
   while(count != halfWay){
       temp=temp->next;
       count++;
   }
   head2=temp->next;
   temp->next=head;
   
   temp=head2;
   
   display(head1);
   while(temp->next != head){
       temp=temp->next;
       
   }
   temp->next=head2;
   display(head2);
}

int main(){
    node* head=NULL;
    
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    //insertAtTail(head,5);
    
    //display(head);
    
    insertAtHead(head,0);
    cout<<length(head)<<endl;
    
    display(head);
    half(head);
}
