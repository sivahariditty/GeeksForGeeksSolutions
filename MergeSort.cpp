#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;

int merge(int arr[],int low,int mid,int high){
   int n1 = mid - low +1;
   int n2 = high - mid;
   int left[n1], right[n2];
   for(int i=0;i<n1;i++){
      left[i] = arr[low + i];
   }
   for(int j=0;j<n2;j++){
      right[j] = arr[mid + 1 + j];
   }
   int ind1 = 0,ind2 = 0, mind = low;
   while(ind1 < n1 && ind2 < n2){
      if(left[ind1]<right[ind2]){
         arr[mind] = left[ind1];
	 ind1++;
      }
      else{
         arr[mind] = right[ind2];
	 ind2++;
      }
      mind ++;
   }
   while(ind1 < n1 && ind2 >= n2){
      arr[mind] = left[ind1];
      ind1++;
      mind ++;
   }
   while(ind1 >= n1 && ind2 < n2){
      arr[mind] = right[ind2];
      ind2++;
      mind ++;
   }
}
void mergeSort(int arr[],int low,int high){
   if(low >=high){
      return;
   }
      int mid = (low+high)/2;
      mergeSort(arr,low,mid);
      mergeSort(arr,mid+1,high);
      merge(arr,low,mid,high);
}

int main(){
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
      cin>>arr[i];
   }
   mergeSort(arr,0,n-1);
   for(int i=0;i<n;i++){
      cout<<arr[i]<<"\n";
   }
}
