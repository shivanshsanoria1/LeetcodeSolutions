class Solution {
public:
    // T.C.=O(n * min(k, n)), S.C.=O(n)
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        // an element can win atmost (n-1) games
        // against the remaining elements
        if(k >= n)
            k = n-1;

        // num -> win freq
        unordered_map<int, int> mp;
        deque<int> dq(arr.begin(), arr.end());

        while(true)
        {
            int curr1 = dq.front();
            dq.pop_front();
            int curr2 = dq.front();
            dq.pop_front();

            int maxVal = max(curr1, curr2);
            int minVal = min(curr1, curr2);
            
            dq.push_front(maxVal);
            dq.push_back(minVal);

            if(++mp[maxVal] == k)
                return maxVal;
        }

        return -1;
    }
};