class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int left = startIndex, right = startIndex;
        for(int step=0; step<n; step++)
        {
            if(words[left] == target || words[right] == target)
                return step;

            left = (left - 1 + n) % n;
            right = (right + 1) % n;
        }
        return -1;
    }
};