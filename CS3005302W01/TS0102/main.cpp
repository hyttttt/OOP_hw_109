#include <iostream>

int main()
{
	unsigned long long int n = 0, h = 0, m = 0, s = 0;
	while (std::cin >> n) //允許重複輸入n
	{
		s = n % 60; //取得秒
		n /= 60;
		m = n % 60; //取得分
		n /= 60;
		h = n; // 取得小時
		std::cout << h << " hours " << m << " minutes and " << s << " seconds" << std::endl;
	}
	
}