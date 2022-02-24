// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int b = 0,e = 0,i;
        long long sum = 0;
        vector<int> res;
        while(true){
           if(sum < s){
              sum = sum + arr[e];
              e++;
           }
           else if(sum > s){
              sum = sum - arr[b];
              b++;
           }
           else {
               res.push_back(b+1);
               res.push_back(e);
               break;
           }
        }
        return res;
        // Your code here
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
