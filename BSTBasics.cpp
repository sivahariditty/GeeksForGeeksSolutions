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

Node *findMinNode(Node *root){
   Node *curr = root;
   while(curr && (curr->left != NULL)){
      curr = curr->left;
   }
   return curr;
}
Node *delNode(Node *root, int val){
   if(root == NULL)
      return root;
   if(val < root->data){
      root->left = delNode(root->left,val);
   }
   else if(val > root->data){
      root->right = delNode(root->right,val);
   }
   else{
      if(root->left == NULL && root->right == NULL){
         return NULL;
      }
      else if(root->left == NULL){
         struct Node *tmp = root->right;
	 free(root);
	 return tmp;
      }
      else if(root->right == NULL){
         struct Node *tmp = root->left;
	 free(root);
	 return tmp;
      }
      struct Node *tmp= findMinNode(root->right);
      root->data = tmp->data;
      root->right = delNode(root->right,tmp->data);
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
   int delval;
   while(1){
   cin>>delval;
   rtr = delNode(rtr,delval);
   inOrder(rtr);
   cout<<"\n";
   }
   return 0;
}
