class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n=colors.size();
        int count = 0;
        for(int i=0; i<n; i++)
            if(colors[(i-1+n) % n] != colors[i] && colors[i] != colors[(i+1) % n])
                count++;
        
        return count;
    }
};