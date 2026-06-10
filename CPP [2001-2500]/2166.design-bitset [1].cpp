class Bitset {
private:
    // main string
    string bits = "";
    int ones = 0;
    int zeros = 0;

    // flipped version of main string
    string bits_f = "";
    int ones_f = 0;
    int zeros_f = 0;

public:
    Bitset(int size) {
        this->bits.resize(size, '0');
        this->ones = 0;
        this->zeros = size;

        this->bits_f.resize(size, '1');
        this->ones_f = size;
        this->zeros_f = 0;
    }
    
    // T.C.=O(1)
    void fix(int idx) {
        if(bits[idx] == '1')
            return;
        
        bits[idx] = '1';
        ones++;
        zeros--;

        bits_f[idx] = '0';
        ones_f = zeros;
        zeros_f = ones;
    }
    
    // T.C.=O(1)
    void unfix(int idx) {
        if(bits[idx] == '0')
            return;
        
        bits[idx] = '0';
        ones--;
        zeros++;

        bits_f[idx] = '1';
        ones_f = zeros;
        zeros_f = ones;
    }
    
    // T.C.=O(1)
    void flip() {
        swap(bits, bits_f);

        swap(ones, ones_f);
        swap(zeros, zeros_f);
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