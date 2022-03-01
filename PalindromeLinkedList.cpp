// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        int n = 0;
        struct Node *ptr = head,*curr = head,*prev,*next;
        while(ptr != NULL){
            ptr = ptr->next;
            n++;
        }
	printf("No of ele : %d\n",n);
        for(int i=0;i<(int)((n)/2);i++){
            curr = curr->next;
        }
	printf("curr data : %d\n",curr->data);
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
	printf("pre data pre next data : %d : %d\n",prev->data,prev->next->data);
        ptr = head;
        for(int j=0;j<(int)(n/2);j++){
	    printf("pali data : %d : %d\n",ptr->data,prev->data);
            if(ptr->data != prev->data){
                return 0;
            }
	    ptr = ptr->next;
	    prev = prev->next;
        }
        return 1;
        //Your code here
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends
