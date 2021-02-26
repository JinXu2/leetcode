/*
1489. 找到最小生成树里的关键边和伪关键边
给你一个 n 个点的带权无向连通图，节点编号为 0 到 n-1 ，同时还有一个数组 edges ，其中 edges[i] = [fromi, toi, weighti] 表示在 fromi 和 toi 节点之间有一条带权无向边。最小生成树 (MST) 是给定图中边的一个子集，它连接了所有节点且没有环，而且这些边的权值和最小。

请你找到给定图中最小生成树的所有关键边和伪关键边。如果从图中删去某条边，会导致最小生成树的权值和增加，那么我们就说它是一条关键边。伪关键边则是可能会出现在某些最小生成树中但不会出现在所有最小生成树中的边。

请注意，你可以分别以任意顺序返回关键边的下标和伪关键边的下标。
*/

/*
题目有点小复杂，因为图当中很多权值一样的边，所以呢会有很多最小生成树，
如果出现在每一个MST中的边，那就是关建边
如果不是，则不是关建边，
因此用的方法是：

关键边：如果最小生成树中删去某条边，会导致最小生成树的权值和增加，那么我们就说它是一条关键边。也就是说，如果设原图最小生成树的权值为 \textit{value}value，那么去掉这条边后：

要么整个图不连通，不存在最小生成树；

要么整个图联通，对应的最小生成树的权值为 vv，其严格大于 \textit{value}value。

伪关键边：可能会出现在某些最小生成树中但不会出现在所有最小生成树中的边。也就是说，我们可以在计算最小生成树的过程中，最先考虑这条边，即最先将这条边的两个端点在并查集中合并。设最终得到的最小生成树权值为 vv，如果 v = \textit{value}v=value，那么这条边就是伪关键边。
*/


class UnionFind{
public:
    vector<int> parent;
    vector<int> size;
    int n;
    //当前连通分量数目
    int setCount;

public:
    UnionFind(int _n):n(_n),setCount(_n),parent(_n),size(_n,1)
    {
        for(int i=0;i<_n;i++)
        {
            parent[i]=i;
        }
    }

    int findset(int x)
    {
        return parent[x]==x? x:parent[x]=findset(parent[x]);
    }

    bool unite(int x,int y)
    {
        x=findset(x);
        y=findset(y);

        if(x==y)
        {
            return false;
        }
        if(size[x]<size[y])
        {
            swap(x,y);
        }
        parent[y]=x;
        size[x]+=size[y];
        setCount--;
        return true;
    }

    bool connected(int x,int y)
    {
        x=findset(x);
        y=findset(y);
        return x==y;
    }

};

class Solution{
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges)
    {
        int m=edges.size();
        for(int i=0;i<m;i++)
        {
            edges[i].push_back(i);
        }
        //关于边权值排序
        sort(edges.begin(),edges.end(),[](const auto&u, const auto& v)
        {
            return u[2]<v[2];
        });

        //计算value
        UnionFind uf(n);
        int value=0;
        for(int i=0;i<m;i++)
        {
            if(uf.unite(edges[i][0],edges[i][1]))
            {
                value+=edges[i][2];
            }
        }

        vector<vector<int>> ans(2);



        for(int i=0;i<m;i++)
        {
            //是否关键边
            //如果不连这条边，连不起来了或者连起来了但是权值和变大了，那就是关键边
            UnionFind uf_1(n);
            int v=0;
            for(int j=0;j<m;j++)
            {
                if(i!=j&&uf_1.unite(edges[j][0],edges[j][1]))
                {
                    v+=edges[j][2];
                }
            }
            if(uf_1.setCount!=1 || (uf_1.setCount==1&& v>value))
            {
                ans[0].push_back(edges[i][3]);
                continue;
            }

            //是否是非关键边 难道不是 是关键边剩下的就都不是关键边了吗？
            //连上这条边
            uf_1=UnionFind(n);
            uf_1.unite(edges[i][0],edges[i][1]);
            v=edges[i][2];
            for(int j=0;j<m;j++)
            {
                if(i!=j && uf_1.unite(edges[j][0],edges[j][1]))
                {
                    v+=edges[j][2];
                }
            }
            if(v==value)
            {
                ans[1].push_back(edges[i][3]);
            }
        }


      return ans;

    }

};
