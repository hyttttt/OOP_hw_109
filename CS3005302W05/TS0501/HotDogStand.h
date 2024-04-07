#pragma once

class HotDogStand
{
public:
	HotDogStand(const char *id);
	HotDogStand(const char *id, int amount);
	HotDogStand();
	~HotDogStand();
	void justSold();
	void print();
	int thisStandSoldAmount();
	static int allStandSoldAmount() { return totalSellAmount; }
private:
	char *standId;
	int hotDogSellAmount;
	static int totalSellAmount;
};


