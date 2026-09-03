class Solution {

    int check(int mid,vector<int>& nums,int k){
        int sum=0;
        int p=1; // CORRECTION: start with one partition

        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>mid){ // CORRECTION: create a partition when adding current element exceeds mid
                sum=nums[i]; // CORRECTION: current element starts the new partition
                p++;
            }
            else{
                sum+=nums[i];
            }
        }

        return p;
    }

public:
    int splitArray(vector<int>& nums,int k){

        int start=INT_MIN;
        int end=0;

        for(int i=0;i<nums.size();i++){
            start=max(start,nums[i]); // CORRECTION: minimum possible maximum sum is largest element
            end+=nums[i]; // maximum possible maximum sum is total sum
        }

        int ans=end;

        while(start<=end){
            int mid=start+(end-start)/2;

            int p=check(mid,nums,k);

            if(p<=k){ // CORRECTION: at most k partitions is valid
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }

        return ans;
    }
};