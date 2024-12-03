//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
         string temp = s + '#' + string(s.rbegin(), s.rend());
    int n = temp.size();

    // Compute LPS array
    vector<int> lps(n, 0);
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j > 0 && temp[i] != temp[j]) {
            j = lps[j - 1];
        }
        if (temp[i] == temp[j]) {
            j++;
        }
        lps[i] = j;
    }

    // Minimum characters to add is the part of the string not part of the LPS
    return s.size() - lps.back();
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends