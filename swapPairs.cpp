#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        while (head && head->next && head->next->next) {
            auto tmp1 = head->next;
            auto tmp2 = tmp1->next;
            tmp1->next = tmp2->next;
            tmp2->next = tmp1;
            
            head->next = tmp2;
            head = tmp1;
            
        }
        return dummy.next;
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
    ListNode* a1 = new ListNode(1);
    ListNode* a2 = new ListNode(2);
    ListNode* a3 = new ListNode(3);
    //ListNode* a4 = new ListNode(4);
    a1->next = a2;
    a2->next = a3;
    //a3->next = a4;
    printList( S.swapPairs(a1) );
    
    //cout << "The answer is: " << result->val << endl;
    return 0;
}