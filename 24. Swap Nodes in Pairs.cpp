

#include<iostream>
#include<vector>
using namespace std;

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}
ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return head;
        int i = 0;
        ListNode* cur, *pre = head;
        ListNode* pos;
        if(cur != nullptr) {
            pos = cur->next;
        } else {
            return head;
        }
        ListNode* temp; // Used for transform
        while(pos != NULL) {
            if(i % 2 == 0) {
                temp = pos->next;
                pos->next = cur;
                cur->next = temp;
                temp = pos;
                pos = cur;
                cur = temp;
                if(i == 0) {
                    head = cur;
                } else {
                    pre->next = cur;
                }
            }
            pre = cur;
            cur = pos;
            pos = pos->next;
            i++;
        }
        return head;
    }
};


int main() {
    Solution c = Solution();

}