// { Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


 // } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
       Node *ptr1, *ptr2;
       ptr1 = head->next; 
       ptr2 = head;
       while(ptr1 != NULL){
           ptr1 = ptr1->next->next;
           ptr2 = ptr2->next;
           if(ptr1 == ptr2){
               breakLoop(ptr1,ptr2,head);
               break;
           }
       }
    }
    void breakLoop(Node *ptr1, Node *ptr2, Node* head){
        int k=1;
        ptr1 = ptr1->next;
        while(ptr1 != ptr2){
            k++;
            ptr1 = ptr1->next;
        }
        ptr1 = ptr2 = head;
        for(int i=0;i<k;i++){
            ptr1 = ptr1->next;
        }
        Node *Prev;
        while(ptr1 != ptr2){
            //Prev = ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            
        }
	for(int i=0;i<k-1;i++){
            ptr1 = ptr1->next;
        }
        ptr1->next = NULL;
        //Prev->next = NULL;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
  // } Driver Code Ends
