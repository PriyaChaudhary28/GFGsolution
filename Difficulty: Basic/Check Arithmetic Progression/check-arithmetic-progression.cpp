class Solution {
  public:
    bool checkIsAP(vector<int> &arr) {
        // Your code goes here
        int i=1;
        unordered_map<int,int>mp;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        while(i<n){
            int diff=arr[i]-arr[i-1];
            mp[diff]++;
            i++;
        }
        if(mp.size()==1) return true;
        return false;
    }
};