#include<iostream>
#include<fstream>
#include<string>

int main(int argc, char* argv[])
{
	std::ifstream fin("in.txt");
	std::string tempstr = { 0 };
	std::string str2;
	std::string str = { 0 };
	while (!fin.eof())
	{
		std::getline(fin, str2);
		str = str + str2 + ' ';
	}
	fin.close();
	std::string words[10000];
	int k = 0;
	for (int i = 0; i < size(str); ++i)
	{
		if ((str[i] != ' ') && (str[i] != ',') && (str[i] != '-') && (str[i] != ';') && (str[i] != ':') && (str[i] != '?') && (str[i] != '!') && (str[i] != '.') && (str[i] != '\0'))
		{
			tempstr = tempstr + str[i];
		}
		else
		{
			words[k] = tempstr;
			k = k + 1;
			tempstr = "";
		}
	}
	int count = 1;
	int max = 0;
	std::string word;
	for (int i = 0; i < k - 1; ++i)
	{
		for (int j = i; j < k; ++j)
		{
			if( (words[i] == words[j])&&(size(words[i])>=1))
			{
				count = count + 1;
			}
		}
		if (count > max)
		{
			max = count;
			word = words[i];
		}
		count = 1;
	}

	std::ofstream fout("out.txt");
	fout  << word << std::endl;
	fout.close();

	return EXIT_SUCCESS;
}