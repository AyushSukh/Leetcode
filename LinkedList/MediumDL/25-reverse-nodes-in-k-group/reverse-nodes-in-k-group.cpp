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
    ListNode* reverselinkedlist(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev; // Return the new head of the reversed list
    }

    ListNode* getKthnode(ListNode* temp, int k) {
        k -= 1;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp; // Return the kth node
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevlast = NULL; // This will point to the last node of the previous reversed group

        while (temp != NULL) {
            ListNode* kthnode = getKthnode(temp, k);
            if (kthnode == NULL) {
                // If there are less than k nodes left, connect the last reversed group to the remaining nodes
                if (prevlast) {
                    prevlast->next = temp;
                }
                break; // Exit the loop
            }

            ListNode* nextNode = kthnode->next; // Store the next node after the kth node
            kthnode->next = NULL; // Temporarily break the list

            // Reverse the current group
            ListNode* reversedHead = reverselinkedlist(temp);

            // Connect the previous part with the newly reversed group
            if (prevlast) {
                prevlast->next = reversedHead;
            } else {
                head = reversedHead; // Update head if this is the first group
            }

            // Update prevlast to the end of the newly reversed group
            prevlast = temp;

            // Move temp to the next group
            temp = nextNode;
        }

        return head; // Return the new head of the modified list
    }
};