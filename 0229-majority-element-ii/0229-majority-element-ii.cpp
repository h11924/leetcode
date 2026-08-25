class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int ele1=INT_MIN;
        int ele2=INT_MIN;
        int count1=0;
        int count2=0;

        vector<int> ans ;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1){
                count1++;
            }else if (nums[i]==ele2){
                count2++;
            }else if (count1==0 && ele2!=nums[i]){
                ele1=nums[i];
                count1++;
            }else if (count2==0 && ele1!=nums[i]){
                ele2=nums[i];
                count2++;
            }else {
                count1--;
                count2--;
            }
        }

        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1) cnt1++;
            if(nums[i]==ele2) cnt2++;
        }

        if(cnt1> nums.size()/3) ans.push_back(ele1);
        if(cnt2> nums.size()/3) ans.push_back(ele2);

        return ans;
        
    }
};