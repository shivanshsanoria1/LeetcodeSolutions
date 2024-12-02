class Solution {
public:
    // T.C.=O(n + 2000), S.C.=O(2000)
    bool checkIfExist(vector<int>& arr) {
        vector<bool> found(2001, false);
        int offset = 1000;

        for(int num: arr)
        {
            if(2*num + offset < found.size() && found[2*num + offset])
                return true;
            if(num % 2 == 0 && found[num/2 + offset])
                return true;

            found[num + offset] = true;
        }

        return false;
    }
};