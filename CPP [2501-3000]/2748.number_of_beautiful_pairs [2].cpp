class Solution {
public:
    int gcd(int a, int b){
        while(a > 0 && b > 0)
        {
            if(a > b)
                a = a % b;
            else
                b = b % a;
        }
        return a == 0 ? b : a;
    }

    int countBeautifulPairs(vector<int>& nums) {
        int n=nums.size();
        int count = 0;
        for(int i=0; i<n-1; i++)
        {
            int v1 = to_string(nums[i])[0] - '0';
            for(int j=i+1; j<n; j++)
            {
                int v2 = nums[j] % 10;
                if(gcd(v1, v2) == 1)
                    count++;
            }
        }
        return count;
    }
};