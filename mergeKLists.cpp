#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        // lambda
        auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare) > pq(compare);
        for (ListNode* l : lists)
            if (l) pq.push(l);
            
        while ( !pq.empty() ){
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
            if (tail->next) pq.push(tail->next);

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
    ListNode* a2 = new ListNode(5);
    ListNode* a3 = new ListNode(10);
    ListNode* b1 = new ListNode(2);
    ListNode* b2 = new ListNode(3);
    ListNode* b3 = new ListNode(200);
    ListNode* c1 = new ListNode(5);
    ListNode* c2 = new ListNode(9);
    a1->next = a2;
    a2->next = a3;
    b1->next = b2;
    b2->next = b3;
    c1->next = c2;
    vector<ListNode*> para{a1, b1, c1};
    ListNode* result = S.mergeKLists(para);
    printList(result); 
    //cout << "The answer is: " << result->val << endl;
    return 0;
}