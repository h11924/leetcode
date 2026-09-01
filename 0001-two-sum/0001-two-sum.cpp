class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int, int>> vec;
        for(int i = 0; i < nums.size(); i++) {
            vec.push_back({nums[i], i});
        }

        sort(vec.begin(), vec.end());

        int start = 0;
        int end = nums.size() - 1;

        while(start < end){
            // FIX: Use .first to get the integer values stored in the pairs
            int sum = vec[start].first + vec[end].first;

            if(sum == target){
                return {vec[start].second, vec[end].second};
            }
            else if (sum > target){
                end--;
            } else {
                start++;
            }
        }

        return {}; // Return empty vector if no pair is found
    }
};