#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode* ret(NULL);
        if (l1 && l2) {
            if (l1->val <= l2->val) {
                ret = l1;
                l1 = l1->next;
            }
            else {
                ret = l2;
                l2 = l2->next;
            }
        }
        auto final_ret = ret;    
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                ret->next = l1;
                ret = l1;
                l1 = l1->next;
            } 
            else {
                ret->next = l2;
                ret = l2;
                l2 = l2->next;
            }
        }
        if (l1 == NULL) ret->next = l2;
        if (l2 == NULL) ret->next = l1;
        return final_ret;
    }
    
};

void printList(ListNode* n) 
{ 
    while (n != NULL) { 
        cout << n->val << " "; 
        n = n->next; 
    } 
} 

int main()
{
    Solution S;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(5);
    ListNode* n3 = new ListNode(10);
    ListNode* na = new ListNode(2);
    ListNode* nb = new ListNode(3);
    ListNode* nc = new ListNode(8);
    ListNode* nd = new ListNode(200);
    n1->next = n2;
    n2->next = n3;
    na->next = nb;
    nb->next = nc;
    nc->next = nd;
    ListNode* result = S.mergeTwoLists(n1, na);
    printList(result); 
    //cout << "The answer is: " << result->val << endl;
    return 0;
}