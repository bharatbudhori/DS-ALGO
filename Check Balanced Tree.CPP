#include <bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  struct Node* left;
  struct Node* right;
  
  Node(int val){
      data=val;
      left=NULL;
      right=NULL;
  }
};

void preorder(struct Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
   
}

int search(int inorder[], int start, int end, int cur){
    for(int i=0;i<=end;i++){
        if(inorder[i]==cur){
            return i;
        }
        
    }
    return -1;
}

Node* buildTree_pre(int preorder[], int inorder[],int start, int end){
    static int i=0;
    if(start>end){
        return NULL;
    }
    int cur=preorder[i];
    i++;
    Node* node=new Node(cur);
    
    int pos=search(inorder,start,end,cur);
    
    if(start==end){
        return node;
    }
    node->left=buildTree_pre(preorder,inorder,start,pos-1);
    node->right=buildTree_pre(preorder,inorder,pos+1,end);
    
    return node;
}

Node* buildTree_pos(int postorder[], int inorder[],int start, int end){
    static int idx=end;
    if(start>end){
        return NULL;
    }
    int cur=postorder[idx];
    idx--;
    Node* node=new Node(cur);
    
    int pos=search(inorder,start,end,cur);
    
    if(start==end){
        return node;
    }
    
    node->right=buildTree_pos(postorder,inorder,pos+1,end);
    node->left=buildTree_pos(postorder,inorder,start,pos-1);
    
    return node;
}

void levelOrder(Node* root){
    if(root==NULL){
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            
            if(node->left !=NULL){
                q.push(node->left);
            }
            if(node->right !=NULL){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}

int SumAtK(Node* root, int K){
    if(root==NULL){
        return -1;
    }
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level=0,sum=0;
    
    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(node!=NULL){
            if(level==K){
                sum+=node->data;
            }
            
            if(node->left !=NULL){
                q.push(node->left);
            }
            if(node->right !=NULL){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

int countNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return countNodes(root->left)+countNodes(root->right)+1;
}

int sumNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return sumNodes(root->left)+sumNodes(root->right)+root->data;
}

int calcHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    
    int lHeight=calcHeight(root->left);
    int rHeight=calcHeight(root->right);
    
    return max(lHeight,rHeight)+1;
}

int calcDiameter(Node* root, int* height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    
    int lHeight=0;
    int rHeight=0;
    
    int lDiameter=calcDiameter(root->left, &lHeight);
    int rDiameter=calcDiameter(root->right, &rHeight);
    
    int currDiameter=lHeight+rHeight+1;
    *height=max(lHeight,rHeight)+1;
    
    return max(currDiameter, max(rDiameter,lDiameter));
}

void sumReplace(Node* root){
    if(root==NULL){
        return;
    }
    
    sumReplace(root->left);
    sumReplace(root->right);
    
    if(root->left != NULL){
        root->data+=root->left->data;
    }
    if(root->right != NULL){
        root->data+=root->right->data;
    }
}

bool isBalanced(Node* root){
    if(root==NULL){
        return true;
    }
    if(isBalanced(root->left)==false){
        return false;
    }
    if(isBalanced(root->right)==false){
        return false;
    }
    int lh=calcHeight(root->left);
    int rh=calcHeight(root->right);
    
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
}


int main()
{
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    
    cout<<isBalanced(root);
    
    //sumReplace(root);
    //preorder(root);
    
    //int height=0;
    //cout<<calcDiameter(root, &height);
    
    //cout<<countNodes(root);
    //cout<<endl;
    //cout<<sumNodes(root);
    
    //levelOrder(root);
    
    //cout<<SumAtK(root,2);
    
    
    //int preorder_arr[]={1,2,4,5,3,6,7};
    // postorder_arr[]={4,5,2,6,7,3,1};
    //int inorder_arr[]={4,2,5,1,6,3,7};
    
    //struct Node* newroot=buildTree_pre(preorder_arr,inorder_arr,0,6);
    //struct Node* newroot2=buildTree_pos(postorder_arr,inorder_arr,0,6);
    
    //preorder(newroot);
    //cout<<endl;
    //inorder(newroot);
    //cout<<endl;
    //postorder(newroot2);
    //cout<<endl;
    //(newroot);
    
    //(root);
    //cout<<endl;
    //postorder(root);
    //cout<<endl;
    //inorder(root);
    //<<endl;

    return 0;
}



