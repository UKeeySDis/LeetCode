class Solution
{
	public:
		vector<vector<string> > groupAnagrams(vector<string> &strs)
		{
			unordered_map<string, vector<string> > m;
			for(int i = 0; i < strs.size(); i++)
			{
				string temp = strs[i];
				sort(strs[i].begin(), strs[i].end());
				m[temp].push_back(strs[i]);
			}
			vector<vector<string> > res;
			for(auto it = m.cbegin(); it != m.cend(); it++)
			{
					res.push_back(it->second);
			}
			return res;
		}

};
