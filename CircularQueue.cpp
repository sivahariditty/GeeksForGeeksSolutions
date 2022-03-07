// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int n,front = -1,rear=-1,no_ele=0;

void enQueue(int val, int *arr){
   if((front == 0 && rear == n-1) || (rear == front - 1)){
      cout<<"over flow front : "<<front<<" rear : "<<rear<<" n: "<<n;
      return;
   }
   if(rear == -1) {
      rear = front = 0;
      arr[rear] = val;
   }
   else if((rear == n-1) && front > 0){
      rear = 0;
      arr[rear] = val;
   }
   else{
      arr[++rear] = val;
   }
}

int deQueue(int *arr){
   if(front == -1){
      cout<<"under flow";
      return -1;
   }
   int ret = arr[front];
   if(front == rear){
      front = rear = -1;
   }
   else if(front == n-1){
      front = 0;
   }
   else {
      front ++;
   }
   return ret;
}	


void displayQueue(int *arr)
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ",arr[i]);
    }
    else
    {
        for (int i = front; i < n; i++)
            printf("%d ", arr[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
    }
}

int main() {
   cin>>n;
   int arr[n],opt,inp;
   while(1){
   cin>>opt;
   if(opt == 1){
      cin>>inp;
      enQueue(inp,arr);
   }
   else if(opt == 2){
      inp = deQueue(arr);
      cout<<inp;
   }
   else{
      displayQueue(arr);
   }
   }
   return 0;
}
  // } Driver Code Ends
