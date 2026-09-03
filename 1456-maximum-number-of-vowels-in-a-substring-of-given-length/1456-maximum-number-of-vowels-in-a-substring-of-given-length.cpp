class Solution {
public:
    int maxVowels(string s, int k) {
        int maxi;
        int count=0;
        for(int l=0;l<k;l++){
            if(s[l]=='a'||s[l]=='e'||s[l]=='i'||s[l]=='o'||s[l]=='u'){
                count++;
            }
        }
        maxi=count;
        
        for(int h=k;h<s.length();h++){
            if(s[h-k]=='a'||s[h-k]=='e'||s[h-k]=='i'||s[h-k]=='o'||s[h-k]=='u'){
                count--;
            }
             if(s[h]=='a'||s[h]=='e'||s[h]=='i'||s[h]=='o'||s[h]=='u'){
                count++;
            }
             maxi=max(maxi,count);
        }
        return maxi;
    }
};