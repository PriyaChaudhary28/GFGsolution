//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
    private:
    bool f(int i,vector<int>&arr, int t,vector<vector<int>>&dp){
        //base case
        if(t==0) return true;
        if(i==0) return arr[0]==t;
        if(dp[i][t]!=-1) return dp[i][t];
        //recursive call
       bool pick = false;
        bool notpick=f(i-1,arr,t,dp);
        if(arr[i]<=t)
            
         pick=f(i-1,arr,t-arr[i],dp);
        
         return dp[i][t]=notpick || pick;
        
        
    }
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
       return f(n-1,arr,target,dp);
        // code here
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends