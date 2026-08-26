class Solution {

    private:

    void merge(int start,int mid,int end,vector<int>& nums){
        int left=start;
        int right=mid+1;

        vector<int> temp;

        while(left<=mid && right<=end){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }

        }

        while(right<=end){
            temp.push_back(nums[right]);
            right++;

        }

        while(left<=mid){
             temp.push_back(nums[left]);
            left++;

        }

        for(int i=0;i<temp.size();i++){
            nums[start+i]=temp[i];
        }

        

      
    }




    void mergesort(int start,int end,vector<int>& nums){

        if (start >= end) return;

        int mid=start+(end-start)/2;

        mergesort(start,mid,nums);
        mergesort(mid+1,end,nums);

        merge(start,mid,end,nums);

    }
public:
    vector<int> sortArray(vector<int>& nums) {

        mergesort(0,nums.size()-1,nums);

        return nums;
        
    }
};