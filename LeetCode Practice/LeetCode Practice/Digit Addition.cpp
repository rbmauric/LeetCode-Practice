  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //Initialization
        ListNode* newList = new ListNode;
        ListNode* zero = new ListNode(0);
        ListNode* listPtr = newList;

        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;

        //Add Each Digit
        while (ptr1 != nullptr || ptr2 != nullptr) {
            if (ptr1 == nullptr)
                ptr1 = zero;
            if (ptr2 == nullptr)
                ptr2 = zero;

            //Addition
            listPtr->val += ptr1->val + ptr2->val;

            //Carry Case
            if (listPtr->val > 9) {
                listPtr->val %= 10;
                ListNode* next = new ListNode(1);
                listPtr->next = next;
            }
            //Regular Case
            else {
                if (ptr1->next != nullptr || ptr2->next != nullptr) {
                    ListNode* next = new ListNode(0);
                    listPtr->next = next;
                }
            }

            //Pointer Advancement
            listPtr = listPtr->next;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return newList;
    }
};