#include <iostream>
#include <vector>

class Widget
{};

class TextBlock {
public:
	TextBlock(const std::string str)
	{
		text = str;
	}

	const char& operator[](const std::size_t position) const  // operator for const objects
	{
		return text[position];
	}

	char& operator[](const std::size_t position)
	{
		return const_cast<char&>(static_cast<const TextBlock&>(*this)[position]);
	}

private:
	std::string text;

};


class CTextBlock {
public:
	CTextBlock(const char* string)
	{
		textLength = (string ? strlen(string) + 1 : 0);
		if (textLength)
			pText = new char[textLength]();

		if (textLength == 0) pText[0] = 0;
		else strcpy_s(pText, textLength, string);
	}

	size_t length() const;

	char& operator[](std::size_t position) const
	{
		return pText[position];
	}
private:
	char *pText;
	
	mutable size_t textLength; // last calculated lendth of textblock
	mutable bool lengthIsValid; // whether length is currently valid
};

size_t CTextBlock::length() const
{
	if (!lengthIsValid)
	{
		textLength = strlen(pText); // error! can't assign to textLength
		lengthIsValid = true;		// and lengthIsValid in a const member function
	}

	return textLength;
}