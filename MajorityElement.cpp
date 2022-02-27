// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdbool.h>


 // } Driver Code Ends
//User function Template for C

// Function to find majority element in the array
// a: input array
// size: size of input array
int findCandidate(int a[], int size){
    int maj_ind = 0, count = 1;
    for(int i=1;i<size;i++){
        if(a[i] == a[maj_ind]){
            count++;
        }
        else{
            count--;
        }
        if(count == 0){
            maj_ind = i;
            count = 1;
        }
    }
    return a[maj_ind];
}
int majorityElement(int a[], int size)
{
    int cand = findCandidate(a,size), count = 0;
    for(int i=0;i<size;i++){
       if(a[i] == cand)
          count++;
    }
    if(count>(int)(size/2))
       return cand;
    else
       return -1;
    // your code here
}

// { Driver Code Starts.

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        
        for(int i = 0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", majorityElement(arr, n));
    }

    return 0;
}
  // } Driver Code Ends
