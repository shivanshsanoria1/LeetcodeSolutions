class Solution {
public:
    // T.C.=O(), S.C.=O()
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for(int i=1; i<=9; i++)
            q.push(i);
        vector<int> ans;
        while(!q.empty() && q.front() <= high)
        {
            int num = q.front();
            q.pop();
            if(num >= low)
                ans.push_back(num);
            int dig = num % 10 + 1;
            if(dig <= 9)
                q.push(10*num + dig);
        }
        return ans;
    }
};