#pragma once
#ifndef FILE_H
#define FILE_H

#include "Document.h"
#include <string>

class File :public Document
{
public:
	/*member*/
	std::string pathName;

	/*constructor*/
	File();
	File(std::string text, std::string path);
	File(File& file);

	/*function*/
	void setPathname(std::string path);
	std::string getPathname();

	/*operator overloading*/
	File& operator=(const File& file);
};

#endif // !FILE_H