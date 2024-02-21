class Solution {
public:
    bool isSelfDividing(int num)
    {
        int n=num, rem;
        while(n>0)
        {
            rem=n%10;
            n=n/10;
            if(rem==0 || num%rem!=0)
                return false;
        }
        return true;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left; i<=right; i++)
            if(isSelfDividing(i)==true)
                ans.push_back(i);
        return ans;
    }
};