class Solution {
    public int countKthRoots(int l, int r, int k) {
        if(k==1)return r-l+1;
        int ans=0;
        for(int i=0;i<=r/2;i++){
            long pow=1;
            for(int j=0;j<k;j++){
                pow*=i;
                
            }
            if(pow>r) break;
            if(pow>=l && pow<=r ) ans++;
    }
        return ans;
}
}
