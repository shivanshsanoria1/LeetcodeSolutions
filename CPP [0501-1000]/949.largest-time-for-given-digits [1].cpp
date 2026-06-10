class Solution {
private:
    // returns true if the digits in arr[] 
    // can be rearranged to make the string hhmm
    bool canMake(vector<int>& arr, string& hhmm){
        vector<bool> visited(5, false);

        for(int i=0; i<4; i++)
            for(int j=0; j<5; j++)
            {
                if(visited[j])
                    continue;

                if(arr[i] == hhmm[j] - '0')
                {
                    visited[j] = true;
                    break;
                }
            }

        return count(visited.begin(), visited.end(), true) == 4;
    }

public:
    // T.C.=O(24*60), S.C.=O(1)
    string largestTimeFromDigits(vector<int>& arr) {
        for(int h=23; h>=0; h--)
            for(int m=59; m>=0; m--)
            {
                string hh = h <= 9 ? "0" + to_string(h) : to_string(h);
                string mm = m <= 9 ? "0" + to_string(m) : to_string(m);

                string hhmm = hh + ":" + mm;

                if(canMake(arr, hhmm))
                    return hhmm;
            }

        return "";
    }
};