#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;

bool isUnique(string str){
   int checker;
   for(int i=0;i<str.length();i++){
      int ch = str[i] - 'a';
      if((checker & (1<<ch)) > 0){
         return false;
      }
      checker = checker | (1<<ch);
   }
   return true;
}

int main(){
   string str;
   cin>>str;
   cout<<isUnique(str);
}
