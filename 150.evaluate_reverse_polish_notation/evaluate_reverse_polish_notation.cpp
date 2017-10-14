class Solution
{
	public:
		int evalRPN(vector<string> &tokens)
		{
			stack<string> num;
			for(int i = 0; i < tokens.size(); i++)
			{
				if(judge_operator(tokens[i]))
				{
					int a = stoi(num.top());
					num.pop();
					int b = stoi(num.top());
					num.pop();
					int c;
					if(tokens[i] == '+')	c = a + b;
					else if(token[i] == '-') c = b - a;
					else if(token[i] == '*') c = a * b;
					else	c = b / a;
					num.push(to_string(c));
				}
				else
				{
					num.push(tokens[i]);
				}
			}
			return num.top();
		}
		bool judge_operator(const string &op)
		{
			if(op == "+" || op == '-' || op == '*' || op == '/')
			{
				return true;
			}
			return false;
		}
};
