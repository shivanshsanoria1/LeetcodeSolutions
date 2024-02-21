class Solution {
public:
    bool checkIfExist(vector<int>& arr) { // T.C.=O(n), S.C.=O(n)
        unordered_set<int> s;
        for(int num: arr)
        {
            if(s.find(2*num) != s.end())
                return true;
            if(num % 2 == 0 && s.find(num/2) != s.end())
                return true;
            s.insert(num);
        }
        return false;
    }
};