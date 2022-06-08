// 链表中环的入口节点
// 描述：给定一个长度为n的链表，若其中包含环，找出该链表的环的入口节点，否则，返回null
// 解题思路1:
// 用set/map储存已经遍历过的节点
// 当第一次出现重复节点时，即为入口节点

// 解题思路2：
// 定义fast和slow快慢两个指针
// slow指针每走一步，fast指针走两步
// 若是有环，则一定会在某个节点处相遇（slow == fast）
// 将slow指针保持在该节点不变，fast指针放回表头
// 两个指针逐步遍历，再次相遇的地方即为环的入口

#include <iostream>
#include <unordered_set>
#include <map>

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
    ListNode* EntryNodeOfloop1(ListNode* pHead)
    {
        unordered_set<ListNode*> set;
        ListNode* cur = pHead->next;

        while (cur)
        {
            if(set.count(cur))
            {
                return cur;
            }
            else
            {
                set.insert(cur);
            }
            cur = cur->next;
        }

        return NULL;
    }

    ListNode* EntryNodeOfloop2(ListNode* pHead)
    {
        if(pHead->next == NULL)
        {
            return NULL;
        }

        // 快慢双指针
        ListNode* fast = pHead->next;
        ListNode* slow = pHead->next;

        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            // BM6方法判断表中是否存在环，并找到相遇节点
            if(fast == slow)
            {
                fast = pHead->next;

                while(fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }

                return slow;
            }
        }

        return NULL;
    }
};

int main()
{
    cout << "This test is for jz23:" << std::endl;

    Solution test;

    // 构造链表
    ListNode* head = new ListNode;
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node3;

    ListNode* res1 = test.EntryNodeOfloop1(head);
    ListNode* res2 = test.EntryNodeOfloop2(head);

    // 打印结果
    cout << "Result1:" << endl;
    if(res1 != NULL)
    {
        cout << res1->data << endl;
    }
    else
    {
        cout << "NULL" << endl;
    }

    cout << "Result2:" << endl;
    if(res2 != NULL)
    {
        cout << res2->data << endl;
    }
    else
    {
        cout << "NULL" << endl;
    }

    return 0;
}