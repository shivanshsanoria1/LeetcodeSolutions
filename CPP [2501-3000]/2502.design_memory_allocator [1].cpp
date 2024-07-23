class Allocator {
private:
    vector<int> memory;

public:
    Allocator(int n) {
        this->memory.resize(n, 0);
    }
    
    // T.C.=O(n); 2-pointer
    int allocate(int size, int mID) {
        int left = 0, right = 0;
        bool blockFound = false;

        while(right < memory.size())
        {
            // not-free memory unit
            if(memory[right] != 0)
                left = right + 1;
            // free memory unit
            else if(right - left + 1 == size)
            {
                blockFound = true;
                break;
            }

            right++;
        }

        // free memory of 'size' units not found
        if(!blockFound)
            return -1;

        // assign memory in range [left, right] an id 'mID'
        for(int i=left; i<=right; i++)
            memory[i] = mID;
        
        return left;
    }
    
    // T.C.=O(n)
    int free(int mID) {
        int units = 0;
        for(int i=0; i<memory.size(); i++)
            if(memory[i] == mID)
            {
                memory[i] = 0;
                units++;
            }
        
        return units;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */