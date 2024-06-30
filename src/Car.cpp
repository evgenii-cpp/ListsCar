#include "Car.h"

str track = " ------------------- ";
bool Check(Car& t,int& x)
{
	for (int num = 0; num <= t.keys.size();num++)
	{
		if (x == t.keys[num]) return true;
	}
	return false;
}
void Car::Update()
{
	in.open(path);
	for (auto i : l)
	{
		str line = i.second.Name + "*" + i.second.Country + "*" + i.second.Story + "*" + i.second.Power + "*" + i.second.Prise;
		in << line;
		in << "\n";
	}
	in.close();
}
void Car::DeleteCar()
{
	int del = DeleteMenu();
	//if (l.size() == 1) l.clear();
	l.erase(del);
	UpdateKeys();
}
Car::Car(str Path)
{
	try {
		out.open(path);
	}
	catch(const std::exception & ex){
		std::cout << "Error!!!" << std::endl;
	}
	str line;
	int i = 0;
	while (std::getline(out, line))
	{
		if(!line.empty()) l.insert(Initialization(i,line));
		line = "";
	}
	out.close();
}
Car::~Car()
{
	Update();
	std::cout << "Close Programm!!!" << std::endl;
}
void Car::ShowCar()
{
	if (l.empty())
	{
		std::cout << "List Clear!" << std::endl;
	}
	else {
		for (auto i : l)
		{
			std::cout << track << i.first  <<track<< std::endl;
			std::cout << "Name: " << i.second.Name << std::endl;
			std::cout << "Country: " << i.second.Country << std::endl;
			std::cout << "Story: " << i.second.Story << std::endl;
			std::cout << "Power: " << i.second.Power << std::endl;
			std::cout << "Prise: " << i.second.Prise << std::endl;
			std::cout << std::endl;
		}
	}
}
std::pair<int,Cars> Car::Initialization(int& x,str line)
{
	Cars t;
	t.Name = line.substr(0, line.find_first_not_of('*'));
	line.erase(0, line.find_first_of('*') + 1);
	t.Country = line.substr(0, line.find_first_not_of('*'));
	line.erase(0, line.find_first_of('*') + 1);
	t.Story = line.substr(0, line.find_first_not_of('*'));
	line.erase(0, line.find_first_of('*') + 1);
	t.Power = line.substr(0, line.find_first_not_of('*'));
	line.erase(0, line.find_first_of('*') + 1);
	t.Prise = line.substr(0, line.find_first_not_of('*'));
	x++;
	return { x,t };
}
int Menu()
{
	int x;
	std::cout << "Press 1 to add a car." << std::endl;
	std::cout << "Press 2 to show all cars." << std::endl;
	std::cout << "Press 3 to remove the car." << std::endl;
	std::cout << "Press 0 to close the program!\n\n" << std::endl;
	std::cin >> x;
	return x;
}
int Car::DeleteMenu()
{
	int x;
	Car::ShowCar();
	while (true)
	{
		std::cout << "Enter car number: "; std::cin >> x;
		if (Check(*this,x))//
		{
			break;
		}
		else {
			std::cout << "There is no car with this number!!!" << std::endl;
		}
	}
	return x;
}
void Car::AddCar()
{
	Cars f;
	std::cin.ignore();
	std::cout << "Name: "; std::getline(std::cin, f.Name);
	std::cout << "Country: "; std::getline(std::cin, f.Country);
	std::cout << "Story: "; std::getline(std::cin, f.Story);
	std::cout << "Power: "; std::getline(std::cin, f.Power);
	std::cout << "Prise: "; std::getline(std::cin, f.Prise);
	l.insert({ l.size() + 1,f });
	UpdateKeys();
}
void Car::UpdateKeys()
{
	for (auto i : l)
	{
		keys.push_back(i.first);
	}
}
