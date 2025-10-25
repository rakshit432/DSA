class Solution {
public:
    int totalMoney(int n) {
        int r = n % 7;
        int q = n / 7;
        int a = (7* (7 + 1)) / 2;

      if(n>=7)  return (q * a) + (7 * (q*(q - 1))/2) + ((r * (r + 1)) / 2) + (q * r);
      else return (n*(n+1))/2;
    }
};
