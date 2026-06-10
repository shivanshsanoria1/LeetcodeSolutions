class Bitset {
private:
    string bits = "";
    int ones = 0;
    int zeros = 0;

public:
    Bitset(int size) {
        this->bits.resize(size, '0');
        this->ones = 0;
        this->zeros = size;
    }
    
    // T.C.=O(1)
    void fix(int idx) {
        if(bits[idx] == '1')
            return;

        bits[idx] = '1';
        ones++;
        zeros--;
    }
    
    // T.C.=O(1)
    void unfix(int idx) {
        if(bits[idx] == '0')
            return;
        
        bits[idx] = '0';
        ones--;
        zeros++;
    }
    
    // T.C.=O(n)
    void flip() {
        for(int i=0; i<bits.size(); i++)
        {
            if(bits[i] == '1')
                bits[i] = '0';
            else
                bits[i] = '1';
        }

        swap(ones, zeros);
    }
    
    // T.C.=O(1)
    bool all() {
        return ones == bits.length();
    }
    
    // T.C.=O(1)
    bool one() {
        return ones > 0;
    }
    
    // T.C.=O(1)
    int count() {
        return ones;
    }
    
    // T.C.=O(1)
    string toString() {
        return bits;
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