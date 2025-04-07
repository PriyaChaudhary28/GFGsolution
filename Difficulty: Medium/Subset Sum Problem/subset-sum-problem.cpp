//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        // tabulation 
 int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, false));
        
        // Base case: sum = 0 can always be formed by empty subset
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // Base case: if first element is within sum
        if (arr[0] <= sum) {
            dp[0][arr[0]] = true;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= sum; j++) {
                bool nonpick = dp[i - 1][j];
                
                bool pick = false;
                // 🔥 Fix is here: use j (current target), not sum
                if (arr[i] <= j) {
                    pick = dp[i - 1][j - arr[i]];
                }

                dp[i][j] = pick || nonpick;
            }
        }

        return dp[n - 1][sum];
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