class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = instructions.size();
        vector<bool> visited(n, false);
        int i = 0;
        long long int score = 0;

        while(i >= 0 && i < n && !visited[i])
        {
            visited[i] = true;
            if(instructions[i] == "add")
            {
                score += values[i];
                i++;
            }
            else // instructions[i] == "jump"
                i += values[i];
        }

        return score;
    }
};