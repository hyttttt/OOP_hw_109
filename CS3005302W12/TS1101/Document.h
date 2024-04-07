#pragma once
#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>

class Document
{
public:
	/*member*/
	std::string text;

	/*constructor*/
	Document();
	Document(std::string text);
	Document(Document& doc);

	/*function*/
	void setText(std::string text);
	std::string getText() const;

	/*operator overloading*/
	Document& operator=(const Document& doc);
};

#endif // !DOCUMENT_H