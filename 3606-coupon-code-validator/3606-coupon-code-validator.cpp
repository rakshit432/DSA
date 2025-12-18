class Solution {
public:
    bool isvalid(string code) {
        for (char ch : code) {
            if ((ch >= '0' && ch <= '9') || 
                (ch >= 'a' && ch <= 'z') || 
                (ch >= 'A' && ch <= 'Z') || 
                ch == '_' || ch == '-') {
                continue;
            }
            return false;
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        vector<pair<string,string>>s1 ;
        int n = code.size();

        for (int i = 0; i < n; i++) {
            if (isvalid(code[i]) && code[i] != "" && isActive[i]) {
                if (businessLine[i] == "electronics" ||
                    businessLine[i] == "grocery" ||
                    businessLine[i] == "pharmacy" ||
                    businessLine[i] == "restaurant") {

                   s1.push_back({businessLine[i],code[i]});
                }
            }
        }

       sort(s1.begin(),s1.end());
       vector<string>ans ;
        for (auto& it : s1) {
           ans.push_back(it.second);
        }

        

       return ans ;
        
    }
};