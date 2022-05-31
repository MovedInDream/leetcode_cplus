// 反转链表
// 描述：给定一个单链表的头结点pHead(该头节点是有值的，比如在下图，它的val是1)，长度为n，反转该链表后，返回新链表的表头。
// 解题思路1：
// 可以参考jz06的思路
// 根据栈先进后出的性质，把链表节点一个个入栈，
// 当全部入栈完之后再一个个出栈，出栈的时候在把出栈的结点串成一个新的链表

// 解题思路2:
// 遍历链表每个节点的next指向前一个节点


#include <iostream>
#include <vector>
#include <stack>

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
    ListNode* ReverseList1(ListNode *pHead)
    {
        stack<int> s;
        ListNode *node = pHead->next;

        while (node)
        {
            s.push(node->data);
            node = node->next;
        }
        if (s.empty())
        {
            return NULL;
        }

        ListNode* newHead = new ListNode;
        ListNode* preNode = newHead;

        while (!s.empty())
        {
            ListNode* curNode = new ListNode(s.top());
            preNode->next = curNode;
            preNode = curNode;
            s.pop();
        }

        return newHead;
    }

    ListNode* ReverseList2(ListNode* pHead)
    {
        if(pHead == NULL)
        {
            return NULL;
        }

        ListNode* cur = pHead;
        ListNode* pre = nullptr;

        while(cur)
        {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        return pre;
    }
};

int main()
{
    cout << "This test is for jz06:" << std::endl;

    Solution test;

    // 构造链表
    cout << "creating lianbiao ..." << endl;
    ListNode* head = new ListNode;
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;

    // 打印链表
    cout << "Input:" << endl;
    ListNode* p = head->next;
    while (p)
    {
        cout << p->data << endl;
        p = p->next;
    }

    ListNode* res1 = test.ReverseList1(head);
    ListNode* res2 = test.ReverseList1(head);

    // 打印结果
    cout << "Result1:" << endl;
    ListNode* q = res1->next;
    while (q)
    {
        cout << q->data << endl;
        q = q->next;
    }

    cout << "Result2:" << endl;
    ListNode* r = res2->next;
    while (r)
    {
        cout << r->data << endl;
        r = r->next;
    }

    return 0;
}