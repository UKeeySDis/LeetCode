/*************************************************************************
  > File Name: two_sum_first.cpp
  > Author: Ukey
  > Mail: gsl110809@gmail.com
  > Created Time: 2017年08月27日 星期日 10时53分12秒
 ************************************************************************/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int> result;
			vector<int>::iterator first = nums.begin();
			vector<int>::iterator end = nums.end();
			for(;first != end; first++)
			{
				int x = target - *first;
				vector<int>::iterator res = find(first + 1, end, x);
				if(res != end)
				{
					result.push_back(first - nums.begin());
					result.push_back(res -  nums.begin());
					return result;
				}
			}
		}
};
