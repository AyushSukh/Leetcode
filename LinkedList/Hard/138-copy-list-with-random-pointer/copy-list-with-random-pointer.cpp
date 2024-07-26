
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertcopyinbetween(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* nextnode = temp->next;
            Node* copy = new Node(temp->val);
            copy->next = nextnode;
            temp->next = copy;
            temp = temp->next->next;
        }
    }
    void connectrandompointer(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* copynode = temp->next;
            if (temp->random)
                copynode->random = temp->random->next;
            else {
                copynode->random = NULL;
            }
            temp = temp->next->next;
        }
    }
    Node* getdeepcopylist(Node* head) {
        Node* temp = head;
        Node* dummynode = new Node(-1);
        Node* res = dummynode;
        while (temp != NULL) {
            // creating a new list
            res->next = temp->next;
            res = res->next;
            // disconnecting previous next pointer that were distorted
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummynode->next;
    }

    Node* copyRandomList(Node* head) {
        insertcopyinbetween(head);
        connectrandompointer(head);
        return getdeepcopylist(head);
    }
};