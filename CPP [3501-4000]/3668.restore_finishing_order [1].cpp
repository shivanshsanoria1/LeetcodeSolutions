class Solution {
public:
    // T.C.=O(n*m), S.C.=O(1)
    // n: size of order[], m: size of friends[]
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> ans;
        for(int id: order)
            for(int fri: friends)
                if(id == fri)
                    ans.push_back(fri);

        return ans;
    }
};