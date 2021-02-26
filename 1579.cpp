/*
Alice 和 Bob 共有一个无向图，其中包含 n 个节点和 3  种类型的边：

类型 1：只能由 Alice 遍历。
类型 2：只能由 Bob 遍历。
类型 3：Alice 和 Bob 都可以遍历。
给你一个数组 edges ，其中 edges[i] = [typei, ui, vi] 表示节点 ui 和 vi 之间存在类型为 typei 的双向边。请你在保证图仍能够被 Alice和 Bob 完全遍历的前提下，找出可以删除的最大边数。如果从任何节点开始，Alice 和 Bob 都可以到达所有其他节点，则认为图是可以完全遍历的。

返回可以删除的最大边数，如果 Alice 和 Bob 无法完全遍历图，则返回 -1 。

*/

//连通图用并查集来做，如果图相连 也只有一个连通分量
//优先保留公共边 因为如果它有用的话 则省去了 Alice和Bob各自一条边

/*
iota 函数学习 范围赋值 开始结束 起始的数值
template <class ForwardIterator, class T>
  void iota (ForwardIterator first, ForwardIterator last, T val)
{
  while (first!=last) {
    *first = val;
    ++first;
    ++val;
  }
}
*/

/*
size其实是并查集size的优化
可以发现，这个结构的树的层相对较高，若此时元素数量增多，这样产生的消耗就会相对较大。解决这个问题其实很简单，在进行具体指向操作的时候先进行判断，把元素少的集合根节点指向元素多的根节点，能更高概率的生成一个层数比较低的树。
https://www.runoob.com/data-structures/union-find-size.html
*/

class UnionFind{
public:
    vector<int> parent;
    vector<int> size;
    int n;
    int setCount;

    UnionFind(int _n):n(_n),setCount(_n),parent(_n),size(_n,1){
        iota(parent.begin(),parent.end(),0);
    }

    int findset(int x)
    {
        return parent[x]==x? x: parent[x]=findset(parent[x]);
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
        --setCount;
        return true;
    }

    bool connected(int x,int y)
    {
        int fx=findset(x);
        int fy=findset(y);
        return fx==fy;
    }
};


class Solution{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges)
    {
        UnionFind ufa(n),ufb(n);
        int ans=0;

        //将编号改为从0开始
        for(auto& edge:edges)
        {
            --edge[1];
            --edge[2];
        }

        //公共边
        for(const auto& edge:edges)
        {
            if(edge[0]==3)
            {
                //属于一个分量了 这条边没有了连通意义 所以可以删除
                if(!ufa.unite(edge[1],edge[2]))
                {
                    ans++;
                }else
                {
                    //如果没意义可以删除的话 B中就不用操作了
                    //如果有意义不可以删除的话 B中就要进行连通操作 但无论是否 边都不可以删掉了
                    ufb.unite(edge[1],edge[2]);
                }
            }
        }

        //独占边
        for(const auto& edge:edges)
        {
            if(edge[0]==1)
            {
                //Alice独有
                if(!ufa.unite(edge[1],edge[2]))
                {
                    ans++;
                }
            }else if(edge[0]==2)
            {
                //Bob独有
                if(!ufb.unite(edge[1],edge[2]))
                {
                    ans++;
                }
            }
        }
        if(ufa.setCount!=1 || ufb.setCount!=1)
        {
            return -1;
        }
        return ans;
    }
};





