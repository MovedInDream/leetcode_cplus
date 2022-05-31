// 合并两个排序的链表
// 描述：输入两个递增的链表，合并这两个链表并使新链表中的节点仍是递增排序的。
// 解题思路：
// step 1：根据链表递增的性质，按序比较节点大小。
// step 2：把较小的节点存入新链表中，对应链表进入下一节点
// step 3：直至某一链表遍历完，将另一链表放在新链表后

#include <iostream>

using namespace std;

struct ListNode
{
    int data;
    struct ListNode *next;

    ListNode()
    {

    }

    ListNode(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL)
            return pHead2;
        if (pHead2 == NULL)
            return pHead1;
        pHead1 = pHead1->next;
        pHead2 = pHead2->next;
        ListNode* head = new ListNode;
        ListNode* cur = head;
        while(pHead1 && pHead2)
        {
            if(pHead1->data <= pHead2->data)
            {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
        }

        if(pHead1)
            cur->next = pHead1;
        else
            cur->next = pHead2;

        return head;
    }
};

int main()
{
    cout << "This test is for jz25:" << std::endl;

    Solution test;

    // 构造链表
    ListNode* head1 = new ListNode;
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(5);
    ListNode* node4 = new ListNode(7);
    head1->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    ListNode* head2 = new ListNode;
    ListNode* node5 = new ListNode(2);
    ListNode* node6 = new ListNode(4);
    ListNode* node7 = new ListNode(6);
    ListNode* node8 = new ListNode(7);
    head2->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;

    // 打印链表
    cout << "Input:" << endl;
    cout << "List1:" << endl;
    ListNode* p = head1->next;
    while (p)
    {
        cout << p->data << endl;
        p = p->next;
    }

    cout << "List2:" << endl;
    ListNode* q = head2->next;
    while (q)
    {
        cout << q->data << endl;
        q = q->next;
    }

    ListNode* res = test.Merge(head1, head2);

    // 打印结果
    cout << "Result1:" << endl;
    ListNode* r = res->next;
    while (r)
    {
        cout << r->data << endl;
        r = r->next;
    }

    return 0;
}