class Solution {
public:
    // T.C.=O(b + n), S.C.=O(b)
    // b: size of banned[]
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> s;
        for(int num: banned)
            if(num <= n)
                s.insert(num);
        
        int sum = 0;
        int count = 0;
        for(int i=1; i<=n; i++)
        {
            if(s.find(i) != s.end())
                continue;
            
            sum += i;
            if(sum > maxSum)
                break;
            count++;
        }

        return count;
    }
};