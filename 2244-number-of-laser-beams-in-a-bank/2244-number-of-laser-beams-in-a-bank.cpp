class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int m = bank.size();
        int n = bank[0].size();
        vector<int>ones;
        for(int i = 0 ; i<m;i++)
        { 
          int cnt = 0 ;
          for(int j = 0 ;j<n ; j++)
          {
             if(bank[i][j] == '1')
             cnt++;
          }
          if(cnt != 0) ones.push_back(cnt);
        }
        
        if(ones.size() == 1)return 0 ;

        int sum = 0 ;
        for(int i = 1 ; i<ones.size() ; i++)
        {
           sum+=(ones[i]*ones[i-1]);
        } 

        return sum ;
    }
};