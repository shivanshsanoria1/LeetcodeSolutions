class Bitset {
private:
    vector<bool> bits;

public:
    Bitset(int size) {
        this->bits.resize(size, false);
    }
    
    // T.C.=O(1)
    void fix(int idx) {
        bits[idx] = true;
    }
    
    // T.C.=O(1)
    void unfix(int idx) {
        bits[idx] = false;
    }
    
    // T.C.=O(n)
    void flip() {
        for(int i=0; i<bits.size(); i++)
            bits[i] = !bits[i];
    }
    
    // T.C.=O(n)
    bool all() {
        for(bool bit: bits)
            if(!bit)
                return false;
        return true;
    }
    
    // T.C.=O(n)
    bool one() {
        for(bool bit: bits)
            if(bit)
                return true;
        return false;
    }
    
    // T.C.=O(n)
    int count() {
        int bitCount = 0;
        for(bool bit: bits)
            bitCount += bit;
        return bitCount;
    }
    
    // T.C.=O(n)
    string toString() {
        string bitsStr = "";
        for(bool bit: bits)
            bitsStr += bit ? "1" : "0";
        return bitsStr;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */