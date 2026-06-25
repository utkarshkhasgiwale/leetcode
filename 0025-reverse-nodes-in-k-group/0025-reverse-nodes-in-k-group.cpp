/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

 void reverse(ListNode* head, int times){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(times--){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head == NULL) return NULL;

        ListNode* left = head;
        ListNode* right;
        ListNode* prevLeft = NULL;
        ListNode* res = NULL;
        int size = k;

        while(true){
            right = left;
            for(int i = 0; i < size - 1; i++){
                if(right == NULL) break;
                right = right->next;
            }

            if(right){
                ListNode* nxtLeft = right->next;
                reverse(left, size);

                if(prevLeft) prevLeft->next = right;   // link previous group to this reversed group
                if(res == NULL) res = right;           // set head of result once

                prevLeft = left;   // <-- now ALWAYS update, not just when prevLeft existed
                left = nxtLeft;    // <-- now ALWAYS update
            }
            else{
                if(prevLeft) prevLeft->next = left;
                if(res == NULL) res = left;
                break;
            }
        }
        return res;
    }
};
