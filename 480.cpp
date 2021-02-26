/*
480. ����������λ��
��λ���������������м���Ǹ�����������еĴ�С��ż������û�����м��������ʱ��λ�������м����������ƽ������

���磺

[2,3,4]����λ���� 3
[2,3]����λ���� (2 + 3) / 2 = 2.5
����һ������ nums����һ����СΪ k �Ĵ��ڴ�����˻��������Ҷˡ��������� k ������ÿ�δ��������ƶ� 1 λ������������ҳ�ÿ�δ����ƶ���õ����´�����Ԫ�ص���λ�����������������ɵ����顣



ʾ����

���� nums = [1,3,-1,-3,5,3,6,7]���Լ� k = 3��
*/

//�Լ��������ݽṹ

class  DualHeap{
private:
    //����� Ĭ�ϴ���ѵ�
    priority_queue<int> small;
    //С���� Ҫ��greater
    priority_queue<int,vector<int>,greater<int>> large;
    //��ϣ����¼�ӳ�ɾ��Ԫ�أ�keyΪԪ�أ�valueΪ��Ҫɾ���Ĵ���
    unordered_map<int,int> delayed;

    int k;
    int smallSize,largeSize;

public:


};





//������汾�� ��������
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
class Solution {
public:
    tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> t;
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        queue<pair<int, int>> q;
        vector<double> ans;
        for(int i = 0; i < nums.size(); ++i) {
            q.push({nums[i], i});
            t.insert({nums[i], i});
            if(q.size() >= k) {
                long x = (*t.find_by_order(k / 2)).first;
                long y = (*t.find_by_order((k - 1) / 2)).first;
                ans.push_back((x + y) / 2.0);
                t.erase(q.front());
                q.pop();
            }
        }
        return ans;
    }
};

