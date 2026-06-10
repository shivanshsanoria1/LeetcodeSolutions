class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq; // max-heap
        for(int amt: amount)
            if(amt > 0)
                pq.push(amt);

        int t = 0; // time
        while(!pq.empty())
        {
            t++;

            int curr1 = pq.top();
            pq.pop();
            curr1--;

            int curr2 = -1;
            if(!pq.empty())
            {
                curr2 = pq.top();
                pq.pop();
            }
            curr2--;

            if(curr1 > 0)
                pq.push(curr1);
            if(curr2 > 0)
                pq.push(curr2);
        }
        return t;
    }
};