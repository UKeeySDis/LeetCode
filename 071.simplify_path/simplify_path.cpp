class Solution
{
	public:
		string simplifyPath(string path)
		{
			stack<string> s;
			for(int i = 0; i < path.length(); i++)
			{
				string::iterator j = find(path.begin() + i, path.end(), '/');
				string temp(path.begin() + i, j);
				if(!temp.empty() && temp != ".")
				{
					if(temp == "..")
					{
						if(!s.empty())
							s.pop();
					}
					else
					{
						s.push(temp);
					}
				}
				i = j - path.begin();
			}

			if(s.empty())
			{
				return "/";
			}
			else
			{
				string ans = "";
				while(!s.empty())
				{
					const string temp = "/" + s.top();
					ans.insert(0, temp);
					s.pop();
				}
				return ans;
			}

		}
};

