class LUPrefix {
private:
    vector<bool> vids;
    // all nums in index-range [1, idx]
    // (both-inclusive) are uploaded
    int idx = 0;

public:
    LUPrefix(int n) {
        this->vids.resize(n+1, false);
        // assume num 0 is uploaded
        vids[0] = true;

        this->idx = 0;
    }
    
    // T.C.=O(1)
    void upload(int video) {
        vids[video] = true;
    }
    
    // T.C.=O(n) (in worst case)
    int longest() {
        for(int i=idx; i<vids.size() && vids[i]; i++)
            idx = i;
        
        return idx;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */