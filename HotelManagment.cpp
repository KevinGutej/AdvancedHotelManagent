#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include <iomanip>

using namespace std;

struct Client
{
	string firstName = "";
	string lastName = "";
	unsigned short int age = 0;
	float dept = 0.0;
	string email = "";
	string receipt = "";
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

string priceToString(float price)
{
    stringstream priceOfStream;
    priceOfStream << fixed << setprecision(2) << price << " $";
    string stringedPrice = priceOfStream.str();
    return stringedPrice;

}

void pay(Client* clientPtr, string title, float price) {

    (*clientPtr).dept += price;
    (*clientPtr).receipt += title + " " + priceToString(price) + "\n";
}

void printAvaiableRooms(int roomSize, RoomList listOfRooms)
{
	int i;
	if(roomSize == 1)
	{
		for(i=0; i < 10; i++)
		{
			cout << "Room Number: " << listOfRooms.singleRooms[i].roomNumber << endl;
			cout << "Price: " << listOfRooms.singleRooms[i].price << "$" << endl;
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
			cout << "Price: " << listOfRooms.doubleRooms[i].price << "$" << endl;
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
			cout << "Price: " << listOfRooms.tripleRooms[i].price << "$" << endl;
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
	int i,j;
	int pin;
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

	for(i=0; i < roomSize; i++)
	{
		Client clientDetail = getClientDetail();
		for(j=0; j < 10; j++)
		{
			if(listOfRooms.singleRooms[j].roomNumber == roomNumber)
			{
				listOfRooms.singleRooms[j].clients[i] = clientDetail;
				pin = listOfRooms.singleRooms[j].pin;
			}
		}

		for(j=0; j < 6; j++)
		{
			if(listOfRooms.doubleRooms[j].roomNumber == roomNumber)
			{
				listOfRooms.doubleRooms[j].clients[i] = clientDetail;
				pin = listOfRooms.doubleRooms[j].pin;
			}
		}


		for(j=0; j < 3; j++)
		{
			if(listOfRooms.tripleRooms[j].roomNumber == roomNumber)
			{
				listOfRooms.tripleRooms[j].clients[i] = clientDetail;
				pin = listOfRooms.tripleRooms[j].pin;
			}
		}
	}
	cout << "Use this pin to enter your room: " << pin << endl;
}

void orderDrink(Client* clientPtr)
{
	string drinkChoice;

	do{
		cout << "Drink options: (CocaCola, Fanta, Sprite, Water, Coffee, Slushy)" << endl;
		cout << "Please enter drink choice: " << endl;
		cin >> drinkChoice;

		if(drinkChoice == "CocaCola")
		{
			cout << "You have chosen CocaCola" << endl;
			(*clientPtr).dept += 3;
		}
		else if(drinkChoice == "Fanta")
		{
			cout << "You have chosen Fanta" << endl;
			(*clientPtr).dept += 3;
		}
		else if(drinkChoice == "Sprite")
		{
			cout << "You have chosen Sprite" << endl;
			(*clientPtr).dept += 3;
		}
		else if(drinkChoice == "Water")
		{
			cout << "You have chosen Water" << endl;
			(*clientPtr).dept += 2;
		}
		else if(drinkChoice == "Coffee")
		{
			cout << "You have chosen Coffee" << endl;
			(*clientPtr).dept += 4;
		}
		else if(drinkChoice == "Slushy")
		{
			cout << "You have chosen Slushy" << endl;
			(*clientPtr).dept += 4;
		}
		else{
			drinkChoice = "Incorrect";
		}

	}while(drinkChoice == "Incorrect");
}

void orderDessert()
{

}

void restaurantMenu(Client* clientPtr)
{
	int restaurantOption;
	bool isMainCourseOrdered = false;
	bool isDrinkOrdered = false;
	bool isDessertOrdered = false;

	do{
		cout << "Please choose what you would like to order from the menu: " << endl;
	    cout << "Drink options: (Coca-Cola, Fanta, Sprite, Water, Coffee, Slushy)" << endl;
	    cout << "Dessert options: (Ice-cream, FrozenHotChocolate, Flapjack, Pankaces)" << endl;

	    if(isMainCourseOrdered == false)
	    {
	    	cout << "[1] - Pizza" << endl;
		    cout << "[2] - Buger" << endl;
		    cout << "[3] - Fries" << endl;
		}

	    if(isDrinkOrdered == false)
	    {
	    	cout << "[4] - Drink: " << endl;
		}

	    if(isDessertOrdered == false)
	    {
	    	cout << "[5] - Dessert: " << endl;
		}

	    cout << "[6] - Leave restaurant" << endl;
	    cin >> restaurantOption;


		switch(restaurantOption)
		{
			case 1:
				cout << "You have ordered pizza" << endl;
				(*clientPtr).dept += 20;
				break;

			case 2:
				cout << "You have ordered burger" << endl;
				(*clientPtr).dept += 12;
				break;

			case 3:
				cout << "You have ordered fries" << endl;
				(*clientPtr).dept += 5;
				break;

			case 4:
				orderDrink(clientPtr);
				break;

			case 5:
				orderDessert();
				break;

			case 6:
				cout << "Goodbye" << endl;
				break;
		}

	}while(restaurantOption > 6 || restaurantOption < 1);



}

bool askAboutAgreement(float price, string activityName)
{
	string response;
	do
	{
		cout << "Do you agree to do " <<  activityName << " for " << price << "$" << " ?" << " yes/no" << endl;
		cin >> response;
		if(response == "yes")
		{
			return true;
		}
		else if(response == "no")
		{
			return false;
		}
		else
		{
			cout << "Please enter again: " << " yes/no" << endl;

		}
	}while(response != "yes" && response != "no");

}

void waterParkMenu(Client* clientPtr)
{
	int waterParkChoice;
	bool agreement = false;
	do
	{
		cout << "Please choose a option from the menu: " << endl;
	    cout << "[1] - Pool Prices" << endl;
	    cout << "[2] - Sauna Prices" << endl;
	    cout << "[3] - Jacuzzi Prices" << endl;
	    cout << "[4] - Leave Water park" << endl;
	    cin >> waterParkChoice;

	    switch(waterParkChoice)
	    {
	    	case 1:
	    		agreement = askAboutAgreement(25, "Pool");
	    		if(agreement == true)
	    		{
	    			(*clientPtr).dept += 25;
	    			(*clientPtr).receipt += "Pool: " + priceToString(25) + "\n";
	    			cout << "You have entered Swimming Pool" << endl;
				}
	    		break;

	    	case 2:
	    		agreement = askAboutAgreement(12, "Sauna");
	    		if(agreement == true)
	    		{
	    			(*clientPtr).dept += 12;
	    			(*clientPtr).receipt += "Sauna: " + priceToString(12) + "\n";
	    			cout << "You have entered Sauna" << endl;
				}
	    		break;

			case 3:
				agreement = askAboutAgreement(8, "Jacuzzi");
				if(agreement == true)
	    		{
	    			(*clientPtr).dept += 8;
	    			cout << "You have entered Jacuzzi Pool" << endl;
				}
	    		break;

	    	case 4:
	    		cout << "Goodbye" << endl;
	    		break;

	    	default:
	    		cout << "Option is not a choice, enter again" << endl;
	    		break;

		}
	}while(waterParkChoice < 1 || waterParkChoice > 4);

}

struct Destination
{
	string location = "";
	int distanceFromHotel = 0;
};

void taxiMenu(Client* clientPtr)
{
	int taxiOption;
	string taxiOrderTo;
	int i;
	float pricePerKm = ((rand() % 4) + 7) / 2.0;
	const int size = 4;

	Destination destinations[size];
	destinations[0].location = "cinema";
	destinations[0].distanceFromHotel = 5;
	destinations[1].location = "oldtown";
	destinations[1].distanceFromHotel = 10;
	destinations[2].location = "supermarket";
	destinations[2].distanceFromHotel = 3;
	destinations[3].location = "concert";
	destinations[3].distanceFromHotel = 7;

    cout << "Please choose a option from the menu: " << endl;
    cout << "[1] - Order a taxi(to)" << endl;
    cout << "[2] - Order a taxi(from)" << endl;
    cout << "[3] - Taxi Prices" << endl;
    cout << "[4] - Exclusive taxi" << endl;
    cout << "[5] - Leave taxi menu" << endl;
    cin >> taxiOption;

    switch(taxiOption)
    {
    	case 1:
    		for(i=0; i < size; i++)
			{
				cout << destinations[i].location << " ";
				cout << pricePerKm * destinations[i].distanceFromHotel<< "$" << endl;
			}
    		cout << "Where would you like to order a taxi: ";
    		cin >> taxiOrderTo;
    		if(taxiOrderTo == "cinema")
    		{
    		    string title = "cinema";
    		    float price = pricePerKm * destinations[0].distanceFromHotel;
    			pay(clientPtr, title, price);
			}


    	break;

    	case 2:
    	break;

    	case 3:
    	break;

    	case 4:
    	break;

    	case 5:
    	break;
	}

}

void checkOut(Client* clientPtr)
{
	int checkOutOption;
    do {
    	cout << "Please choose an option from below: " << endl;
    	cout << "[1] - Pay and exit" << endl;
	    cout << "[2] - My balance" << endl;
	    cout << "[3] - Back to main" << endl;
	    cin >> checkOutOption;
	    if(checkOutOption < 1 || checkOutOption > 3)
	    {
	    	cout << checkOutOption << " was not a option from above, Enter again: " << endl;
		}else if(checkOutOption == 1){
			cout << "Your receipt: " << (*clientPtr).receipt << endl;
			cout << "Your total is: " << (*clientPtr).dept << "$" << endl;
			cout << "Goodbye " << (*clientPtr).firstName << endl;
			exit(0);
		}else if(checkOutOption == 2){
			cout << "Your balance is : " << "-" << (*clientPtr).dept << "$" << endl;
		}
	}while(checkOutOption != 3);


}

void chooseActivity(Client* clientPtr)
{
	int activityOption;



	do{
		cout << "Please choose a activity " << endl;
		cout << "[1] - Order food" << endl;
		cout << "[2] - Go to water park" << endl;
		cout << "[3] - Book a VIP area" << endl;
		cout << "[4] - Book a transport" << endl;
		cout << "[5] - Check out" << endl;

		cin >> activityOption;

		switch(activityOption)
		{
			case 1:
			restaurantMenu(clientPtr);
			break;

			case 2:
			waterParkMenu(clientPtr);
			break;

			case 3:
			break;

			case 4:
			taxiMenu(clientPtr);
			break;

			case 5:
			checkOut(clientPtr);
			break;

			default:
			cout << "Incorrect activity" << endl;
		}

	}while(true);


}

int main()
{
	//ENTER SOMETHING IN RECIEPT (IN CLIENT WHILE BUYING SOMETHING)!!!!!!!!!!!
	srand(time(NULL));

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

	//roomBookingMenu(listOfRooms);
	Client* clientPtr2;
	Client fakeClient;
	clientPtr2 = &fakeClient;
	chooseActivity(clientPtr2);
	cout << "Your dept: " << (*clientPtr2).dept << endl;

	return 0;
}
