/*
1052. ������������ϰ�
���죬����ϰ���һ�ҵ������Ӫҵ customers.length ���ӡ�ÿ���Ӷ���һЩ�˿ͣ�customers[i]���������꣬������Щ�˿Ͷ�������һ���ӽ������뿪��

��ĳЩʱ������ϰ�������� �������ϰ��ڵ� i ������������ô grumpy[i] = 1������ grumpy[i] = 0�� ������ϰ�����ʱ����һ���ӵĹ˿;ͻ᲻���⣬������������������ġ�

����ϰ�֪��һ�����ܼ��ɣ��������Լ����������������Լ����� X ���Ӳ���������ȴֻ��ʹ��һ�Ρ�

���㷵����һ��Ӫҵ����������ж��ٿͻ��ܹ��е������������


ʾ����

���룺customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
�����16
���ͣ�
����ϰ������ 3 ���ӱ����侲��
�е���������ͻ����� = 1 + 1 + 1 + 1 + 7 + 5 = 16.


ע��������� ����˵������������Ӳ����������ǿ���ʹ��������� Ҳ����˵�����м��� ��������
�Ǿ���һ���������ھͺ�
*/
class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int total = 0;
        int n=customers.length;
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0)
            {
                total+=customers[i];
            }
        }
        int increase = 0;
        for(int i=0;i<X;i++)
        {
            increase += customers[i]*grumpy[i];
        }
        int maxIncrease = increase;
        for(int i=X;i<n;i++)
        {
            increase = increase - customers[i-X]*grumpy[i-X]+customers[i]*grumpy[i];
            maxIncrease = Math.max(maxIncrease,increase);
        }
        return total+maxIncrease;
    }
}

