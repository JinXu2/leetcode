/*
1128. �ȼ۶���ŵ���ƶԵ�����
����һ����һЩ����ŵ������ɵ��б� dominoes��

�������ĳһ�Ŷ���ŵ���ƿ���ͨ����ת 0 �Ȼ� 180 �ȵõ���һ�Ŷ���ŵ���ƣ����Ǿ���Ϊ���������ǵȼ۵ġ�

��ʽ�ϣ�dominoes[i] = [a, b] �� dominoes[j] = [c, d] �ȼ۵�ǰ���� a==c �� b==d������ a==d �� b==c��

�� 0 <= i < j < dominoes.length ��ǰ���£��ҳ����� dominoes[i] �� dominoes[j] �ȼ۵Ĺ��ƶ� (i, j) ��������



ʾ����

���룺dominoes = [[1,2],[2,1],[3,4],[5,6]]
�����1
*/

//һ��ʼ�϶���Ҫ�ù�ϣ �����Լ�����Ŀ�Ϳ���ֱ�Ӱ����Կ����� һ����λ��

class Solution{
public:
    //�����2��һ����+1 3��һ������ +2+1 4��һ������+3+2+1 ��������������res[num]�����������    int numEquivDominoPairs(vector<vector<int>>& dominoes)
    {
        vector<int> nums(100);
        int ret=0;
        for(auto& it: dominoes)
        {
            int val = it[0]<it[1]? it[0]*10+it[1] :it[1]*10+it[0];
            ret+=nums[val];
            nums[val]++;
        }
        return ret;
    }
};
