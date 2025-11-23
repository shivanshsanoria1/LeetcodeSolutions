class Solution {
private:
    string getId(string& log){
        int i = 0;
        while(log[i] != ' ')
            i++;
        
        return log.substr(0, i);
    }

    // returns false for letter-log and true for digit-log
    bool getType(string& log){
        int i = 0;
        while(log[i] != ' ')
            i++;
        
        return isdigit(log[i+1]);
    }

    string getData(string& log){
        int i = 0;
        while(log[i] != ' ')
            i++;
        
        return log.substr(i+1);
    }

public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // log -> index
        unordered_map<string, int> mp;
        for(int i=0; i<logs.size(); i++)
            mp[logs[i]] = i;

        sort(logs.begin(), logs.end(), [&](string& a, string& b){
            bool type_a = getType(a);
            bool type_b = getType(b);

            // one is letter-log and the other is digit-log
            if(type_a != type_b)
                return type_a < type_b;

            // both are letter-logs
            if(!type_a && !type_b)
            {
                string data_a = getData(a);
                string data_b = getData(b);

                string id_a = getId(a);
                string id_b = getId(b);

                return data_a == data_b ? id_a < id_b : data_a < data_b;
            }

            // type_a && type_b
            // both are digit-logs
            return mp[a] < mp[b];
        });

        return logs;
    }
};
// NOTE: id's are not guranteed to be unique