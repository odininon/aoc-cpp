//
// Created by Stengel on 8/5/2021.
//

#include "Day05.h"
#include <string>

bool ContainsVowels(int amount, const std::string& string)
{
	int count = 0;
	for (char c : string)
	{
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		{
			count += 1;
		}
	}

	return count >= amount;
}

bool ContainsDoubleLetter(const std::string& string)
{
	for (auto i = 0; i < string.size() - 1; i++)
	{
		if (string[i] == string[i + 1])
		{
			return true;
		}
	}

	return false;
}

bool ContainsBadWord(const std::string& string)
{
	if (string.find("ab") != std::string::npos)
	{
		return true;
	}

	if (string.find("cd") != std::string::npos)
	{
		return true;
	}

	if (string.find("pq") != std::string::npos)
	{
		return true;
	}

	if (string.find("xy") != std::string::npos)
	{
		return true;
	}

	return false;
}

bool ContainsSandwich(const std::string& string)
{
	for (auto i = 0; i < (string.size() - 2); ++i)
	{
		if (string[i] == string[i + 2])
		{
			return true;
		}
	}

	return false;
}

bool ContainsDoubleRepeat(const std::string& string)
{
	auto inputStringSize = string.size();
	for (auto i = 0; i < (inputStringSize - 3); ++i)
	{
		for (auto j = i + 2; j < (inputStringSize - 1); ++j)
		{
			if (string[i] == string[j] && string[i + 1] == string[j + 1])
			{
				return true;
			}
		}
	}

	return false;
}

bool IsNiceWordPart1(const std::string& word)
{
	return ContainsVowels(3, word) && ContainsDoubleLetter(word) && !ContainsBadWord(word);
}

bool IsNiceWordPart2(const std::string& word)
{
	return ContainsDoubleRepeat(word) && ContainsSandwich(word);
}

void CalculateNiceWords(const std::vector<std::string>& words, bool (* fn)(const std::string&))
{
	int nice_words = 0;

	for (const auto& word: words)
	{
		auto isNiceWord = fn(word);

		if (isNiceWord)
		{
			nice_words += 1;
		}
	}

	printf("Number of nice words: %i\n", nice_words);
}

void Day05::Part1()
{
	CalculateNiceWords(input, IsNiceWordPart1);
}

void Day05::Part2()
{
	CalculateNiceWords(input, IsNiceWordPart2);
}
