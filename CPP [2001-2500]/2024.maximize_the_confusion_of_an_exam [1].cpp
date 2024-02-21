class Solution {
public:
    // returns the max length of substring with atmost k 'check' chars
    int solve(string& s, int k, char check){ // sliding-window
        int n=s.length();
        int left = 0, right = 0;
        int count = 0;
        int maxLen = 0; // max length of substring
        while(right < n)
        {
            if(s[right] == check)
                count++;
            // reduce the size of window until there are k 'check' chars
            if(count == k + 1)
                while(count != k)
                {
                    if(s[left] == check)
                        count--;
                    left++;
                }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }

    int maxConsecutiveAnswers(string answerKey, int k) { // T.C.=O(n), S.C.=O(1)
        // max length of substring with atmost k 'F' chars
        int convertToTrue = solve(answerKey, k, 'F');
        // max length of substring with atmost k 'T' chars
        int convertToFalse = solve(answerKey, k, 'T');
        return max(convertToTrue, convertToFalse);
    }
};