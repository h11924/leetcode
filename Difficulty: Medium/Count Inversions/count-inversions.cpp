class Solution {
    
    private:
    void merge(int start,int end,vector<int>&arr,int &count,int mid){
        int left=start;
        int right=mid+1;
        
        vector<int> temp;
        
        
        while(left<=mid && right<=end){
            
            if(arr[left]>arr[right]){
                temp.push_back(arr[right]);
                right++;
                count+=mid-left+1;
            }else{
                temp.push_back(arr[left]);
                left++;
            }
            
        }
        
        while(left<=mid){
             temp.push_back(arr[left]);
                left++;
                
            
        }
        
        while(right<=end){
              temp.push_back(arr[right]);
              right++;
            
        }
        
        for(int i=0;i<temp.size();i++){
            arr[start+i]=temp[i];
        }
        
        
        
        
        
    }
    
    void mergesort(int start,int end,vector<int>&arr,int &count){
        if(start>=end) return;
        
        int mid=start+(end-start)/2;
        
        mergesort(start,mid,arr,count);
        mergesort(mid+1,end,arr,count);
        
        merge(start, end, arr, count, mid);
        
        
    }
  public:
    int inversionCount(vector<int> &arr) {
        
        int count=0;
        mergesort(0,arr.size()-1,arr,count);
        return count;
        // code here
        
    }
};