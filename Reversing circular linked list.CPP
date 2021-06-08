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

void deleteAtHead(node* &head){
    node* temp=head;
    
    while(temp->next != head){
        temp=temp->next;
    }
    node* todelete=head;
    temp->next=head->next;
    head=head->next;
    
    delete todelete;
}

void getPos(node* head, int key){
    node* temp1=head;
    
    int pos=1;
    
    do{
        if(temp1->data==key){
            cout<<pos<<endl;
            return;
        }
        pos++;
        temp1=temp1->next;
    }while(temp1 != head);
    
    cout<<"element not found"<<endl;
}

void deletion(node* &head, int key){
    
    node* temp1=head;
    
    int pos=1;
    
    do{
        if(temp1->data==key){
            //cout<<pos<<endl;
            break;
        }
        pos++;
        temp1=temp1->next;
    }while(temp1 != head);
    
    //cout<<"element not found"<<endl;
    
    
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    
    node* temp=head;
    int count=1;
    
    while(count != pos-1){
        temp=temp->next;
        count++;
    }
    
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

void reverse(node* &head){
    node* temp=head;
    do{
        temp=temp->next;
    }while(temp->next != head);
    
    
    node* prevptr=temp;
    node* currptr=head;
    node* nextptr;
    
    do{
        nextptr=currptr->next;
        currptr->next=prevptr;
        
        prevptr=currptr;
        currptr=nextptr;
        }while(currptr != head);
        
        head=prevptr;
}

int main(){
    node* head=NULL;
    
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    
    display(head);
    
    insertAtHead(head,0);
    display(head);
    
    getPos(head,4);
    
    
    
    
    deletion(head,4);
    display(head);
    deletion(head,0);
    display(head);
    
    reverse(head);
    display(head);
    
}
