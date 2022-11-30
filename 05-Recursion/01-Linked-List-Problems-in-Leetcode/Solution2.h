//
// Created by lenovo on 2022/10/21.
//

#ifndef INC_01_LINKED_LIST_PROBLEMS_IN_LEETCODE_SOLUTION2_H
#define INC_01_LINKED_LIST_PROBLEMS_IN_LEETCODE_SOLUTION2_H
  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev = new ListNode(0, head);
        ListNode *dummyHead = prev;
        while (prev != nullptr){
            if (prev->next != nullptr && prev->next->val == val ){
                prev->next = prev->next->next;
            } else{
                prev = prev->next;
            }
        }

        return dummyHead->next;
    }
};
#endif //INC_01_LINKED_LIST_PROBLEMS_IN_LEETCODE_SOLUTION2_H
