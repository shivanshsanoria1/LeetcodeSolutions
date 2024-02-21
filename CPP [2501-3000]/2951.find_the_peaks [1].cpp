class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    vector<int> findPeaks(vector<int>& mountain) { 
        vector<int> peaks;
        for(int i=1; i<mountain.size()-1; i++)
            if(mountain[i-1] < mountain[i] && mountain[i] > mountain[i+1])
                peaks.push_back(i);
        return peaks;
    }
};