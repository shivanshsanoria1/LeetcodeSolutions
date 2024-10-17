class Solution {
public:
    // T.C.=O(a + b + c), S.C.=O(1)
    // Greedy
    string longestDiverseString(int a, int b, int c) {
        // max-heap; {freq, char}
        priority_queue<pair<int, char>> pq;

        if(a > 0)
            pq.push({a, 'a'});
        if(b > 0)
            pq.push({b, 'b'});
        if(c > 0)
            pq.push({c, 'c'});

        string ans = "";
        while(!pq.empty())
        {
            auto [freq1, ch1] = pq.top();
            pq.pop();

            if(!ans.empty() && ans.back() == ch1)
            {
                if(pq.empty())
                    break;

                auto [freq2, ch2] = pq.top();
                pq.pop();

                ans += ch2;
                
                if(--freq2 > 0)
                    pq.push({freq2, ch2});
                
                pq.push({freq1, ch1});
            }
            else
            {
                if(freq1 >= 2)
                {
                    ans += string(2, ch1);
                    pq.push({freq1 - 2, ch1});
                }
                else if(freq1 == 1)
                    ans += ch1;
            }
        }

        return ans;
    }
};