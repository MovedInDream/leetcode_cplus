// 两个链表的第一个公共节点
// 描述：输入两个无环的单向链表，找出它们的第一个公共节点，如果没有公共节点则返回空。
// 解题思路:
// 使用两个指针分别遍历两个链表
// 当其中一个链表便利到尾部时，指针指向另一个链表表头
// 无论如何两个指针最终会相遇
// 若有公共节点，相遇的地方即为公共节点
// 若没有公共节点，可以预见相遇的地方在各自链表尾部，也为NULL

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
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* l1 = pHead1->next;
        ListNode* l2 = pHead2->next;
        while(l1 != l2)
        {
            l1 = (l1 == NULL)?pHead1:l1->next;
            l2 = (l2 == NULL)?pHead2:l2->next;
        }
        return l1;
    }
};

int main()
{
    cout << "This test is for jz52:" << std::endl;

    Solution test;

    // 构造链表
    ListNode* head1 = new ListNode;
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);

    head1->next = node1;
    node1->next = node2;
    node2->next = node3;

    ListNode* head2 = new ListNode;
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    head2->next = node4;
    node4->next = node5;

    ListNode* public1 = new ListNode(6);
    ListNode* public2 = new ListNode(7);
    public1->next = public2;

    node3->next = public1;
    node5->next = public1;

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

    ListNode* res = test.FindFirstCommonNode(head1, head2);

    // 打印结果
    cout << "Result:" << endl;
    cout << res->data << endl;

    return 0;
}