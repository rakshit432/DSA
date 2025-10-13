class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        unordered_map<string,string>mpp;

        for(int i = 0 ; i<words.size();i++)
        {
            string s = words[i];
            sort(s.begin(),s.end());
            mpp[words[i]] = s ;
        }

        
        
        int n = words.size();
        for(int i = n-1 ; i>0 ;i--)
        {
          if(mpp[words[i]] == mpp[words[i-1]])
          {
            words.erase(words.begin() + i); 
          }
        }

        return words;
        
    }
};