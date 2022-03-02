// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           //Write your code here
          if(s.empty())
              return -1;
          return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
          if(s.empty())
              return -1;
          else{
	     int tmp1 = s.top(), tmp2;
	     s.pop();
	     if(tmp1<minEle){
	        tmp2 = minEle;
	        minEle = 2*minEle - tmp1;
		return tmp2;
	     }
	     else{
	        return tmp1;
	     }
          }
           //Write your code here
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(s.empty()){
              s.push(x);
	      minEle = x;
	   }
	   else{
	      if(x<minEle){
	         int tmp = 2*x - minEle;
		 s.push(tmp);
		 minEle = x;
	      }
	      else {
		 s.push(x);
	      }
	   }
           //Write your code here
       }
};

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends
