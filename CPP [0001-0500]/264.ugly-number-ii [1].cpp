class Solution {
public:
    int nthUglyNumber(int n) {
        // multipliers
        vector<int> muls = { 2, 3, 5 };
        // min-heap
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_set<int> s;
        s.insert(1);
        pq.push(1);

        // run the loop for (n-1) times
        while(--n)
        {
            int curr = pq.top();
            pq.pop();

            for(int mul: muls)
            {
                long long int next = (long long int)curr * mul;
                // next val is out of int range
                if(next > INT_MAX)
                    continue;
                // next val already present in set
                if(s.find(next) != s.end())
                    continue;
                
                s.insert(next);
                pq.push(next);
            }
        }

        return pq.top();
    }
};