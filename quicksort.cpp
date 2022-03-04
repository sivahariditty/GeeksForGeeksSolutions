#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int l,int r){
   int piv = arr[r],j=l,tmp;
   for(int i=l;i<r;i++){
      if(arr[i] < piv){
         tmp = arr[i];
	 arr[i] = arr[j];
	 arr[j] = tmp;
	 j++;
      }
   }
   tmp = arr[j];
   arr[j] = arr[r];
   arr[r] = tmp;
   return j;
}
void quicksort(int arr[],int low,int high){
   if(low < high){
      int piv = partition(arr,low,high);
      quicksort(arr,low,piv-1);
      quicksort(arr,piv+1,high);
   }
}

int main(){
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
      cin>>arr[i];
   }
   quicksort(arr,0,n-1);
   for(int i=0;i<n;i++){
      cout<<arr[i]<<"\n";
   }
}
