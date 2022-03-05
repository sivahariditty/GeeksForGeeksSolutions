#include <bits/stdc++.h>
using namespace std;

void urlify(char str[],int n){
   int cnt=0;
   for(int i=0;i<n;i++){
      if(str[i] == ' '){
         cnt++;
      }
   }
   for(int i=n-1;i>=0;i--){
      if(str[i] == ' '){
         str[i+2*cnt] = '0';
         str[i+2*cnt-1] = '2';
         str[i+2*cnt-2] = '%';
	 cnt--;
      }
      else{      
         str[i+2*cnt] = str[i];
      }
   }
}

int main(){
   string inpstr;
   char str[500] = "abcd ed  ed df ";
   int n=15;
   urlify(str,n);
   cout<<str;
}
