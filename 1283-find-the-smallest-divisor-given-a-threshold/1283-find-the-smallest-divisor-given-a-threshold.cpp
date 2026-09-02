class Solution {

    int check(int mid,vector<int>& nums, int threshold){
        int ans=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]+mid-1)/mid;
            
                    }
                    return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        int start=1;
        int end=INT_MIN;

        

        for(int i=0;i<nums.size();i++){
            
            end=max(end,nums[i]);

        }
        int ans=start;

        while(start<=end){

            int mid=start+(end-start)/2;

            int sol=check(mid,nums,threshold);

            if(sol<=threshold){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

        return ans;
        
    }
};