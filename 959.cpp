/*
959. 由斜杠划分区域
在由 1 x 1 方格组成的 N x N 网格 grid 中，每个 1 x 1 方块由 /、\ 或空格构成。这些字符会将方块划分为一些共边的区域。

（请注意，反斜杠字符是转义的，因此 \ 用 "\\" 表示。）。

返回区域的数目。



示例 1：

输入：
[
  " /",
  "/ "
]
输出：2
解释：2x2 网格如下：
*/

//按单元格区域划分的，一个单元格分为四小块 开始进行合并

class Solution{
public:
    int find(vector<int>&f,int x)
    {
        if(f[x]==x)
        {
            return x;
        }
        int fa=find(f,f[x]);
        f[x]=fa;
        return fa;
    }

    void merge(vector<int>&f,int x,int y)
    {
        int fx=find(f,x);
        int fy=find(f,y);
        f[fx]=fy;
    }

    int regionsBySlashes(vector<string>& grid)
    {
        int n=grid.size();
        vector<int> f(n*n*4);
        for(int i=0;i<n*n*4;i++)
        {
            f[i]=i;
        }

        //行
        for(int i=0;i<n;i++)
        {
            //列
            for(int j=0;j<n;j++)
            {
                //第几个单元格
                int idx=i*n+j;
                if(i<n-1)
                {
                    int bottom=idx+n;
                    //合并下面的
                    merge(f,idx*4+2,bottom*4);
                }
                if(j<n-1)
                {
                    int right=idx+1;
                    //合并右边的
                    merge(f,idx*4+1,right*+3);
                }
                if(grid[i][j]=='/')
                {
                    merge(f,idx*4,idx*4+3);
                    merge(f,idx*4+1,idx*4+2);
                }else if(grid[i][j]=='\\')
                {
                    merge(f,idx*4,idx*4+1);
                    merge(f,idx*4+3,idx*4+2);
                }else
                {
                    merge(f, idx * 4, idx * 4 + 1);
                    merge(f, idx * 4 + 1, idx * 4 + 2);
                    merge(f, idx * 4 + 2, idx * 4 + 3);
                }
            }
        }
        unordered_set<int> fathers;
        for(int i=0;i<n*n*4;i++)
        {
            int fa=find(f,i);
            fathers.insert(fa);
        }
        return fathers.size();
    }
};


//按照点的 一个格子是四个点

class Solution{
public:
    vector<int> f;
    int find(int x)
    {
        return x==f[x]? x: f[x]=find(f[x]);
    }

    int merge(int u,int v)
    {
        int fu=find(u);
        int fv=find(v);
        if(fu==fv)
        {
            return 0;
        }
        f[fv]=fu;
        return 1;
    }

    int regionsBySlashes(vector<string>& grid)
    {
        int n=grid.size();
        f=vector<int>((n+1)*(n+1),0);
        for(int i=0;i<(n+1)*(n+1);i++)
        {
            f[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            //上面
            merge(i,i+1);
            //下面
            merge(n*(n+1)+i,n*(n+1)+i+1);
            //左边
            merge(i*(n+1), (i+1)*(n+1));
            //右边
            merge(i*(n+1)+n, (i+1)*(n+1)+n);
        }
        int cnt=1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==' ')
                {
                    continue;
                }
                int u,v;
                if(grid[i][j]=='/')
                {
                    u=i*(n+1)+j+1;
                    v=(i+1)*(n+1)+j;
                }else
                {
                    u=i*(n+1)+j;
                    v=(i+1)*(n+1)+j+1;
                }
                if(!merge(u,v)) cnt++;
            }
        }
        return cnt;
    }
};
