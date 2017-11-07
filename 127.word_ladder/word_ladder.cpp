/* bfs+哈希set完成
 * 开始做的时候直接用vector来查找和删除单词
 * 但是泛型算法里的find太慢,为O(n)
 * 导致数据量一大就超时了
 * 后来改成用哈希set来存wordDict就行了
 */
class Solution
{
	public:
		int ladderLength(string beginWord, string endWord, vector<string>& wordDict)
		{
			queue<string> to_visit;
            unordered_set<string> dict;
            for (int i = 0; i < wordDict.size(); i++) 
            {
                dict.insert(wordDict[i]);
            }
			add_next_word(beginWord, to_visit, dict);
            int result = 2;
			while(!to_visit.empty())
			{
				int len = to_visit.size();
				for(int i = 0; i < len; i++)
				{
					string word = to_visit.front();
					to_visit.pop();
					if(word == endWord)
					{
						return result;
					}
                    add_next_word(word, to_visit, dict);
					
				}
				result++;
			}
            return 0;
		}
		void add_next_word(string word, queue<string>& to_visit, unordered_set<string>& dict)
		{
            dict.erase(word);
			for(int i = 0; i < word.length(); i++)
			{
				char str = word[i];
				for(int j = 0; j < 26; j++)
				{
					word[i] = 'a' + j;
					if(dict.find(word) != dict.end())
					{
						to_visit.push(word);
                        dict.erase(word);
					}
				}
				word[i] = str;
			}
		}
};

