/*
832. ��תͼ��
����һ�������ƾ��� A����������ˮƽ��תͼ��Ȼ��תͼ�񲢷��ؽ����

ˮƽ��תͼƬ���ǽ�ͼƬ��ÿһ�ж����з�ת�����������磬ˮƽ��ת [1, 1, 0] �Ľ���� [0, 1, 1]��

��תͼƬ����˼��ͼƬ�е� 0 ȫ���� 1 �滻�� 1 ȫ���� 0 �滻�����磬��ת [0, 1, 1] �Ľ���� [1, 0, 0]��
*/


//���ֱ��ģ����ʵ�� ��������� ����һ�ߵĻ����Ϳ���ÿһ��01��ת�ͷ�ת������
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        int n=A.length;
        for(int i=0;i<n;i++)
        {
            int left=0,right=n-1;
            while(left<right)
            {
                if(A[i][left]==A[i][right])
                {
                    A[i][left]^=1;
                    A[i][right]^=1;
                }
                left++;
                right--;
            }
            if(left==right)
            {
                A[i][right]^=1;
            }
        }
        return A;
    }
}
