class Solution
{
    int mod=1000000007;

    public int[] pathsWithMaxScore(List<String> board)
    {
        int n=board.size();

        int[][] score=new int[n][n];
        int[][] count=new int[n][n];

        for(int i=0;i<n;i++)
            Arrays.fill(score[i],-1);

        score[n-1][n-1]=0;
        count[n-1][n-1]=1;

        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(board.get(i).charAt(j)=='X')
                    continue;

                if(i==n-1 && j==n-1)
                    continue;

                int max=-1;
                int ways=0;

                if(i+1<n && score[i+1][j]!=-1)
                {
                    if(score[i+1][j]>max)
                    {
                        max=score[i+1][j];
                        ways=count[i+1][j];
                    }
                    else if(score[i+1][j]==max)
                        ways=(ways+count[i+1][j])%mod;
                }

                if(j+1<n && score[i][j+1]!=-1)
                {
                    if(score[i][j+1]>max)
                    {
                        max=score[i][j+1];
                        ways=count[i][j+1];
                    }
                    else if(score[i][j+1]==max)
                        ways=(ways+count[i][j+1])%mod;
                }

                if(i+1<n && j+1<n && score[i+1][j+1]!=-1)
                {
                    if(score[i+1][j+1]>max)
                    {
                        max=score[i+1][j+1];
                        ways=count[i+1][j+1];
                    }
                    else if(score[i+1][j+1]==max)
                        ways=(ways+count[i+1][j+1])%mod;
                }

                if(max==-1)
                    continue;

                int val=0;
                char ch=board.get(i).charAt(j);

                if(ch!='S' && ch!='E')
                    val=ch-'0';

                score[i][j]=max+val;
                count[i][j]=ways;
            }
        }

        if(score[0][0]==-1)
            return new int[]{0,0};

        return new int[]{score[0][0],count[0][0]};
    }
}