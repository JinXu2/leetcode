/*
1004. �������1�ĸ��� III
����һ�������� 0 �� 1 ��ɵ����� A�����������Խ� K ��ֵ�� 0 ��� 1 ��

���ؽ����� 1 �����������������ĳ��ȡ�



ʾ�� 1��

���룺A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
�����6
���ͣ�
[1,1,1,0,0,1,1,1,1,1,1]
�������ִ� 0 ��ת�� 1����������鳤��Ϊ 6��
*/

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left=0;
        int right=0;
        int len=A.size();
        int countzero=0;
        int res=0;
        while(right<len)
        {
            if(A[right]==0)
            {
                countzero++;
            }
            right++;
            while(zerocount>K)
            {
                if(A[left]==0)
                {
                    zerocount--;
                }
                left++;
            }
            res=max(res,r-l);
        }
        return res;
    }
};

//�޵м��汾
int longestOnes(vector<int>&A,int K)
{
    int l=0,r=0;
    while(r<A.size())
    {
        K-=1-A[r++];
        if(K<0)
        {
            K+=1-A[l++];
        }
    }
    return r-l;
}
