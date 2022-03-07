// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 

Node *reurnKth(Node* head, int k){
   struct Node *ptr1 = head, *ptr2 = head;
   for(int i=0;i<k;i++){
      if(ptr1)
         ptr1 = ptr1->next;
      else
	 return NULL;
   }
   while(ptr1 != NULL){
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
   }
   return ptr2;
}

 // } Driver Code Ends
/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        Node *ptr1 = head, *ptr2 = head;
        while(ptr1->next != NULL){
            if(ptr1->next->next)
               ptr1 = ptr1->next->next;
	    else
               ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr2->data;
        // Your code here
    }
};


// { Driver Code Starts.

int main() {
    //code
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
	int k;
	cout<<"Enter K : ";
        cin>>k;
        
        Node *kth = reurnKth(head,k);
        cout << kth->data << endl;
    return 0;
}
  // } Driver Code Ends
