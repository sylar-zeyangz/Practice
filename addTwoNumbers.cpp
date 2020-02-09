#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool increment = 0;
        ListNode* l3 = NULL;
        ListNode** node = &l3;
        while (l1 || l2 || increment) {
            int sum = 0;
            if (!l1 && !l2) {
                *node = new ListNode(increment);
                node = &((*node)->next);
                increment = 0;
                break;
            }
            
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += increment;
            *node = new ListNode( sum % 10 );
            node = &((*node)->next);
            if (sum >= 10)
                increment = 1;
            else
                increment = 0;
        }
        return l3;
    }
};

int main()
{
    Solution S;
    ListNode* n1 = new ListNode(5);
    ListNode* n2 = n1;
    ListNode* result = S.addTwoNumbers(n1, n2);
    cout << "The answer is: " << result->val << endl;
    return 0;
}