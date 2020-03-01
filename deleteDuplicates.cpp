#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr && curr->next) {
            if (curr->val == curr->next->val)
                curr->next = curr->next->next;
            else
                curr = curr->next;
        }
        return head;
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
    ListNode* n2 = new ListNode(1);
    ListNode* n3 = new ListNode(2);

    n1->next = n2;
    n2->next = n3;

    ListNode* result = S.deleteDuplicates(n1);
    printList(result); 
    //cout << "The answer is: " << result->val << endl;
    return 0;
}