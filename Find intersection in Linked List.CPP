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

int length(node* head){
    int l=0;
    node* temp=head;
    
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

node* kAppend (node* &head, int k){
    
    node* newHead;
    node* newTail;
    node* tail=head;
    
    int l=length(head);
    k=k%l;
    
    int count=1;
    
    while(tail->next != NULL){
        if(count==l-k){
            newTail=tail;
        }
        if(count==l-k+1){
            newHead=tail;
        }
        tail=tail->next;
        count++;
    }
    
    newTail->next=NULL;
    tail->next=head;
    
    return newHead;
}

int findIntersection(node* &head1, node* &head2){
    int l1=length(head1);
    int l2=length(head2);
    
    int d=0;
    node* ptr1;
    node* ptr2;
    
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    
    while(d){
        ptr1=ptr1->next;
        if(ptr1 == NULL){
            return -1;
        }
        d--;
    }
    
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}

void intersect(node* &head1, node* &head2, int pos){
    node* temp1=head1;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    node* temp2=head2;
    
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}



int main()
{
    node* head=NULL;
    node* head2=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    
    insertAtTail(head2,3);
    insertAtTail(head2,4);
    insertAtTail(head2,5);
    
    intersect(head,head2,4);
    
    //display(head);
    
    //insertAtHead(head,0);
    
    //display(head);
    
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
    
    //node* newHead=kAppend(head,3);
    //display(newHead);
    
    cout<<findIntersection(head,head2);
    
    

    return 0;
}




