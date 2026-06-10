class Solution {
public:
    // T.C.=O(n + m), S.C.=O(n)
    // n: size of order[], m: size of friends[]
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<bool> isFriend(order.size() + 1, false);
        for(int id: friends)
            isFriend[id] = true;
        
        vector<int> ans;
        for(int id: order)
            if(isFriend[id])
                ans.push_back(id);

        return ans;
    }
};