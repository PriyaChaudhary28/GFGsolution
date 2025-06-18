class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        unordered_map<int,int>mp;
        for(int i:a){
            mp[i]++;
            
        }
        int cnt=0;
        for(int j:b){
            if(mp[j]){
                cnt++;
                mp[j]--;
            }
        }
        if(cnt==b.size()) return true;
        return false;
        
    }
};