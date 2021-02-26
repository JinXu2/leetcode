/*
888. ��ƽ���ǹ�������
����˿�ͱ����в�ͬ��С���ǹ�����A[i] �ǰ���˿ӵ�еĵ� i ���ǹ����Ĵ�С��B[j] �Ǳ���ӵ�еĵ� j ���ǹ����Ĵ�С��

��Ϊ���������ѣ����������뽻��һ���ǹ������������������Ƕ�����ͬ���ǹ���������һ����ӵ�е��ǹ�����������ӵ�е��ǹ�����С���ܺ͡���

����һ���������� ans������ ans[0] �ǰ���˿���뽻�����ǹ����Ĵ�С��ans[1] �� Bob ���뽻�����ǹ����Ĵ�С��

����ж���𰸣�����Է��������κ�һ������֤�𰸴��ڡ�



ʾ�� 1��

���룺A = [1,1], B = [2,2]
�����[1,2]
*/


//��������� �����ϣ�㷨
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA=accumulate(A.begin(),A.end(),0);
        int sumB=accumulate(B.begin(),B.end(),0);
        int delta=(sumA-sumB)/2;
        unordered_set<int> rec(A.begin(),A.end());
        vector<int> ans;
        for(auto&y :B)
        {
            int x=y+delta;
            if(rec.count(x))
            {
                ans=vector<int>{x,y};
                break;
            }
        }
        return ans;
    }
};

//�������� �������������� �ҵ��������ǹ�  ��� diff/2
