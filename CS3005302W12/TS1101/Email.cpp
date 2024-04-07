#include "Email.h"

/*constructor*/
// Intent: Defualt constructor for class Email
// Pre: No input needed 
// Post: All members are empty string
Email::Email() :Document()
{
	this->sender = "";
	this->recipient = "";
	this->title = "";
}

// Intent: Constructor fo class Email
// Pre: Input four string representing the content of members
// Post: All members equal the input strings
Email::Email(std::string text, std::string sender, std::string reci, std::string title) 
	:Document(text)
{
	this->sender = sender;
	this->recipient = reci;
	this->title = title;
}

// Intent: Copy Constructor for class Email
// Pre: Input a Email type object
// Post: This object equals the input object
Email::Email(Email& email) :Document(email)
{
	this->sender = email.sender;
	this->recipient = email.recipient;
	this->title = email.title;
}

/*function*/
// Intent: Set the member sender
// Pre: Input a string representing sender
// Post: Member sender equals the input string
void Email::setSender(std::string sender)
{
	this->sender = sender;
}

// Intent: Set the member recipient
// Pre: Input a string representing recipient
// Post: Member recipient equals the input string
void Email::setRecipient(std::string reci)
{
	this->recipient = reci;
}

// Intent: Set the member title
// Pre: Input a string representing title
// Post: Member title equals the input string
void Email::setTitle(std::string title)
{
	this->title = title;
}

// Intent: Get the member sender
// Pre: No input needed
// Post: Return the sender
std::string Email::getSender()
{
	return this->sender;
}

// Intent: Get the member recipient
// Pre: No input needed
// Post: Return the recipient
std::string Email::getRecipient()
{
	return this->recipient;
}

// Intent: Get the member title
// Pre: No input needed
// Post: Return the title
std::string Email::getTitle()
{
	return this->title;
}

/*operator overloading*/
// Intent: Overload assign operator for class Email
// Pre: Input a Email type object
// Post: This object equals the input object
Email& Email::operator=(const Email& email)
{
	this->text = email.text;
	this->sender = email.sender;
	this->recipient = email.recipient;
	this->title = email.title;

	return *this;
}