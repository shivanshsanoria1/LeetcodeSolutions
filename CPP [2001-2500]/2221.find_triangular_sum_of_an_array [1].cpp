class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    int triangularSum(vector<int>& nums) {
        queue<int> q;
        for(int num: nums)
            q.push(num);

        while(q.size() > 1)
        {
            int size = q.size() - 1;
            while(size--)
            {
                int a = q.front();
                q.pop();
                q.push((a + q.front()) % 10);
            }
            q.pop();
        }
        return q.front();
    }
};