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
    ListNode* rotateRight(ListNode* head, int k) {
        // #2 Method to rotate the list to the right by k places (in-place) - O(N) & O(1)
    // Edge case: When the list is empty or single noded
    if(!head || !head->next)
        return head;

    ListNode* nodeLast = head; // Require to track the last node of the list
    int listLength = 1;

    // Iterate and find the last node
    while(nodeLast && nodeLast->next) {
        nodeLast = nodeLast->next, listLength++;
    } 

    // Calculate and store the number of nodes for rotation
    k = k % listLength;

    // If k is zero than return the head node of the list
    if(k == 0) return head;

    ListNode* prevNode = nullptr; // Require to track the previous node of the kTh node (if seen from the end-side)
    ListNode* currNode = head;    // Require to track the kTh node (if seen from the end-side)
    int nodesToSkip = listLength - k; // Calculate and store the number of nodes to skip from the front-side

    // Iterate and find the previous node of the kTh node and itself
    while(currNode && nodesToSkip--) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    // Set the final links for the rotation
    prevNode->next = nullptr;
    nodeLast->next = head;
    head = currNode;

    // Return the head node of the list after rotation
    return head; 
}
};