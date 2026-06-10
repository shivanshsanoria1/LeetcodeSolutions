class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n=nums.size(), val=1, parSum=0;
        for(int i=0; i<n; i++)
        {
            parSum=parSum+nums[i];
            if(parSum<0)
                if(abs(parSum)>=val)
                    val=abs(parSum)+1;
        }
        return val;
    }
};