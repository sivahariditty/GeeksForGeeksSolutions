#include <bits/stdc++.h>
using namespace std;

bool check(string str1, string str2){
   if(str1.length() != str2.length()){
      if(str1.length() > str2.length()+1){
         return false;
      }
      else{
	 int ind1=0,ind2=0;
         while(ind1<str1.length() && ind2<str2.length()){
	    if(str1[ind1] != str2[ind2]){
	       if(ind1 != ind2)
	          return false;
	       ind2++;
	    }
	    else{
	       ind2++;
	       ind1++;
	    }
	 }
      }
   }
   else{
      bool isM = false;
      for(int i=0;i<str2.length();i++){
         if(str1[i] != str2[i]){
	    if(isM)
	       return false;
	    isM = true;
         }
      }
   }
   return true;
}

int main(){
   string str1 = "abcd";
   string str2 = "aebcd";
   if(check(str1,str2))
      cout<<"yes";
   
}
