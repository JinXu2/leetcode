/*
766. �������ľ���
����һ�� m x n �ľ��� matrix ���������������������ľ��󣬷��� true �����򣬷��� false ��

���������ÿһ�������ϵ����µĶԽ����ϵ�Ԫ�ض���ͬ����ô��������� �������ľ��� ��



ʾ�� 1��


���룺matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
�����true
���ͣ�
������������, ��Խ���Ϊ:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]"��
�����Խ����ϵ�����Ԫ�ؾ���ͬ, ��˴��� True ��
*/

//����ΪJava����
//��򵥵ķ���һ�����Խ������� ��������Ҫ����ѭ���� ��Ҫ���Ǳ߽� ���򵥵��� ��ÿһ��Ԫ�����Լ����Ͻǵ�Ԫ�ؽ��жԱ�

class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        int m=matrix.length,n=martrix[0].length;
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]!=matrix[i-1][j-1])
                {
                    return false;
                }
            }
        }
        return true;
    }
}

//�������һ�����ֻ�ܽ������һ�м��ص��ڴ��� ��ÿһ�и��Ƶ�һ�����������У�����ڶ�ȡ��һ��ʱ�������ڴ��д�ǰ�����������бȽϡ�

class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        int m=matrix.length,n=martrix[0].length;
        int[] temp = new int[n];
        temp=matrix[0];
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(temp[j-1]!=matrix[i][j])
                {
                    return false;
                }
            }
            temp=matrix[i];
        }
    }
}

//���ڽ����������һ��ֻ�ܽ���������һ�м��ص��ڴ��У����ǽ�����������ֱ�зֳ������Ӿ��󣬲���֤�������ڵľ���������һ�л�һ�����غϵģ�Ȼ���ж�ÿ���Ӿ����Ƿ����Ҫ��

