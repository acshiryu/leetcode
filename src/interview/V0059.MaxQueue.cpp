//
// Created by hzl on 2020/3/7.
//

#include <include/cplusplus.h>

class MaxQueue
{
 public:
  MaxQueue()
  {

  }

  int max_value()
  {
    return deque_.empty() ? -1 : deque_.front();
  }

  void push_back(int value)
  {
    queue_.push(value);
    while (!deque_.empty() && value > deque_.back() ){
      deque_.pop_back();
    }
    deque_.push_back(value);
  }

  int pop_front()
  {
    if (queue_.empty()) {
      return -1;
    }

    auto front = queue_.front();
    queue_.pop();

    if (front == deque_.front())
    {
      deque_.pop_front();
    }

    return front;
  }

 private:
  deque<int> deque_;
  queue<int> queue_;
};

int32_t main()
{
  MaxQueue *obj = new MaxQueue();
  int param_1 = obj->max_value();
  obj->push_back(1000);
  int param_3 = obj->pop_front();

  dbg(param_1);
  dbg(param_3);

  return 0;
}

