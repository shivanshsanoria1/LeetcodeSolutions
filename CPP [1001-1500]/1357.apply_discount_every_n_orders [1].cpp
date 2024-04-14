class Cashier {
private:
    // productId -> price
    unordered_map<int, int> productPriceMap;

    int n = 0;
    int discountPercent = 0;
    int customerCount = 0;

public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        for(int i=0; i<products.size(); i++)
            this->productPriceMap[products[i]] = prices[i];
        
        this->n = n;
        this->discountPercent = discount;
        this->customerCount = 0;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        customerCount++;

        double bill = 0;

        for(int i=0; i<product.size(); i++)
            bill += productPriceMap[product[i]] * amount[i];

        if(customerCount % n == 0)
            bill *= (double)(100 - discountPercent) / 100;

        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */