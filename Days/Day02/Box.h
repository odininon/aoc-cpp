//
// Created by Stengel on 7/28/2021.
//

#pragma once

#include <algorithm>
#include <sstream>

struct Box
{
	int width;
	int height;
	int length;

	[[nodiscard]]
	int SurfaceArea() const
	{
		return 2 * length * width + 2 * width * height + 2 * height * length;
	}

	[[nodiscard]]
	int BowLength() const
	{
		return width * height;
	}

	[[nodiscard]]
	int WrappingPaperNeeded() const
	{
		return SurfaceArea() + BowLength();
	}

	[[nodiscard]]
	int CubicVolume() const
	{
		return length * width * height;
	}

	[[nodiscard]]
	int Parameter() const
	{
		return 2 * width + 2 * height;
	}

	[[nodiscard]]
	int RibbonNeeded() const
	{
		return CubicVolume() + Parameter();
	}

	static Box FromString(const std::string& string)
	{
		std::vector<int> result;
		std::stringstream s_stream(string);

		while (s_stream.good())
		{
			std::string substr;
			std::getline(s_stream, substr, 'x');
			result.push_back(atoi(substr.c_str()));
		}

		std::sort(result.begin(), result.end());

		return { result[0], result[1], result[2] };
	}
};