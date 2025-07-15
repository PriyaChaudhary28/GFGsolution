class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int n=arr.size();
         int cnt=1;
         sort(arr.begin(),arr.end());
         for(int i=0;i<n;i++){
             if(arr[i]<=0) continue;
             if(arr[i]==cnt && arr[i]!=arr[i+1]) cnt++;
             else if(arr[i]!=cnt) {
                 break;
             }
         }
         return cnt;
    }
};