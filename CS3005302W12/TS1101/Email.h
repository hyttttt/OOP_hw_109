#pragma once
#ifndef EMAIL_H
#define EMAIL_H

#include "Document.h"
#include <string>

class Email :public Document
{
public:
	/*member*/
	std::string sender;
	std::string recipient;
	std::string title;

	/*constructor*/
	Email();
	Email(std::string text, std::string sender, std::string reci, std::string title);
	Email(Email& email);

	/*function*/
	void setSender(std::string sender);
	void setRecipient(std::string reci);
	void setTitle(std::string title);
	std::string getSender();
	std::string getRecipient();
	std::string getTitle();

	/*operator overloading*/
	Email& operator=(const Email& email);
};

#endif // !EMAIL_H