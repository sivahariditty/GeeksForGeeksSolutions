#include <bits/stdc++.h>
using namespace std;

void findSubstr(char chars[],string str,int n){
   int count[n] = {0},ucount=0;
   for(int i=0;i<str.length();i++){
      for(int k=0;k<n;k++){
         if(str[i] == chars[k])
	    count[k]++;
      }
   }
}

int main(){
   int n;
   cin>>n;
   char chars[n];
   for(int i=0;i<n;i++){
      cin>>chars[i];
   }
   string str;
   cout<<"Enter the string : ";
   cin>>str;
   findSubStr(chars,str,n);
}
