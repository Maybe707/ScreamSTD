#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <sstream>
#include <cstdarg>

void XorSwap(char* x, char* y) 
{
  if (x != y)
  {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
  }
}

char* reverseString( char* string, unsigned int size ) {
    char element0;
	char element1;

	for ( int i = 0; i < size / 2; ++i) {
		element0 = string[i];
		element1 = string[size - i - 1];

		string[size - i - 1] = element0;
		string[i] = element1;
	}
	
	return string;
}

std::string toString(int value) {
	unsigned int stringIndex = 0;
	int var = 0;
	char buffer[12];
	
	while(value > 0) {
		var = value % 10;
		value = value / 10;
		var += 48;

		buffer[stringIndex] = var;
		++stringIndex;
	}

	reverseString(buffer, stringIndex);
	buffer[stringIndex] = '\0';
	return std::string (buffer);
}

std::string concatIntBetweenTwoStrings(	std::string leftString, unsigned int value, std::string rightString ) {
	std::string resultString = leftString + toString(value) + rightString;
	
	return resultString;
}

int main(int argc, char* argv[])
{
	int value = 12345;

	int iterations = 1'000'000;
	while (iterations > 0) {
		std::string string1 = toString(value);
		--iterations;
	}
	
	return 0;
}
