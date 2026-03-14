class Solution {
public:
     
    string func(int n, int k, int &cnt, string &res)
    {
        if(res.size() == n)
        {
            cnt++;
            if(cnt == k) return res;
            return "";
        }

        for(char ch = 'a'; ch <= 'c'; ch++)
        {
            if(!res.empty() && res.back() == ch) continue;

            res.push_back(ch);

            string ans = func(n, k, cnt, res);
            if(ans != "") return ans;

            res.pop_back();
        }
        return "";
    }

    string getHappyString(int n, int k) {
        
        int cnt = 0;
        string res = "";

        return func(n, k, cnt, res);
    }
};