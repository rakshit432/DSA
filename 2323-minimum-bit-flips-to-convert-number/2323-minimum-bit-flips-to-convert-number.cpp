class Solution {
public:
    int minBitFlips(int start, int goal) {
        int XOR = start^goal ;
      
      int cnt = 0 ;
      while(XOR>0)
      {
        XOR = XOR & (XOR-1);
        cnt ++ ;
      }
      return cnt ;
    }
};