#include "Util.h"


std::string LoadFileAsString(std::string fileName)
{
	std::stringstream stream;
	std::ifstream file(fileName);


	if (file.is_open())
	{
		while (!file.eof())
		{
			std::string line;
			std::getline(file, line);
			stream << line << std::endl;
		}
		return stream.str();
		file.close();
	}
	else
	{
		std::cout << "Error occured while trying to read file" << std::endl;
		return "";
	}
}