class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n=nums.size(), val=1;
        while(1)
        {
            int sum=val;
            bool flag=false;
            for(int i=0; i<n; i++)
            {
                sum=sum+nums[i];
                if(sum<1)
                {
                    flag=true;
                    break;
                }
            }
            if(flag==false)
                return val;
            val++;
        }
    }
};