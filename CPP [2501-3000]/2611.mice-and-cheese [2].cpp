class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) { // T.C.=O(n*logn), S.C.=O(n)
        int n=reward1.size();
        priority_queue<pair<int, int>> pq; // max-heap, {diff, index}
        for(int i=0; i<n; i++)
            pq.push({reward1[i] - reward2[i], i});
        int sum = 0;
        while(!pq.empty())
        {
            auto [diff, i] = pq.top();
            pq.pop();
            if(k > 0) // mouse1 eats the 1st k cheese
            {
                sum += reward1[i];
                k--;
            }
            else // mouse2 eats the remaining cheese
                sum += reward2[i];
        }
        return sum;
    }
};