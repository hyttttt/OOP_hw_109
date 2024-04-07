#include "File.h"

/*constructor*/
// Intent: Defualt constructor for class File
// Pre: No input needed 
// Post: All members are empty string
File::File() :Document()
{
	this->pathName = "";
}

// Intent: Constructor fo class File
// Pre: Input four string representing the content of members
// Post: All members equal the input strings
File::File(std::string text, std::string path) : Document(text)
{
	this->pathName = path;
}

// Intent: Copy Constructor for class File
// Pre: Input a File type object
// Post: This object equals the input object
File::File(File& file) : Document(file)
{
	this->pathName = file.pathName;
}

/*function*/
// Intent: Set the member pathName
// Pre: Input a string representing pathName
// Post: Member pathName equals the input string
void File::setPathname(std::string path)
{
	this->pathName = path;
}

// Intent: Get the member pathName
// Pre: No input needed
// Post: Return the pathName
std::string File::getPathname()
{
	return this->pathName;
}

/*operator overloading*/
// Intent: Overload assign operator for class Fi;e
// Pre: Input a File type object
// Post: This object equals the input object
File& File::operator=(const File& file)
{
	this->text = file.text;
	this->pathName = file.pathName;

	return *this;
}