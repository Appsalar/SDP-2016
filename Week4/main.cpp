#include <string>
#include <stack>

using namespace std;


int main()
{

	string input = "5+8*4+9";
	stack<char> a;
	string res;

	for (size_t i = 0; i < input.size(); i++)
	{
		if (isdigit(input[i]))
			res += input[i] + " ";
		else
		{
			switch (input[i])
			{
			case '-':
			case '+':
				if (a.empty())
					a.push(input[i]);
				else
				{
					res += a.top() + " ";
				}
			}
		}
	}

	return 0;
}