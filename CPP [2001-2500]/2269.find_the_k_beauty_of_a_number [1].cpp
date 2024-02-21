class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str = to_string(num);
        int count = 0;
        for(int i=0; i <= str.length()-k; i++)
        {
            int currNum = stoi(str.substr(i, k));
            if(currNum != 0 && num % currNum == 0)
                count++;
        }
        return count;
    }
};