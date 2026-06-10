class BrowserHistory {
private:
    vector<string> urls;
    int i = -1;

public:
    BrowserHistory(string homepage) {
        urls.push_back(homepage);
        i = 0;
    }
    
    void visit(string url) {
        // pop the urls after the index i before pushing the new url
        for(int j=urls.size()-1; j>i; j--)
            urls.pop_back();
        urls.push_back(url);
        i++;
    }
    
    string back(int steps) {
        i -= steps; // move i steps backwards
        if(i < 0) // limit the min index to 0
            i = 0;
        return urls[i];
    }
    
    string forward(int steps) {
        i += steps; // move i steps forwards
        if(i >= urls.size()) // limit the max index to urls.size()-1
            i = urls.size() - 1;
        return urls[i];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */