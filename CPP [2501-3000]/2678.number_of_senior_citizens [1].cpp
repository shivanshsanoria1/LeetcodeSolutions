class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(string& detail: details)
        {
            int age = 10*(detail[11] - '0') + (detail[12] - '0');
            if(age > 60)
                count++;
        }

        return count;
    }
};