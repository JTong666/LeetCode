#include<stdio.h>
#include<cstddef>
#include<string>

class TextBlock {
public:
	const char& operator[](std::size_t position) const { return text[position]; }
	char& operator[](std::size_t position) { return text[position]; }

private:
	std::string text;
};


class TextBlock {
public:
	const char& operator[](std::size_t position) const { return text[position]; }

	char& operator[](std::size_t position) { return const_cast<char&>(static_cast<const TextBlock&>(*this)[position]); }

private:
	std::string text;
};