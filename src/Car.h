#pragma once
#include "../includes/include.h"
struct Cars
{
	str Name;
	str Country;
	str Story;
	str Power;
	str Prise;
};
class Car
{
public:
	Car() = default;
	~Car();
	Car(str path);
	void DeleteCar();
	void AddCar();
	void Update();
	std::pair<int, Cars> Initialization(int&x,str line);
	void ShowCar();
	void UpdateKeys();
	int DeleteMenu();
private:
	std::ofstream in;
	std::ifstream out;
	std::map<int, Cars> l;
	std::vector<int> keys;
	const str path = "List.txt";
	friend bool Check(Car& t, int& x);
};
int Menu();
bool Check(Car& t, int& x);

