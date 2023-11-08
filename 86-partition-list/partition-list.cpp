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
    ListNode* partition(ListNode* h, int x) {
        
        vector<int> all,less,more;
        
        
        ListNode* hh = h;
        while(hh)
        {
            all.push_back(hh->val);
            hh = hh->next;
        }
        
        
        for(auto i:all)
        {
            if(i<x)
                less.push_back(i);
            else
                more.push_back(i);
        }
        
        
        ListNode *s = new  ListNode(-1);
        ListNode *start;
        start = s;
        
        for(int i=0;i<less.size();i++)
        {
            s->next = new  ListNode(less[i]); 
            s = s->next;
        }
        
        for(int i=0;i<more.size();i++)
        {
            s->next = new  ListNode(more[i]);   
            s = s->next;
        }
        
        return start->next;
        
    }
};