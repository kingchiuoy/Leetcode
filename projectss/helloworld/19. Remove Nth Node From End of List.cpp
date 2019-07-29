/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        ListNode* front, *end;
        ListNode* prev;
        end = head;
        int count = 0;
        while(end != NULL) {
            count++;
            if(count == n) {
                front = head;
            }
            if(count > n) {
                prev = front;
                front = front->next;
            }
            end = end->next;
        }
        if(prev == NULL) {
            prev = head;
            head = head->next;
            delete(prev);
        } else {
            prev->next = front->next;
            delete(front);
        }
        
        return head;
        
        
        
    }
};

int main() {

}