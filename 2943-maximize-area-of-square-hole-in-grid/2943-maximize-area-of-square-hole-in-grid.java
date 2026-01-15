class Solution {
    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        Arrays.sort(hBars);
        Arrays.sort(vBars);
        int hxcur=hBars[0];
        int hx=hBars[0];
        int hy=0;
        int hdif=0;
        int vxcur=vBars[0];
        int vx=vBars[0];
        int vy=0;
        int vdif=0;
        int i;
        for(i=1;i<hBars.length;i++)
        {
            if(hBars[i]==hBars[i-1]+1)
            {
                continue;
            }
            else
            {
                if(hBars[i-1]-hxcur>=hdif)
                {
                    hy=hBars[i-1];
                    hdif=hBars[i-1]-hxcur;
                    hx=hxcur;
                }
                hxcur=hBars[i];
            }
        }
        if(hBars[i-1]-hxcur>=hdif)
        {
            hy=hBars[i-1];
            hdif=hBars[i-1]-hxcur;
            hx=hxcur;
        }

        for(i=1;i<vBars.length;i++)
        {
            if(vBars[i]==vBars[i-1]+1)
            {
                continue;
            }
            else
            {
                if(vBars[i-1]-vxcur>=vdif)
                {
                    vy=vBars[i-1];
                    vdif=vBars[i-1]-vxcur;
                    vx=vxcur;
                }
                vxcur=vBars[i];
            }
        }
        if(vBars[i-1]-vxcur>=vdif)
        {
            vy=vBars[i-1];
            vdif=vBars[i-1]-vxcur;
            vx=vxcur;
        }
        int sqlen=Math.min((hy-hx+2),(vy-vx+2));
        return sqlen*sqlen;

    }
}