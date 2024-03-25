class Bitset {
private:
    vector<bool> bits;
    int ones = 0;
    int zeros = 0;

public:
    Bitset(int size) {
        this->bits.resize(size, false);
        this->ones = 0;
        this->zeros = size;
    }
    
    // T.C.=O(1)
    void fix(int idx) {
        if(bits[idx])
            ones--;
        else
            zeros--;

        bits[idx] = true;

        ones++;
    }
    
    // T.C.=O(1)
    void unfix(int idx) {
        if(bits[idx])
            ones--;
        else
            zeros--;

        bits[idx] = false;

        zeros++;
    }
    
    // T.C.=O(n)
    void flip() {
        for(int i=0; i<bits.size(); i++)
            bits[i] = !bits[i];

        swap(ones, zeros);
    }
    
    // T.C.=O(1)
    bool all() {
        return ones == bits.size();
    }
    
    // T.C.=O(1)
    bool one() {
        return ones > 0;
    }
    
    // T.C.=O(1)
    int count() {
        return ones;
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