class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n=nums.size();
        while(1)
        {
            bool flag=false;
            for(int i=0; i<n; i++)
                if(nums[i] == original)
                    flag=true;
            if(flag==true) //original found in array
                original*=2;
            else //original not found in array
                break;
        }
        return original;
    }
};