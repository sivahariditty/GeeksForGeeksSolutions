// { Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    int c1=0,c2=0,flg,diff;
    struct Node *ptr1=head1, *ptr2=head2;
    while(ptr1 != NULL){
        ptr1 = ptr1->next;
        c1++;
    }
    while(ptr2 != NULL){
        ptr2 = ptr2->next;
        c2++;
    }
    cout<<c1<<" : "<<c2<<"\n";
    if(c1>c2){
        flg = 1;
        diff = c1-c2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        flg = 2;
        diff = c2-c1;
        c1=c2;
        ptr1 = head2;
        ptr2 = head1;
    }
    for(int i=0;i<diff;i++){
       ptr1=ptr1->next;   
    }
    for(int j=diff;j<c1;j++){
        if(ptr1 == ptr2)
           return ptr1->data;
       ptr1=ptr1->next;   
       ptr2=ptr2->next;   
	
    }
    return NULL;
    // Your Code Here
}


