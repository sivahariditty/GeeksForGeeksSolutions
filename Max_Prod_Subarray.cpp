// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	int min(int x, int y) { return x < y ? x : y; }
	int max(int x, int y) { return x > y ? x : y; }
	long long maxProduct(vector<int> arr, int n) {
	    if(n==1)
	       return arr[0];
	    long long MAX = 1,MIN = 1,OVMAX = 0;
	    for(int i=0;i<n;i++){
	        if(arr[i]>0){
	            MAX = MAX * arr[i];
	            MIN = min(MIN*arr[i],1);
	        }
	        else if(arr[i] == 0){
	            MAX = MIN = 1;
	        }
	        else {
	            long long tmp = MAX;
	            MAX = max(MIN * arr[i],1);
	            MIN = tmp * arr[i];
	            
	        }
	        if(OVMAX < MAX)
	           OVMAX = MAX;
	    }
	    return OVMAX;
	    // code here
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
