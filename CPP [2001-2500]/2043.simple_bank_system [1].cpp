class Bank {
private:
    typedef long long int lli;

    vector<lli> balance;

    int n = 0;

    bool isAccountValid(int account) {
        return account >= 1 && account <= n;
    }

public:
    Bank(vector<long long>& balance) {
        // assume the 0th account has balance '-1'
        this->balance.push_back(-1);

        for(lli money: balance)
            this->balance.push_back(money);
        
        this->n = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!isAccountValid(account1) || !isAccountValid(account2))
            return false;

        if(balance[account1] < money)
            return false;
        
        balance[account1] -= money;
        balance[account2] += money;

        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!isAccountValid(account))
            return false;

        balance[account] += money;

        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!isAccountValid(account))
            return false;

        if(balance[account] < money)
            return false;

        balance[account] -= money;
        
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */