/*
25. K 个一组翻转链表
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。



示例：

给你这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5
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








