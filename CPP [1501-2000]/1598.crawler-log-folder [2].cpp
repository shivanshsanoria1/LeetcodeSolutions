class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minOperations(vector<string>& logs) {
        int count = 0;

        for(string& log: logs)
        {
            if(log == "../")
                count = max(count - 1, 0);
            else if(log != "./")
                count++;
        }

        return count;
    }
};