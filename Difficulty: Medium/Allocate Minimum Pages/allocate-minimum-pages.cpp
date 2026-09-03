class Solution {
    
    int check(long long  mid,vector<int> &arr, int k){
        int allocations=1;
        long long  sum=0;
        /*for(int i=0;i<arr.size();i++){
            if(sum>=mid){
                sum=0;
                allocations++;
            }else{
                sum+=arr[i];
            }
        }*/
        
        for(int i=0;i<arr.size();i++){
            // Mistake: you used if(sum>=mid)
            // We need to check if adding the current book exceeds mid
            if(sum+arr[i]>mid){
                // Mistake: you used sum=0
                // Current book must go to the new student
                sum=arr[i];
                allocations++;
            }else{
                sum+=arr[i];
            }
        }
        
        return allocations;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
         if(k>arr.size()) return -1;
        long long  start=0;
        long long  end=0;
        
        for(int i=0;i<arr.size();i++){
            start=max(start,(long long)arr[i]);
            end=end+arr[i];
        }
        
        long long ans=-1;
        
        while(start<=end){
            long long mid=start+(end-start)/2;
            
            int allocations=check(mid,arr,k);
            
            if(allocations<=k){
                //if allocations are less means we are giving more pages so move back
                ans=mid;
                end=mid-1;
            }
            //if allocatuions are more means we are giving less pages so move forward
            else{
                start=mid+1;
            }
          
            
        }
        
        return (int )ans;
        
    }
};