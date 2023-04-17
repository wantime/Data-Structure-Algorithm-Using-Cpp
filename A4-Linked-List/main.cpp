//
// Created by w on 2023/4/17.
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next){}
};
void printListNode(ListNode* head){
    ListNode* cur = head;
    cout<<"head";
    while(cur!=NULL){
        cout<<"->"<<cur->val;
        cur = cur->next;
    }
    cout<<endl;
}
void deleteNode(ListNode* head){
    ListNode *cur = head;
    while(cur != NULL){
        ListNode* delNode = cur;
        cur = cur->next;
        delete delNode;
    }
}
// Leetcode 206
ListNode* reverseList(ListNode* head) {
    ListNode *pre = nullptr;
    ListNode *cur= head;
    while(cur != nullptr){
        ListNode *next = cur->next;
        cur->next = pre;

        pre = cur;
        cur = next;
    }
    return pre;
}
//leetcode 92
ListNode* reverseBetween(ListNode* head, int left, int right) {
    //设置虚拟头节点
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    //寻找left的前一个节点
    ListNode* pre = dummy;
    for(int i = 1; i < left; i ++)
        pre = pre->next;
    //反转left与right之间的部分
    ListNode* cur = pre->next;
    for(int i = left; i < right; i ++){
        ListNode* next = cur->next;

        cur->next = next->next;

        next->next = pre->next;
        pre->next = next;
    }
    return dummy->next;
}
//leetcode 83
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* cur = head;
    while(cur!= NULL && cur->next != NULL){
        ListNode* nex = cur->next;
        while(nex != NULL && nex->val == cur->val) nex = nex->next;
        cur->next = nex;
        cur = nex;
    }
    return head;
}
//leetcode 86
ListNode* partition(ListNode* head, int x) {
    ListNode* part1 = new ListNode(-1);
    ListNode* part2 = new ListNode(-1);
    ListNode* lesser = part1;
    ListNode* greater = part2;

    ListNode* cur = head;
    while(cur != NULL){
        if(cur->val < x){
            lesser->next = cur;
            lesser = lesser->next;
        }
        else {
            greater->next = cur;
            greater = greater->next;
        }
        cur = cur->next;
    }

    greater->next = NULL;
    lesser->next = part2->next;

    return part1->next;
}
//leetcode 328
ListNode* oddEvenList(ListNode* head) {
    ListNode* part1 = new ListNode(-1);
    ListNode* part2 = new ListNode(-1);
    ListNode* odd = part1;
    ListNode* even = part2;

    ListNode* cur = head;
    int count = 1;
    while(cur != NULL){
        if(count % 2 == 1){
            odd->next = cur;
            odd = odd->next;
        }
        else {
            even->next = cur;
            even = even->next;
        }
        cur = cur->next;
        count ++;
    }

    even->next = NULL;
    odd->next = part2->next;

    return part1->next;
}
//leetcode 2
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    int rem = 0;
    ListNode* cur = dummy;
    while(p1 != NULL || p2 != NULL){
        int x1 = p1 == NULL ? 0 : p1->val;
        int x2 = p2 == NULL ? 0 : p2->val;
        int sum = x1 + x2 + rem;
        cur->next = new ListNode(sum%10);
        rem = sum/10;
        if(p1 != NULL) p1 = p1->next;
        if(p2 != NULL) p2 = p2->next;
        cur = cur->next;
    }
    if(rem > 0)
        cur->next = new ListNode(rem);
    return dummy->next;
}

//leetcode 445
ListNode* addTwoNumbers_2(ListNode* l1, ListNode* l2) {
    stack<int> s1;
    stack<int> s2;
    ListNode* c1 = l1;
    while (c1 != NULL){
        s1.push(c1->val);
        c1 = c1->next;
    }
    ListNode* c2 = l2;
    while (c2 != NULL){
        s2.push(c2->val);
        c2 = c2->next;
    }


    stack<int> res;
    int carry = 0;
    while(!s1.empty() || !s2.empty()){
        int x1 = 0;
        if(!s1.empty()){
            x1 = s1.top();
            s1.pop();
        }
        int x2 = 0;
        if(!s2.empty()){
            x2 = s2.top();
            s2.pop();
        }
        int sum = x1 + x2 + carry;
        res.push(sum%10);

        carry = sum/10;
    }
    if(carry > 0)
        res.push(carry);
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    while(!res.empty()){
        cur->next = new ListNode(res.top());
        cur = cur->next;
        res.pop();
    }
    return dummy->next;
}
//leetcode 203
ListNode* removeElements(ListNode* head, int val) {
    ListNode* prev = new ListNode(-1, head);
    ListNode* cur = prev;
    while(cur->next != NULL){
        if(cur->next->val == val){
            ListNode* delNode = cur->next;
            cur->next = delNode->next;
            delete delNode;
        }else{
            cur = cur->next;
        }
    }
    return prev->next;
}

