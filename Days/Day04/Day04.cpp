//
// Created by Stengel on 8/4/2021.
//

#include "Day04.h"

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1

#include "cryptopp/md5.h"
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>

inline std::string MD5(const std::string& data)
{
	std::string res;
	CryptoPP::Weak::MD5 hash;
	CryptoPP::byte digest[CryptoPP::Weak::MD5::DIGESTSIZE];

	hash.CalculateDigest(digest, (CryptoPP::byte*)data.c_str(), data.size());

	CryptoPP::HexEncoder encoder;
	encoder.Attach(new CryptoPP::StringSink(res));
	encoder.Put(digest, sizeof(digest));
	encoder.MessageEnd();

	return res;
}

int64_t FindSuffixForMD5(const std::string& prefix, const std::string& needed_hash)
{
	int64_t number = 0;

	std::string ret;
	do
	{
		number += 1;
		auto stuff = std::string(prefix + std::to_string(number));
		ret = MD5(stuff);
	} while (ret.rfind(needed_hash, 0) != 0);

	return number;
}

void Day04::Part1()
{
	auto suffix = FindSuffixForMD5("iwrupvqb", "00000");
	printf("[xxxxxxxx] %lli\n", suffix);
}

void Day04::Part2()
{
	auto suffix = FindSuffixForMD5("iwrupvqb", "000000");
	printf("[xxxxxxxx] %lli\n", suffix);
}
