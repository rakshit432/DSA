class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        int hash[256] = {0};
        int vis[26] = {0};

        int cnt = 0 ;
        
        for(auto it : word)
        {
            if(isupper(it))
            {
                if(hash[tolower(it)] > 0 && !vis[tolower(it)-'a'])
                {
                    cnt++;
                    vis[tolower(it)-'a'] = 1;
                }

                hash[it]++;
            }
            
            else if(islower(it))
            {
                if(hash[toupper(it)] > 0 && !vis[it-'a'])
                {
                    cnt++;
                    vis[it-'a'] = 1;
                }

                hash[it]++;
            }
        }
       
       return cnt ;
    }
};