/*
867. ת�þ���
����һ����ά�������� matrix�� ���� matrix �� ת�þ��� ��

����� ת�� ��ָ����������Խ��߷�ת���������������������������
*/


class Solution {
    public int[][] transpose(int[][] matrix) {
        int m=matrix.length;
        int n=matrix[0].length;
        /*���������ǲ��е� �����m=n�ſ���
        for(int i=0;i<m;i++)
        {
            for(int j=i+1;j<n;j++)
        }*/
        int[][] res = new int[n][m];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                res[j][i]=matrix[i][j];
            }
        }
        return res;
    }
}
