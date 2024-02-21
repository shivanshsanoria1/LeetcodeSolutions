class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n=sentence.length();
        char prev = '#', curr = '#'; 
        for(int i=0; i<n; i++)
        {
            prev = curr;
            if(sentence[i] == ' ')
            {
                i++;
                curr = i < n ? sentence[i] : sentence[0];
                if(prev != curr)
                    return false;
            }
            else
                curr = sentence[i];
        }
        return sentence[0] == sentence[n-1] ? true : false;
    }
};