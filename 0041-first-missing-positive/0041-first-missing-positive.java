class Solution {
    public int firstMissingPositive(int[] a) {
        int n=a.length;
        int k=0;
        while(k<n){
            int x=a[k];
            if(x>0 && x<=n && a[x-1]!=x){
                int tem=a[k];
                a[k]=a[x-1];
                a[x-1]=tem;
            }
            else    k++;
        }
        int ans=n+1;
        for(int i=0;i<n;i++){
            if(a[i]!=i+1){
                ans=i+1;    break;
            }
        }
        return ans;
    }
}