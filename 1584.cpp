//链接所有点的最小费用 实际问题就是求 最小生成树

//最小生成树的经典算法：Kruskal 算法 贪心思想

//在实际代码中，我们首先将这张完全图中的边全部提取到边集数组中，然后对所有边进行排序，从小到大进行枚举，每次贪心选边加入答案。使用并查集维护连通性，若当前边两端不连通即可选择这条边。


class DisjointSetUnion{
private:
    vector<int> f,rank;
    int n;
public:
    DisjointSetUnion(int _n)
    {
        n=_n;
        rank.resize(n,1);
        f.resize(n);
        for(int i=0;i<n;i++)
        {
            f[i]=i;
        }
    }

    int find(int x)
    {
        return f[x]==x? x:f[x]=find(f[x]);
    }

    int unionSet(int x,int y)
    {
        int fx=find(x);
        int fy=find(y);
        if(fx==fy)
        {
            return false;
        }
        if(rank[fx]<rank[fy])
        {
            swap(fx,fy);
        }

        rank[fx]+=rank[fy];
        f[fy]=fx;
        return true;
    }
};


struct edge
{
    int len,x,y;
    edge(int len,int x,int y):len(len),x(x),y(y){}
};

class Solution{
public:
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        auto dist=[&](int x,int y)->int{
            return abs(points[x][0]-points[y][0])+abs(points[x][1]-points[y][1]);
        };
        int n=points.size();
        DisjointSetUnion dsu(n);
        vector<edge> edges;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                edges.emplace_back(dist(i,j),i,j);
            }
        }
        sort(edges.begin(),edges.end(),[](edge a,edge b)-> int {return a.len<b.len;});
        int ret=0,num=1;
        for(auto& [len,x,y]:edges)
        {
            if(dsu.unionSet(x,y))
            {
                ret+=len;
                num++;
                if(num==n)
                {
                    break;
                }
            }
        }
        return ret;
    }
};
