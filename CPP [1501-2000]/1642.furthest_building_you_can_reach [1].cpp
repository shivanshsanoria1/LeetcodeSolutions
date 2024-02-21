class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(n)
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq; // max-heap
        int n=heights.size();
        for(int i=0; i<n-1; i++)
        {
            int diff = heights[i+1] - heights[i];
            // no brick or ladder nedded
            if(diff <= 0)
                continue;

            pq.push(diff);

            // use bricks to make the jump
            bricks -= diff;
            // no more bricks left to make the jump
            if(bricks < 0)
            {
                // use ladder to make the largest jump till now
                if(ladders > 0)
                {
                    bricks += pq.top();
                    pq.pop();
                    ladders--;
                }
                // no more ladders left, ie, cannot make the jump
                else
                    return i;
            }
        }
        return n-1;
    }
};