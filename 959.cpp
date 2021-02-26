/*
959. ��б�ܻ�������
���� 1 x 1 ������ɵ� N x N ���� grid �У�ÿ�� 1 x 1 ������ /��\ ��ո񹹳ɡ���Щ�ַ��Ὣ���黮��ΪһЩ���ߵ�����

����ע�⣬��б���ַ���ת��ģ���� \ �� "\\" ��ʾ������

�����������Ŀ��



ʾ�� 1��

���룺
[
  " /",
  "/ "
]
�����2
���ͣ�2x2 �������£�
*/

//����Ԫ�����򻮷ֵģ�һ����Ԫ���Ϊ��С�� ��ʼ���кϲ�

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

        //��
        for(int i=0;i<n;i++)
        {
            //��
            for(int j=0;j<n;j++)
            {
                //�ڼ�����Ԫ��
                int idx=i*n+j;
                if(i<n-1)
                {
                    int bottom=idx+n;
                    //�ϲ������
                    merge(f,idx*4+2,bottom*4);
                }
                if(j<n-1)
                {
                    int right=idx+1;
                    //�ϲ��ұߵ�
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


//���յ�� һ���������ĸ���

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
            //����
            merge(i,i+1);
            //����
            merge(n*(n+1)+i,n*(n+1)+i+1);
            //���
            merge(i*(n+1), (i+1)*(n+1));
            //�ұ�
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
