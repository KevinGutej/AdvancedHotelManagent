#include <iostream>

using namespace std;

struct Client
{
	string firstName = "";
	string lastName = "";
	unsigned short int age = 0;
	float dept = 0.0;
	string email = "";
};

struct GroupOfClients
{
	int numberOfClients = 0;
	Client clients[10];
};

Client getClientDetail()
{
	Client firstClient;
	
	cout << "Please enter first name: ";
	cin >> firstClient.firstName;
	cout << "Please enter last name: ";
	cin >> firstClient.lastName;
	cout << "Please enter your age: ";
	cin >> firstClient.age;
	cout << "Please enter email: ";
	cin >> firstClient.email;
	
	return firstClient;	
}

int main()
{
  getClientDetail();
  return 0;
}
