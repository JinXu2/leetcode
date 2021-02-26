/*
1489. �ҵ���С��������Ĺؼ��ߺ�α�ؼ���
����һ�� n ����Ĵ�Ȩ������ͨͼ���ڵ���Ϊ 0 �� n-1 ��ͬʱ����һ������ edges ������ edges[i] = [fromi, toi, weighti] ��ʾ�� fromi �� toi �ڵ�֮����һ����Ȩ����ߡ���С������ (MST) �Ǹ���ͼ�бߵ�һ���Ӽ��������������нڵ���û�л���������Щ�ߵ�Ȩֵ����С��

�����ҵ�����ͼ����С�����������йؼ��ߺ�α�ؼ��ߡ������ͼ��ɾȥĳ���ߣ��ᵼ����С��������Ȩֵ�����ӣ���ô���Ǿ�˵����һ���ؼ��ߡ�α�ؼ������ǿ��ܻ������ĳЩ��С�������е����������������С�������еıߡ�

��ע�⣬����Էֱ�������˳�򷵻عؼ��ߵ��±��α�ؼ��ߵ��±ꡣ
*/

/*
��Ŀ�е�С���ӣ���Ϊͼ���кܶ�Ȩֵһ���ıߣ������ػ��кܶ���С��������
���������ÿһ��MST�еıߣ��Ǿ��ǹؽ���
������ǣ����ǹؽ��ߣ�
����õķ����ǣ�

�ؼ��ߣ������С��������ɾȥĳ���ߣ��ᵼ����С��������Ȩֵ�����ӣ���ô���Ǿ�˵����һ���ؼ��ߡ�Ҳ����˵�������ԭͼ��С��������ȨֵΪ \textit{value}value����ôȥ�������ߺ�

Ҫô����ͼ����ͨ����������С��������

Ҫô����ͼ��ͨ����Ӧ����С��������ȨֵΪ vv�����ϸ���� \textit{value}value��

α�ؼ��ߣ����ܻ������ĳЩ��С�������е����������������С�������еıߡ�Ҳ����˵�����ǿ����ڼ�����С�������Ĺ����У����ȿ��������ߣ������Ƚ������ߵ������˵��ڲ��鼯�кϲ��������յõ�����С������ȨֵΪ vv����� v = \textit{value}v=value����ô�����߾���α�ؼ��ߡ�
*/


class UnionFind{
public:
    vector<int> parent;
    vector<int> size;
    int n;
    //��ǰ��ͨ������Ŀ
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
        //���ڱ�Ȩֵ����
        sort(edges.begin(),edges.end(),[](const auto&u, const auto& v)
        {
            return u[2]<v[2];
        });

        //����value
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
            //�Ƿ�ؼ���
            //������������ߣ����������˻����������˵���Ȩֵ�ͱ���ˣ��Ǿ��ǹؼ���
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

            //�Ƿ��Ƿǹؼ��� �ѵ����� �ǹؼ���ʣ�µľͶ����ǹؼ�������
            //����������
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
