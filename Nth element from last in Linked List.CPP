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

node* intersection(node* head1, node* head2){
    node* temp1=head1;
    node* temp2=head2;
    node* temp3=NULL;
    node* head3=new node(100);
    
    int arr[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    
    
    while(temp1 != NULL){
        arr[temp1->data]+=1;
        temp1=temp1->next;
    }
    while(temp2 != NULL){
        if(arr[temp2->data]>-1){
            node* x=new node(temp2->data);
            head3->next=x;
            
        }
        temp2=temp2->next;
        
    }
    return head3;
    
}

int length(node* head){
    int l=0;
    node* temp=head;
    
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

int elementFroLast(node* head, int n){
    node* temp=head;
    int l=0;
    //node* temp=head;
    
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    
    temp=head;
    
    int x=l-n;
    int i=0;
    while(i!= x){
        temp=temp->next;
        i++;
    }
    
    return temp->data;
    
}

int main(){
    node* head2=NULL;
    node* head1=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,6);
    insertAtTail(head1,2);
    insertAtTail(head1,4);
    insertAtTail(head1,6);
    insertAtTail(head1,8);
    
    display(head1);
    //display(head2);
    
    //node* newHead=intersection(head1,head2);
    //display(newHead);
    
    cout<<elementFroLast(head1,2);
}
