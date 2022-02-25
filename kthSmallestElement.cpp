// { Driver Code Starts
//Initial Template for C

#include<stdio.h>

 // } Driver Code Ends
//User function Template for C
void swap(int arr[], int a, int b){
    int tmp;
    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
int kthSmallest(int arr[], int l, int r, int k)
{
   //if (k > 0 && k <= r - l + 1) {
   int ck =  partition(arr, l, r);
   if(ck-l == k-1)
      return arr[ck];
   else if(ck-l > k-1)
      kthSmallest(arr, l, ck-1, k);
   else
      kthSmallest(arr, ck+1, r, k - ck + l - 1);
   //}
   //return INT_MAX;
}
int partition(int arr[], int l, int r){
    int i = l,x=arr[r];
    for(int j =l;j<r-1;j++){
        if(arr[j]<=x){
            swap(arr,i,j);
            i++;
        }
    }
    swap(arr,i,r);
    return i;
}

// { Driver Code Starts.
 
int main()
{
    int test_case;
    scanf("%d",&test_case);
    while(test_case--)
    {
        int number_of_elements;
        scanf("%d", &number_of_elements);
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            scanf("%d", &a[i]);
            
        int k;
        scanf("%d",&k);
        printf("%d",kthSmallest(a, 0, number_of_elements-1, k));
        printf("\n");
    }
    return 0;
}  // } Driver Code Ends
