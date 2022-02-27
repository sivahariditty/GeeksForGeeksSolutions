// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        int count[n] = {0}, flg = 0;
        vector<int> ret;
        for(int i=0;i<n;i++){
	    int ind = arr[i];
            count[ind]++;
        }
	for(int i=0;i<n;i++){
	   if(count[i] > 1){
              ret.push_back(i);
	      flg = 1;
	   }
        }
	if(flg == 1)
           return ret;
	else {
	   ret.push_back(-1);
           return ret;
	}
        // code here
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
