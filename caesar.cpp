#include "casesarHeader.h"

int getIndexOf(char& c)
{
	for (int i = 0; i < 26; i++)
	{
		if (letters[i] == c)
		{
			return i;
		}

	}
	return -1;
}


vector<int> key_arr(string key)
{
	vector<int > v;
	int size = key.size();
	for (int i = 0; i < size; i++)
	{
		v.push_back(int(key[i]) - '0');
		std::cout << v[i] << std::endl;
	}


	return v;

}

void encrypt(string str)
{
	if (str.size()>0)
	{

		vector<int> keys = key_arr(str);
		bool run = true;
		while (run)
		{

			string exp;
			std::cout << "enter exp: " << std::endl;
			std::cin >> exp;
			std::cout << "str:  " << str << std::endl;
			if (exp == "pause")
			{
				break;
			}
			else
			{
				for (int i = 0; i < exp.size(); i++)
				{
					int index = getIndexOf(exp[i]);
					int key = keys[i % 5];
					if (i + key < letters.size())
					{
						exp[i] = letters[index + key];


					}
					else {
						exp[i] = letters[(index + key) % 26];
					}
				}
			}

		}
	}
}