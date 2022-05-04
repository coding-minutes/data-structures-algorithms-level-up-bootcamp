
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void maxSubArrayK(vector<int> &nums, int k)
{
  vector<int> ans;
  deque<int> dq;
  for (int i = 0; i < nums.size(); i++)
  {
    if (!dq.empty() && dq.front() == i - k)
      dq.pop_front();
    while (!dq.empty() && nums[dq.back()] < nums[i])
      dq.pop_back();
    dq.push_back(i);
    if (i >= k - 1)
      ans.push_back(nums[dq.front()]);
  }
  for (int i : ans)
  {
    cout << i << " ";
  }
}

int main()
{
  vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  maxSubArrayK(nums, k);
  return 0;
}
