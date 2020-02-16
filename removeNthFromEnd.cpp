#include<iostream>
#include<cassert>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = findLength(head);
        // If the deleted node is the first node
        if (length - n == 0) return head->next;
        if (length - n < 0) return NULL;
        auto tmp = head;
        for (int i = 0; i < length; i++) {
            // If the deleted node is not the first node
            if (i == length - n - 1) {
                if (tmp->next) {
                    tmp->next = tmp->next->next;
                    cout << "removing! ";
                } 
                else
                    tmp->next = NULL;
                break;
            } 
            else
                tmp = tmp->next;
        }
        return head;
    }
private: 
    int findLength(ListNode* head) {  
	// Find the length of a linked list
        int len = 0;
        while(head != NULL){
            head = head-> next;
            len++;
        }
        return len;       
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
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    ListNode* result = S.removeNthFromEnd(n1, 2);
    printList(result); 
    //cout << "The answer is: " << result->val << endl;
    return 0;
}