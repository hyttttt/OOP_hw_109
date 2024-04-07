#include "Document.h"

/*constructor*/
// Intent: Default constructor for class Document
// Pre: No input needed
// Post: Member text is empty string
Document::Document()
{
	this->text = "";
}

// Intent: Constructor for class Document
// Pre: Input a string representing the content
// Post: Member text is the input string
Document::Document(std::string text)
{
	this->text = text;
}

// Intent: Copy constructor for class Document
// Pre: Input a Document type object
// Post: This object equals the input object
Document::Document(Document& doc)
{
	this->text = doc.text;
}

/*function*/
// Intent: Set the text
// Pre: Input a string representing the content
// Post: Text is the input string
void Document::setText(std::string text)
{
	this->text = text;
}

// Intent: Get the text
// Pre: No input needed
// Post: Return the text
std::string Document::getText() const
{
	return this->text;
}

/*operator overloading*/
// Intent: Overload assign operator for class Document
// Pre: Input a Document type object
// Post: This object equals the input object
Document& Document::operator=(const Document& doc)
{
	this->text = doc.text;
	return *this;
}