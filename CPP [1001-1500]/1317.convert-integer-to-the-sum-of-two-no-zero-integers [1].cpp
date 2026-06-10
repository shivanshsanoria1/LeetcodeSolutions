class Solution {
public:
    bool isNoZeroInt(int n){
        while(n > 0)
        {
            if(n % 10 == 0)
                return false;
            n /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for(int a=1; a<=n/2; a++)
        {
            int b = n - a;
            if(isNoZeroInt(a) && isNoZeroInt(b))
            {
                ans.push_back(a);
                ans.push_back(b);
                break;
            }
        }
        return ans;
    }
};