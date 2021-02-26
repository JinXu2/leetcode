/*
1631. 最小体力消耗路径
你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子 (row, col) 的高度。一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从 0 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。

一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。

请你返回从左上角走到右下角的最小 体力消耗值 。
*/

//第一反应肯定是DP 但是状态之间是没有关系的

/*重新建模 看成一张图 一个格子是一个节点，相邻格子即是相邻节点 之间存在一条边

方法一：二分查找  二分查找的是 边的值 也就是判断的上限 这样子最快
思路与算法

我们可以将这个问题转化成一个「判定性」问题，即：

是否存在一条从左上角到右下角的路径，其经过的所有边权的最大值不超过 xx？

这个判定性问题解决起来并不复杂，我们只要从左上角开始进行深度优先搜索或者广度优先搜索，在搜索的过程中只允许经过边权不超过 xx 的边，搜索结束后判断是否能到达右下角即可。

随着 xx 的增大，原先可以经过的边仍然会被保留，因此如果当 x=x_0x=x
0
​
  时，我们可以从左上角到达右下角，那么当 x > x_0x>x
0
​
  时同样也可以可行的。因此我们可以使用二分查找的方法，找出满足要求的最小的那个 xx 值，记为 x_\textit{ans}x
ans
​
 ，那么：

当 x < x_\textit{ans}x<x
ans
​
 ，我们无法从左上角到达右下角；

当 x \geq x_\textit{ans}x≥x
ans
​
 ，我们可以从左上角到达右下角。

由于格子的高度范围为 [1, 10^6][1,10
6
 ]，因此我们可以 [0, 10^6-1][0,10
6
 −1] 的范围内对 xx 进行二分查找。在每一步查找的过程中，我们使用进行深度优先搜索或者广度优先搜索判断是否可以从左上角到达右下角，并根据判定结果更新二分查找的左边界或右边界即可。


*/

//边找 边更新上下界 感觉这个方法我想不到的
//我们需要进行 O(\log C)O(logC) 次二分查找，每一步查找的过程中需要使用广度优先搜索，在 O(mn)O(mn) 的时间判断是否可以从左上角到达右下角，因此总时间复杂度为 O(mn \log C)O(mnlogC)


class Solution{
private:
    state constexpr int dirs[4][2]={{-1,0}，{1,0}，{0，-1}，{0,1}};
public:
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int m=heights.size();
        int n=heights[0].size();
        int left=0,int right=999999,ans=0;
        while(left<right)
        {
            int mid=(right+left)/2;
            queue<pair<int,int>> q;
            q.emplace(0,0);
            vector<int> seem(m*n);
            seen[0]=1;
            while(!q.empty()){
                auto [x,y] = q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nx=x+dirs[i][0];
                    int ny=y+dirs[i][0];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && !seen[nx*n+ny] && abs(heights[x][y]-heights[nx][ny])<=mid)
                    {
                        q.emplace(nx,ny);
                        seen[nx*n+ny]=1;
                    }

                }
            }
            if(seen[m*n]-1)
            {
                ans=mid;
                right=mid-1;
            }else
            {
                left=mid+1;
            }
        }
        return ans;
    }
};

/*
方法二：并查集
思路与算法

我们将这 mnmn 个节点放入并查集中，实时维护它们的连通性。

由于我们需要找到从左上角到右下角的最短路径，因此我们可以将图中的所有边按照权值从小到大进行排序，并依次加入并查集中。当我们加入一条权值为 xx 的边之后，如果左上角和右下角从非连通状态变为连通状态，那么 xx 即为答案。

*/
// 并查集模板
class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    // 当前连通分量数目
    int setCount;

public:
    UnionFind(int _n): n(_n), setCount(_n), parent(_n), size(_n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int findset(int x) {
        return parent[x] == x ? x : parent[x] = findset(parent[x]);
    }

    bool unite(int x, int y) {
        x = findset(x);
        y = findset(y);
        if (x == y) {
            return false;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        --setCount;
        return true;
    }

    bool connected(int x, int y) {
        x = findset(x);
        y = findset(y);
        return x == y;
    }
};

class Solution{
public:
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int m=heights.size();
        int n=heights[0].size();
        vector<tuple<int,int,int>> edges;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int id=i*n+j;
                if(i>0)
                {
                    edges.emplace_back(id-n,id,abs(heights[i][j]-heights[i-1][j]));
                }
                if(j>0)
                {
                    edges.emplace_back(id-1,id,abs(heights[i][j]-heights[i][j-1]));
                }
            }
        }

        sort(edges.begin(),edges.end(),[](const auto&e1,const auto&e2){
             auto&& [x1,y1,v1]=e1;
             auto&& [x2,y2,v2]=e2;
             return  v1<v2;
             });
        UnionFind uf(m*n);
        int ans=0;
        for(const auto [x,y,v]:edges)
        {
            uf.unite(x,y);
            if(uf.connected(0,m*n-1))
            {
                ans=v;
                break;
            }
        }
        return ans;
    }

};


//最短路径 经典的Dijkstra算法 不想写了
