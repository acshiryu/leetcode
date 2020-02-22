//
// Created by hzl on 2020/2/19.
//

#include <include/cplusplus.h>

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    static int32_t ten = 0;
    if (nullptr == l1 && nullptr == l2)
    {
      ListNode* pnext = nullptr;
      if (ten >= 1)
      {
        pnext = new ListNode(1);
        ten = 0;
      }
      return  pnext;
    }

    if (nullptr == l1)
    {
      return addTwoNumbers(l2, l1);
    }


    if (nullptr == l2)
    {
      if (ten > 0)
      {
        ++l1->val;
        if (l1->val >= 10)
        {
          l1->val-=10;
          auto pnext = addTwoNumbers(l1->next, nullptr);
          l1->next = pnext;
        }
        else
        {
          ten = 0;
        }
      }

      return l1;
    }

    ListNode* pthis  = new ListNode(l1->val + l2->val + ten);
    if (pthis->val >= 10)
    {
      pthis->val -= 10;
      ten = 1;
    }
    else
    {
      ten = 0;
    }
    ListNode* pnext = addTwoNumbers(l1->next, l2->next);
    pthis->next = pnext;
    return pthis;
  }
};

int32_t main()
{
  return 0;
}