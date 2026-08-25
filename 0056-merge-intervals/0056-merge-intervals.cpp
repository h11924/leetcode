class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        for(int i=0;i<intervals.size();i++){

            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
                //this was teh case where everythinhg is going well
            }

            else {
                //we got the new element to be greater than ans.back
                //ans[1].back()=max(ans[1].back(), intervals[i][1]);
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
        
    }
};