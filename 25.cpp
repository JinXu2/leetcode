/*
25. K ��һ�鷭ת����
����һ������ÿ k ���ڵ�һ����з�ת�����㷵�ط�ת�������

k ��һ��������������ֵС�ڻ��������ĳ��ȡ�

����ڵ��������� k ������������ô�뽫���ʣ��Ľڵ㱣��ԭ��˳��



ʾ����

�����������1->2->3->4->5

�� k = 2 ʱ��Ӧ������: 2->1->4->3->5

�� k = 3 ʱ��Ӧ������: 3->2->1->4->5
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    pair<ListNode*,ListNode*> myReverse(ListNode* head,ListNode* tail)
    {
        ListNode* pre=tail->next;
        ListNode* p=head;
        while(pre!=tail)
        {
            ListNode* nex=p->next;
            p->next=pre;
            pre=p;
            p=nex;
        }
        return {tail,head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair=new ListNode(0);
        hair->next=head;
        ListNode* pre=hair;

        while(head)
        {
            ListNode* tail=pre;
            for(int i=0;i<k;i++)
            {
                tail=tail->next;
                if(!tail)
                {
                    return hair->next;
                }
            }

            ListNode* nex=tail->next;
            pair<ListNode*,ListNode*> res = myReverse(head,tail);
            head=res.first;
            tail=res.second;
            pre->next=head;
            tail->next=nex;
            pre=tail;
            head=tail->next;

        }
        return hair->next;
    }
};








