class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    // 2 nested Linear-search
    int specialArray(vector<int>& nums) { 
        int n=nums.size();

        for(int x=1; x<=n; x++)
        {
            int count = 0;

            for(int num: nums)
            {
                if(num >= x)
                    count++;
                if(count > x)
                    break;
            }
            
            if(count == x)
                return x;
        }

        return -1;
    }
};