/*
1208. ������ʹ�ַ������
��������������ͬ���ַ�����s �� t��

�� s �еĵ� i ���ַ��䵽 t �еĵ� i ���ַ���Ҫ |s[i] - t[i]| �Ŀ�������������Ϊ 0����Ҳ���������ַ��� ASCII ��ֵ�Ĳ�ľ���ֵ��

���ڱ���ַ��������Ԥ���� maxCost����ת���ַ���ʱ���ܿ���Ӧ��С�ڵ��ڸ�Ԥ�㣬��Ҳ��ζ���ַ�����ת�������ǲ���ȫ�ġ�

�������Խ� s �����ַ���ת��Ϊ���� t �ж�Ӧ�����ַ������򷵻ؿ���ת������󳤶ȡ�

��� s ��û�����ַ�������ת���� t �ж�Ӧ�����ַ������򷵻� 0��



ʾ�� 1��

���룺s = "abcd", t = "bcdf", cost = 3
�����3
���ͣ�s �е� "abc" ���Ա�Ϊ "bcd"������Ϊ 3��������󳤶�Ϊ 3��
*/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left=0;
        int len=0;
        int cost=0;
        for(int i=0;i<s.size();i++)
        {
            cost += abs(s[i]-t[i]);
            if(cost>maxCost)
            {
                cost-=abs(s[left]-t[left]);
                left++;
            }
            len=max(len,i-left+1);
        }
        return len;
    }
};
