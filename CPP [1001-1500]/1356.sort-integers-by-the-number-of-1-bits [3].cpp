class Solution {
public:
    static int countSetBits(int n)
    {
        int c=0;
        while(n)
        {
            if((n & 1) == 1)
                c++;
            n=n>>1;
        }
        return c;
    }
    
    static bool cmp(const int& a, const int& b)
    {
        int c1 = countSetBits(a);
        int c2 = countSetBits(b);
        return (c1 == c2) ? (a < b) : (c1 < c2);
    }
    
    vector<int> sortByBits(vector<int>& arr) { //using comparator
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};