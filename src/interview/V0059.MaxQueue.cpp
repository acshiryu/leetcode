//
// Created by hzl on 2020/3/7.
//

#include <include/cplusplus.h>

class MaxQueue {
 public:
  MaxQueue() {

  }

  int max_value() {
    return set_.empty() ? - 1 : *set_.rbegin();
  }

  void push_back(int value) {
    deque_.push_back(value);
    set_.insert(value);
    set_.erase(set_.begin(), set_.find(value));
  }

  int pop_front() {
    if (deque_.empty()) {
      return -1;
    }

    auto front = deque_.front();
    if (*set_.rbegin() == front)
    {
      set_.erase(set_.find(front));
    }
    deque_.pop_front();
    return front;
  }

 private:
  deque<int> deque_;
  std::multiset<int> set_;
};

int32_t main()
{
  MaxQueue* obj = new MaxQueue();
  int param_1 = obj->max_value();
  obj->push_back(1000);
  int param_3 = obj->pop_front();

  dbg(param_1);
  dbg(param_3);

  return 0;
}

