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

struct SingleRoom
{
	short int roomNumber = 1;
	int pin = 0;
	static const int roomSize = 1;
	Client clients[roomSize];
	float price = 50.0; 
};

struct DoubleRoom
{
	short int roomNumber = 1;
	int pin = 0;
	static const int roomSize = 2;
	Client clients[roomSize];
	float price = 100.0; 
};

struct TripleRoom
{
	short int roomNumber = 1;
	int pin = 0;
	static const int roomSize = 3;
	Client clients[roomSize];
	float price = 150.0; 
};

struct GroupOfClients
{
	int numberOfClients = 0;
	Client clients[10];
};

struct RoomList
{
	SingleRoom singleRooms[10];
	DoubleRoom doubleRooms[6];
	TripleRoom tripleRooms[3];
	
};

void display(Client c){
    cout << "first name:" <<c.firstName << " last name:" <<c.lastName << " age:" <<c.age << " dept:" <<c.dept << " email: "<<c.email << endl;
}

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



void printAvaiableRooms(int roomSize, RoomList listOfRooms)
{
	int i;
	for(i=0; i < 10; i++)
	{
		cout << "Room Number: " << listOfRooms.singleRooms[i].roomNumber << endl;
		cout << "Price: " << listOfRooms.singleRooms[i].price << endl;
		cout << "Room Size: " << listOfRooms.singleRooms[i].roomSize << endl;
		if(listOfRooms.singleRooms[i].clients[0].firstName != "")
		{
			cout << "Room is Occupied" << endl;
		}
		else {
			cout << "Room is Available" << endl;
		}
		cout << "---------------------- " << endl;
	}
	
	for(i=0; i < 6; i++)
	{
		cout << "Room Number: " << listOfRooms.doubleRooms[i].roomNumber << endl;
		cout << "Price: " << listOfRooms.doubleRooms[i].price << endl;
		cout << "Room Size: " << listOfRooms.doubleRooms[i].roomSize << endl;
		if(listOfRooms.doubleRooms[i].clients[0].firstName != "")
		{
			cout << "Room is Occupied" << endl;
		}
		else {
			cout << "Room is Available" << endl;
		}
		cout << "---------------------- " << endl;
	}
	
	for(i=0; i < 3; i++)
	{
		cout << "Room Number: " << listOfRooms.tripleRooms[i].roomNumber << endl;
		cout << "Price: " << listOfRooms.tripleRooms[i].price << endl;
		cout << "Room Size: " << listOfRooms.tripleRooms[i].roomSize << endl;
		if(listOfRooms.tripleRooms[i].clients[0].firstName != "")
		{
			cout << "Room is Occupied " << endl;
		}
		else {
			cout << "Room is Available" << endl;
		}
		cout << "---------------------- " << endl;
	}
}

void roomBookingMenu(RoomList listOfRooms)
{
	int roomSize;
	cout << "What room size would you like(1,2,3): " << endl;
	cin >> roomSize;
	printAvaiableRooms(roomSize,listOfRooms);
}

int main()
{
	RoomList listOfRooms;
	SingleRoom firstSingleRoom;
	DoubleRoom firstDoubleRoom;
	TripleRoom firstTripleRoom;
	
	firstSingleRoom.pin = 2345;
	firstDoubleRoom.pin = 4356;
	firstTripleRoom.pin = 8576;
	
	listOfRooms.singleRooms[0] = firstSingleRoom;
	listOfRooms.doubleRooms[0] = firstDoubleRoom;
	listOfRooms.tripleRooms[0] = firstTripleRoom;
	
	
	
	Client firstClient = getClientDetail();
	display(firstClient);
	
	roomBookingMenu(listOfRooms);
	
	return 0;
}
