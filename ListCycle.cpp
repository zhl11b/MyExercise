/* 
* Given a linked list, determine if it has a cycle in it.
* Follow up:
* Can you solve it without using extra space?
* 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //! 我的解法，时间复杂度太高
bool hasCycle(struct ListNode *head) {
    if(head == NULL) return false;
    struct ListNode*node = head->next;
    
    while(node!=NULL&&node->next!=NULL)
    {
        if(node->next == node) return true;
        struct ListNode*tmp = head;
        while(tmp!=NULL&&tmp->next!=NULL&&tmp!=node)
        {
            if(tmp == node->next) return true;
            tmp=tmp->next;
        }
        node = node->next;

    }
    return false;
}

/* 
*使用慢指针循环和快指针循环，快指针最终会追上慢指针
*用两个移动的指针可以确保：如果有环的话两个指针都会进入有环的部分。
*一旦进入有环的部分，一快一慢，就相当于一个静止另一个移动。
*/
bool hasCycle(ListNode* head)
{
    if(NULL == head) return false;
    ListNode* p = head;
    ListNode* q = head;
    while(true)
    {
        p = p->next;
        q = q->next;
        if(NULL != q) q = q->next;
        if(NULL == q || NULL == p) return false;
        else if(p == q) return true;
    }
}
