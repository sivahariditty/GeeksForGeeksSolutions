#include <bits/stdc++.h>
using namespace std;

struct Node{
   int data;
   Node *right;
   Node *left;
};

Node* newNode(int val){
   Node *tmp = new Node;
   tmp->data = val;
   tmp->right = NULL;
   tmp->left = NULL;
   return tmp;
}

void insertNode(Node *rt,int val){
   Node *ptr = rt, *prev;
   while(ptr != NULL){
      prev = ptr;
      if(ptr->data > val){
         ptr = ptr->left;
      }
      else{
	 ptr = ptr->right;
      }
   }
   if(prev->data > val){
      prev->left = newNode(val);
   }
   else{
      prev->right = newNode(val);
   }
}

Node *buildTree(int arr[], int n){
   Node *root = newNode(arr[0]);
   for(int i=1;i<n;i++){
      insertNode(root,arr[i]);
   }
   return root;
}

void inOrder(Node *root){
   if(root != NULL){
      inOrder(root->left);
      cout<<root->data<<" ";
      inOrder(root->right);
   }
}
void preOrder(Node *root){
   if(root != NULL){
      cout<<root->data<<" ";
      preOrder(root->left);
      preOrder(root->right);
   }
}
void posOrder(Node *root){
   if(root != NULL){
      posOrder(root->left);
      posOrder(root->right);
      cout<<root->data<<" ";
   }
}

int main(){
   int n;
   cin>>n;
   int arr[n];
   for(int i =0;i<n;i++){
      cin>>arr[i];
   }
   Node *rtr = buildTree(arr,n);
   inOrder(rtr);
   return 0;
}
