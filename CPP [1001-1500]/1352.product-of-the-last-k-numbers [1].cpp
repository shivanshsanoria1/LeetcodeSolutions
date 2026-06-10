class ProductOfNumbers {
private:
    vector<int> preProds; // prefix-products

public:
    ProductOfNumbers() {
        preProds.push_back(1);
    }
    
    void add(int num) { // T.C.=O(1)
        if(num > 0)
            preProds.push_back(preProds.back() * num);
        else
            preProds = {1};
    }
    
    int getProduct(int k) { // T.C.=O(1)
        int n = preProds.size();
        return n-k-1 >= 0 ? preProds[n-1] / preProds[n-k-1] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */