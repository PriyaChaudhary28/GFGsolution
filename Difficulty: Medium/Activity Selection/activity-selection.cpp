class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n=start.size();
        // code here
       vector<pair<int,int>>act;
       for(int i=0;i<n;i++){
           act.push_back({finish[i],start[i]});
       }
       
       sort(act.begin(),act.end());
       
       int cnt=1;
       int lst=act[0].first;
       
       for(int i=1;i<n;i++){
           if(act[i].second>lst){
               cnt++;
               lst=act[i].first;
           }
           
           
       }
       return cnt;
        
    }
};