//leetcode 82
ListNode* deleteDuplicates_2(ListNode* head) {
    ListNode* dummy = new ListNode(-1, head);

    ListNode* prev = dummy;
    ListNode* cur = head;

    while(cur != NULL ){

        int num = 0;
        ListNode* p = cur;
        while(p != NULL && p->val == cur->val){
            num ++;
            p = p->next;
        }
        if(num > 1)
            prev->next = p;
        else
            prev = cur;
        cur = p;
    }
    return dummy->next;
}
//leetcode 21
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // 一个最后需要返回的虚拟头节点
    ListNode* dummy = new ListNode(-1);

    ListNode* cur1 = list1;
    ListNode* cur2 = list2;
    ListNode* cur = dummy;
    while(cur1 != NULL || cur2!= NULL){
        if(cur1 == NULL){
            cur->next = cur2;
            cur2 = cur2->next;
        }
        else if (cur2 == NULL){
            cur->next = cur1;
            cur1 = cur1->next;
        }
        else if(cur1->val < cur2->val){
            cur->next = cur1;
            cur1 = cur1->next;
        } else{
            cur->next = cur2;
            cur2 = cur2->next;
        }
        cur = cur->next;
    }
    cur->next = NULL;
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}
//leetcode 24
ListNode* swapPairs(ListNode* head) {
     ListNode* dummy = new ListNode(-1, head);

     ListNode* prev = dummy;

     while(prev->next != NULL && prev->next->next != NULL){
         ListNode* node1 = prev->next;
         ListNode* node2 = node1->next;
         ListNode* next = node2->next;

         node2->next = node1;
         node1->next = next;
         prev->next = node2;

         prev = node1;
     }
     ListNode* newHead = dummy->next;
     delete dummy;
     return newHead;
}
//leetcode 147
ListNode* insertionSortList(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;//虚拟头节点

    ListNode* cur = head->next;//遍历用，指向当前需要插入的节点
    ListNode* tail = head;//遍历用，记录有序元素的尾巴
    while (cur != NULL){

        ListNode* prev = dummy;//记录有序元素的头，方便插入元素用
        ListNode* next = cur->next;//记录当前插入元素的下一个，方便下一个插入用
        // 如果有序，尾巴直接后移
        if(tail->val <= cur->val)
            tail = tail->next;
        else{
            //需要插入，首先prev指向插入的前一个元素
            while( prev->next->val < cur->val){
                prev = prev->next;
            }
            cur->next = prev->next;
            prev->next = cur;
            tail->next = next;
        }
        cur = next;
    }
    ListNode* ret = dummy->next;
    delete dummy;
    return ret;
}
//leetcode 148
ListNode* sortList(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;

    ListNode* slow = head;
    ListNode* fast = head->next;
    // 快慢指针找到中间位置
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* head2 = slow->next;
    slow->next = NULL;
    head = sortList(head);
    head2 = sortList(head2);
    return mergeTwoLists(head, head2);
}
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* slow = dummy;
    ListNode* fast = dummy;
    for(int i = 0; i < n+1; i ++)
        fast = fast->next;

    while(fast != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    ListNode* delNode = slow->next;
    slow->next = delNode->next;
    delete delNode;
    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}

//leetcode 234
ListNode* reverse(ListNode* head){

    ListNode* prev = NULL;
    ListNode* cur = head;
    while(cur != NULL){
        ListNode* next = cur->next;

        cur->next = prev;

        prev = cur;
        cur = next;
    }

    return prev;
}
bool isPalindrome(ListNode* head) {
    if(head == NULL | head->next == NULL)
        return true;
    ListNode* dummy = new ListNode(0, head);

    ListNode* slow = dummy;
    ListNode* fast = slow->next;
    // find middle
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* head2 = slow->next;
    slow->next = NULL;
    head2 = reverse(head2);

    //比较
    ListNode* l1 = head;
    ListNode* l2 = head2;
    while(l1 != NULL && l2 != NULL){
        if(l1->val != l2->val)
            return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    delete dummy;
    return true;

}

// leetcode 143
ListNode* reorderList(ListNode* head) {
    if(head == NULL | head->next == NULL)
        return head;

    ListNode* slow = head;
    ListNode* fast = slow->next;
    // find middle
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* head2 = slow->next;
    slow->next = NULL;
    head2 = reverse(head2);


    // 处理
    ListNode* l1 = head;
    ListNode* l2 = head2;
    ListNode* cur = new ListNode(0);
    while(l1 != NULL && l2 != NULL){
        cur->next = l1;
        l1 = l1->next;
        cur = cur->next;
        cur->next = l2;
        l2 = l2->next;
        cur = cur->next;
    }
    if(l1 != NULL)
        cur->next = l1;
    l1->next = NULL;
    return head;
}

//leetcode 61
ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL)
        return head;
    // 在合适的位置拆开再拼接
    int count = 0;
    ListNode* cur = head;
    while(cur != NULL){
        cur = cur->next;
        count ++;
    }
    k =  k % count;

    ListNode* slow = head;
    ListNode* fast = head;
    for(int i = 0; i < k; i ++)
        fast = fast->next;
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = head;
    head = slow->next;
    slow->next = NULL;
    return head;
}


int main(){
    vector<int> nums = {1,2,3,4,5};
    ListNode* head = new ListNode(nums[0]);
    ListNode* cur = head;
    for(int i = 1; i < nums.size(); i++) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }

    printListNode(head);
    head = reorderList(head);
    printListNode(head);
    deleteNode(head);
    return 0;
}