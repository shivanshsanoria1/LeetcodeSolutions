class StreamChecker {
private:
    unordered_set<string> dict;
    int maxWordLen = 0;
    string stream = "";

public:
    StreamChecker(vector<string>& words) {
        this->maxWordLen = 0;
        
        for(string& word: words)
        {
            this->dict.insert(word);
            maxWordLen = max(maxWordLen, (int)word.length());
        }
        
        this->stream = "";
    }
    
    bool query(char letter) {
        stream += letter;

        // eliminate the 0th char from stream
        if(stream.length() == maxWordLen + 1)
            stream = stream.substr(1);

        for(int i=stream.size()-1; i>=0; i--)
            if(dict.find(stream.substr(i)) != dict.end())
                return true;

        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */