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

bool search(node* head, int key){
    node*temp=head;
    
    while(temp != NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void deleteAtHead(node* &head){      //for deletion of first node i.e. head.
    node* toDelete=head;
    
    head=head->next;
    delete toDelete;
}

void deletion(node* &head, int val){    //this will not work if we delete first node i.e. head.
    if(head==NULL){
        return;
    }
    
    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }

    node*temp=head;
    
    while(temp->next->data != val){
        temp=temp->next;
    }
    node* toDelete=temp->next;
    
    temp->next=temp->next->next;
    
    delete toDelete;
}

node* reverse(node* &head){
    
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    
    while(currptr != NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;
        
        prevptr=currptr;
        currptr=nextptr;
    }
    
    return prevptr;
}

node* reverseRecursive(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    node* newHead= reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    
    return newHead;
}

node* reverseK(node* &head, int k){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    
    int count=0;
    
    while(currptr != NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    
    if(nextptr != NULL){
        head->next=reverseK(nextptr,k);
    }
    return prevptr;
}

void removeDup(node* &head){
    node* temp=head;
    
    int arr[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    arr[temp->data]++;
    
    while(temp->next != NULL){
        if(arr[temp->next->data]==0){
            node* todelete=temp->next;
            temp->next=temp->next->next;
            delete todelete;
        }
        else{
        arr[temp->next->data]++;
        temp=temp->next;
    }}
}



int main()
{
    node* head=NULL;
    insertAtTail(head,5);
    insertAtTail(head,2);
    insertAtTail(head,2);
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,4);
    insertAtTail(head,1);
    
    //display(head);
    
    insertAtHead(head,0);
    
    display(head);
    
    //cout<<search(head,3)<<endl;
    //cout<<search(head,4)<<endl;
    
    //deletion(head,4);
    //display(head);
    //deleteAtHead(head);
    //display(head);
    
    //node* newHead=reverse(head);
    //display(newHead);
    //node* newHead=reverseRecursive(head);
    //display(newHead);
    //node* newHead=reverseK(head,2);
    //display(newHead);
    removeDup(head);
    display(head);
    
    

    return 0;
}



