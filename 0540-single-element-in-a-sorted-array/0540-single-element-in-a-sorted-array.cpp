class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n=nums.size();

        //first apperace should be in odd position(before the double)

        //but later first postion should be in even position

        // Edge case: single element array
        if (n == 1) return nums[0];

        // Edge case: single element is at index 0
        if (nums[0] != nums[1]) return nums[0];

        // Edge case: single element is at the last index
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int start=0;
        int end=nums.size()-1;

        while(start<=end){
            int mid=start+(end-start)/2;
            //the elemenst is in mid
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }

            else if((nums[mid]==nums[mid-1] && mid%2==1) || 
                (nums[mid]==nums[mid+1] && mid%2==0)){
                //the second number is mid and it is even index 
                //means everything to its left is not required

                start=mid+1;
            }
            else {
                end=mid-1;
            }
        }

        return -1;

    }
        
    
};

//normal- even is second
//odd is one 