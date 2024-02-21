class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        queue<int> q;
        for(int num: nums)
            q.push(num);
            
        // flip: true for min(), false for max()
        bool flip = true;
        while(q.size() > 1)
        {
            int a = q.front();
            q.pop();
            int b = q.front();
            q.pop();

            if(flip)
                q.push(min(a, b));
            else
                q.push(max(a, b));
                
            flip = !flip;
        }
        return q.front();
    }
};