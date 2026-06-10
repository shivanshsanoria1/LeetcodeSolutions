class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) { // T.C.=O(n), S.C.=O(n)
        int n = arr.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int num: arr)
        {
            mini = min(mini, num);
            maxi = max(maxi, num);
        }
        if((maxi - mini) % (n-1) != 0)
            return false;
        int diff = (maxi - mini)/(n-1);
        if(diff == 0) // all the nums are equal
            return true;
        unordered_set<int> s;
        for(int num: arr)
        {
            if((num - mini) % diff != 0)
                return false;
            s.insert(num);
        }
        return s.size() == n ? true : false;
    }
};
/*
# in AP the terms are of the form- a, a + d, a + 2d, ..., a + (n-1)d
# here, a is minimum and a + (n-1)d is maximum (assuming d > 0)
# (a + (n-1)d) - (a) is always divisible by (n-1) and gives d as quotient
# now, we can check for each term (of the form a + zd) if it belongs to this AP or not by-
# (a + zd) - (a) is divisible by d 
*/