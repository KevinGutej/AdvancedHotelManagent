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
	if(roomSize == 1)
	{
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
	}
		
	
	else if(roomSize == 2)
	{
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
	}
	
	else if(roomSize == 3)
	{
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
	else
	{
		cout << "Room size is not available" << endl;
	}
	
}

bool checkIfRoomNumberIsAvailable(int roomNumber, RoomList listOfRooms)
{
	int i;
	for(i=0; i < 10; i++)
	{
		if(listOfRooms.singleRooms[i].roomNumber == roomNumber)
		{
			if(listOfRooms.singleRooms[i].clients[0].firstName == "")
			{
				return true;	
			}
			else
			{
				cout << "This room is not available, enter again" << endl;
				return false;
			}
		}		
	}
	
	for(i=0; i < 6; i++)
	{
		if(listOfRooms.doubleRooms[i].roomNumber == roomNumber)
		{
			if(listOfRooms.doubleRooms[i].clients[0].firstName == "")
			{
				return true;	
			}
			else
			{
				cout << "This room is not available, enter again" << endl;
				return false;
			}
		}
	}
	
	for(i=0; i < 3;  i++)
	{
		if(listOfRooms.tripleRooms[i].roomNumber == roomNumber)
		{
			if(listOfRooms.tripleRooms[i].clients[0].firstName == "")
			{
				return true;	
			}
			else
			{
				cout << "This room is not available, enter again" << endl;
				return false;
			}
		}
	}
	cout << "This room does not exist, enter again" << endl;
	return false;
}


void roomBookingMenu(RoomList listOfRooms)
{
	int roomSize;
	int roomNumber;
	do
	{
		cout << "What room size would you like(1,2,3): " << endl;
		cin >> roomSize;
		printAvaiableRooms(roomSize,listOfRooms);
	}while(roomSize > 3 || roomSize < 0);
	
	do
	{
		cout << "Which room number would you like?: ";
		cin >> roomNumber;
	}
	while(checkIfRoomNumberIsAvailable(roomNumber, listOfRooms) == false);
	
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
	
	
	
	//Client firstClient = getClientDetail();
	//display(firstClient);
	
	roomBookingMenu(listOfRooms);
	
	return 0;
}
