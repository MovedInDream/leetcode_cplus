// 从头到尾打印链表
// 描述：输入链表的头节点，按链表从尾到头返回每个节点的值（用数组返回）。
// 解题思路1：利用递归函数
// step 1：从表头开始往后递归进入每一个节点。
// step 2：遇到尾节点后开始返回，每次返回依次添加一个值进入输出数组。
// step 3：直到递归返回表头。

// 知识点：递归
// 递归是一个过程或函数在其定义或说明中有直接或间接调用自身的一种方法，它通常把一个大型复杂的问题层层转化为一个与原问题相似的规模较小的问题来求解。
// 因此递归过程，最重要的就是查看能不能讲原本的问题分解为更小的子问题，这是使用递归的关键。

// 解题思路2:栈
// step 1：顺序遍历链表，将链表的值push到栈中。
// step 2：依次弹出栈中的元素，加入到数组中，即可实现链表逆序。

// 知识点：栈
// 栈是一种仅支持在表尾进行插入和删除操作的线性表，栈的两端分别为栈顶和栈底。
// 元素入栈指的是把新元素放到栈顶元素的上面，使之成为新的栈顶元素；
// 元素出栈指的是从一个栈删除元素又称作出栈或退栈，它是把栈顶元素删除掉，使其相邻的元素成为新的栈顶元素。

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode
{
    int data;
    struct ListNode* next;

    ListNode()
    {
        next = NULL;
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
    // 递归函数
    void recursion(ListNode* head, vector<int>& res)
    {
        if(head)
        {
            recursion(head->next, res);
            res.push_back(head->data);
        }
    }

    vector<int> printListFromTailToHead1(ListNode* head)
    {
        vector<int> res;
        recursion(head, res);

        return res;
    }

    vector<int> printListFromTailToHead2(ListNode* head)
    {
        vector<int> res;
        stack<int> s;
        // 遍历链表并将每个元素压入栈中
        while(head)
        {
            s.push(head->data);
            head = head->next;
        }

        // 弹出栈中元素
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }

        return res;
    }
};

int main()
{
    cout << "This test is for jz06:" << std::endl;

    Solution test;

    // 构造链表
    ListNode head = ListNode();
    ListNode node1 = ListNode(1);
    ListNode node2 = ListNode(2);
    ListNode node3 = ListNode(3);
    head.next = &node1;
    node1.next = &node2;
    node2.next = &node3;

    // 打印链表
    cout << "Input:" << endl;
    ListNode* p = head.next;
    while(p)
    {
        cout << p->data << endl;
        p = p->next;
    }

   vector<int> res1 = test.printListFromTailToHead1(&node1);
   vector<int> res2 = test.printListFromTailToHead2(&node1);

   // 遍历打印
    cout << "Result1:" << endl;
   for(int i = 0; i< res1.size(); i++)
   {
       cout << res1[i] << endl;
   }

    cout << "Result2:" << endl;
   for(int i = 0; i< res1.size(); i++)
   {
       cout << res1[i] << endl;
   }

    return 0;
}