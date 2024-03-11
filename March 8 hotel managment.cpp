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
	string currentLocation = "hotel";
	bool hasMembership = false;
	int numberOfFreeRides = 0;
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

static const int numberOfSingleRooms = 1;
static const int numberOfDoubleRooms = 1;
static const int numberOfTripleRooms = 1;

struct RoomList
{
	SingleRoom singleRooms[numberOfSingleRooms];
	DoubleRoom doubleRooms[numberOfDoubleRooms];
	TripleRoom tripleRooms[numberOfTripleRooms];
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
	if(firstClient.age < 18) {
        cout << "You have to be at least 18 to book a room" << endl;
        exit(0);
	}

    bool isEmailValid = false;
	do{
        cout << "Please enter email: ";
        cin >> firstClient.email;
        for(int i = 0; i < firstClient.email.size(); i++) {
            if(firstClient.email[i] == '@') {
                isEmailValid = true;
                break;
            }
        }
        if(isEmailValid == false) {
            cout << "Email is invalid" << endl;
        }
	}while(isEmailValid == false);


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
		for(i=0; i < 1; i++)
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
		for(i=0; i < 1; i++)
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
		for(i=0; i < 1; i++)
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


void roomBookingMenu(RoomList & listOfRooms, Client *clientPtr)
{
	int roomSize;
	int roomNumber;
	int i,j;
	int pin = -1;
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

    for(j=0; j < 1; j++)
    {
        if(listOfRooms.singleRooms[j].roomNumber == roomNumber)
        {
            //listOfRooms.singleRooms[j].clients[i] = clientDetail;
            pin = listOfRooms.singleRooms[j].pin;
            pay(clientPtr, "Single Room", listOfRooms.singleRooms[j].price);
        }
    }

    for(j=0; j < 1; j++)
    {
        if(listOfRooms.doubleRooms[j].roomNumber == roomNumber)
        {
            //listOfRooms.doubleRooms[j].clients[i] = clientDetail;
            pin = listOfRooms.doubleRooms[j].pin;
            pay(clientPtr, "Double Room", listOfRooms.doubleRooms[j].price);
        }
    }


    for(j=0; j < 1; j++)
    {
        if(listOfRooms.tripleRooms[j].roomNumber == roomNumber)
        {
            //listOfRooms.tripleRooms[j].clients[i] = clientDetail;
            pin = listOfRooms.tripleRooms[j].pin;
            pay(clientPtr, "Triple Room", listOfRooms.tripleRooms[j].price);
        }
    }

	cout << "Use this pin to enter your room: " << pin << endl;
}

void generateRooms(RoomList & listOfRooms) {



    listOfRooms.singleRooms.price = rand() % (75-50 + 1) + 50;
    listOfRooms.singleRooms.pin = rand() % (9999-1000 + 1) + 1000;
    listOfRooms.singleRooms.roomNumber =
}

void orderDrink(Client* clientPtr)
{
	string drinkChoice;
	string drinkName = "";
	float drinkPrice = 0.0;
	int ignoreCounter = 0;

	do{
		cout << "Drink options: (Coca Cola, Fanta, Sprite, Water, Coffee, Slushy)" << endl;
		cout << "Please enter drink choice: " << endl;
		if(ignoreCounter == 0) {
			cin.ignore(1,'\n');
		}
		getline(cin, drinkChoice);

		if(drinkChoice == "Coca Cola")
		{
			drinkName = "Coca Cola";
			drinkPrice = 5;
		}
		else if(drinkChoice == "Fanta")
		{
			drinkName = "Fanta";
			drinkPrice = 4;
		}
		else if(drinkChoice == "Sprite")
		{
			drinkName = "Sprite";
			drinkPrice = 3.50;
		}
		else if(drinkChoice == "Water")
		{
			drinkName = "Water";
			drinkPrice = 2;
		}
		else if(drinkChoice == "Coffee")
		{
			drinkName = "Coffee";
			drinkPrice = 3;
		}
		else if(drinkChoice == "Slushy")
		{
			drinkName = "Slushy";
			drinkPrice = 6;
		}
		else{
			drinkChoice = "Incorrect";
		}
		if((*clientPtr).hasMembership == true) {
			drinkPrice = drinkPrice * 0.75;
		}
		cout << "You have purchased " << drinkName;
		pay(clientPtr, drinkName, drinkPrice);

	}while(drinkChoice == "Incorrect");
}

void informAboutOrder(string orderName)
{
	cout << "You have ordered: " << orderName << endl;
}

void orderDessert(Client* clientPtr)
{
	int dessertOption = 0;
	float price = 0.0f;
	string orderName;
	int pancakes = 0;

	cout << "Dessert options: Ice-cream (1), HotChocolate(2), Flapjack(3), Pankaces(4)" << endl;
	cout << "Please enter dessert option using a number: ";
	cin >> dessertOption;

	switch(dessertOption) {
		case 1:
			orderName = "Ice-Cream, $3.25";
			price = 3.25;
			break;
		case 2:
			orderName = "Hot Chocolate, $2.99";
			price = 2.99;
			break;
		case 3:
			orderName = "Flapjack, $3.56";
			price = 3.56;
			break;
		case 4:
			price = 5.50;
			cout << "How many pancakes would you like: " << endl;
			cout << "1 pancake, $5.50" << endl;
			cin >> pancakes;
			if(pancakes >= 1) {
				orderName = priceToString(pancakes) + " Pancakes";
				price = pancakes * price;
			}else {
				cout << "Please enter a positive number." << endl;
				return;
			}
			break;
		default:
			cout << "Option entered is not available" << endl;
			return;
	}
	if((*clientPtr).hasMembership == true) {
			price = price * 0.75;
		}
		cout << "You have purchased " << orderName << endl;
		pay(clientPtr, orderName, price);
}

void restaurantMenu(Client* clientPtr)
{
	int restaurantOption;
	bool isMainCourseOrdered = false;
	bool isDrinkOrdered = false;
	bool isDessertOrdered = false;

	do{
		cout << "Please choose what you would like to order from the menu: " << endl;

	    if(isMainCourseOrdered == false)
	    {
	    	cout << "[1] - Pizza" << endl;
		    cout << "[2] - Burger" << endl;
		    cout << "[3] - Fries" << endl;
		}

	    if(isDrinkOrdered == false)
	    {
	    	cout << "[4] - Drink " << endl;
		}

	    if(isDessertOrdered == false)
	    {
	    	cout << "[5] - Dessert " << endl;
		}

	    cout << "[6] - Leave restaurant" << endl;
	    cin >> restaurantOption;
		float price = 0.0;
		string foodName = "";

		switch(restaurantOption)
		{
			case 1:
				price = 20.0;
				foodName = "Pizza";
				break;

			case 2:
				price = 15.0;
				foodName = "Burger";
				break;

			case 3:
				price = 5.0;
				foodName = "Fries";
				break;

			case 4:
				orderDrink(clientPtr);
				break;

			case 5:
				orderDessert(clientPtr);
				break;

			case 6:
				cout << "Goodbye" << endl;
				break;
		}
		if(foodName != "") {
			if((*clientPtr).hasMembership == true) {
				price = price * 0.75;
			}
			cout << "You have purchased " << foodName;
			pay(clientPtr, foodName, price);
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
    return true;
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
	    			pay(clientPtr, "Swimming Pool", 25);
	    			cout << "You have entered Swimming Pool" << endl;
				}
	    		break;

	    	case 2:
	    		if((*clientPtr).hasMembership == false) {
	    			cout << "You need to have VIP membership to enter" << endl;
				}else {
					agreement = askAboutAgreement(12, "Sauna");
					if(agreement == true)
	    			{
		    			pay(clientPtr, "Sauna", 12);
		    			cout << "You have entered Sauna" << endl;
					}
				}
	    		break;

			case 3:
				if((*clientPtr).hasMembership == false) {
					cout << "You need to have VIP membership to enter" << endl;
				}else {
					agreement = askAboutAgreement(8, "Jacuzzi");
					if(agreement == true)
	    			{
		    			pay(clientPtr, "Jacuzzi", 8);
		    			cout << "You have entered Jacuzzi Pool" << endl;
					}
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
	int taxiOption = 1;
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


	do {

		cout << "Please choose a option from the menu: " << endl;
	    cout << "[1] - Order a taxi(to)" << endl;
	    cout << "[2] - Order a taxi(from)" << endl;
	    cout << "[3] - Leave taxi menu" << endl;
	    cin >> taxiOption;
		bool isLocationChosen = false;
		char confirmationOption = 'n';
		char freeRideConfirmation = 'n';

	    switch(taxiOption)
    	{
	    	case 1:
	    		if(clientPtr->currentLocation == "hotel") {
	    			for(i=0; i < size; i++)
					{
						cout << destinations[i].location << " ";
						cout << pricePerKm * destinations[i].distanceFromHotel<< "$" << endl;
					}
	    			cout << "Where would you like to order a taxi: ";
	    			cin >> taxiOrderTo;
	    			for(i=0; i < size; i++) {
	    				if(taxiOrderTo == destinations[i].location) {
	    					isLocationChosen = true;
	    					string title = taxiOrderTo;
			    		    float price = pricePerKm * destinations[i].distanceFromHotel;
			    			pay(clientPtr, title, price);
			    			clientPtr->currentLocation = taxiOrderTo;
						}
					}
	    			if(isLocationChosen == false) {
						cout << "Location dosen't exist" << endl;
					}
				}
	    	break;

	    	case 2:
	    		if(clientPtr->currentLocation == "hotel") {
	    			cout << "You are currently in hotel" << endl;
				}else {
					for(i=0; i < size; i++)
					{
						float price = 0.0;
						if(destinations[i].location == clientPtr->currentLocation) {
							if((*clientPtr).numberOfFreeRides > 0) {
								cout << "You have VIP membership, so you have " << (*clientPtr).numberOfFreeRides << "free rides" << endl;
								cout << "Are you sure you wanna use your free ride (y,n)" << endl;
								cin >> freeRideConfirmation;
								if(freeRideConfirmation == 'y') {
									(*clientPtr).numberOfFreeRides -= 1;
									(*clientPtr).currentLocation = "hotel";
								}
							}else{
								cout << "To return to hotel, you need to pay: " << pricePerKm * destinations[i].distanceFromHotel<< "$" << endl;
								cout << "Are you sure you want to pay (y/n)" << endl;
								cin >> confirmationOption;
								if(confirmationOption == 'y') {
									string title = "Return to Hotel";
									float price = pricePerKm * destinations[i].distanceFromHotel;
					    			pay(clientPtr, title, price);
					    			clientPtr->currentLocation = "hotel";
								}else {
									cout << "Payment cancelled" << endl;
								}
							}

						}

					}

				}
	    	break;
	    	case 3:
                return;
	    		break;
		}
	}while(taxiOption < 1 || taxiOption >= 3);
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
		    cout << "Goodbye " << (*clientPtr).firstName << " " << (*clientPtr).lastName << endl;
			cout << "Your receipt: " << (*clientPtr).receipt << endl;
			cout << "Your total is: " << (*clientPtr).dept << "$" << endl;
			exit(0);
		}else if(checkOutOption == 2){
			cout << "Your balance is : " << "-" << (*clientPtr).dept << "$" << endl;
		}
	}while(checkOutOption != 3);


}

void vipMenu(Client* clientPtr) {
	cout << "VIP membership includes:" << endl;
	cout << "25% discount on food and drinks" << endl;
	cout << "Exclusive access to the jacuzzi and sauna" << endl;
	cout << "1 Free ride back to the hotel" << endl;

	if((*clientPtr).hasMembership == true) {
		cout << endl;
		cout << "You already have a VIP membership" << endl;
		cout << endl;
		return;
	}

	float membershipPrice = 50.0;
	cout << "Would you like to buy VIP membership for " << membershipPrice << " $(y,n)" << endl;
	char membershipChoice = 'n';
	cin >> membershipChoice;
	if(membershipChoice == 'y') {
		cout << endl;
		cout << "Congratulation you have successfully purchased the membership" << endl;
		pay(clientPtr, "VIP Membership", membershipPrice);
		(*clientPtr).hasMembership = true;
		(*clientPtr).numberOfFreeRides = 1;
	}else{
		cout << "Cancelled payment" << endl;
	}
}

void chooseActivity(Client* clientPtr)
{
	int activityOption;



	do{
		cout << endl;
		system("pause");
		system("cls");
		cout << "Please choose a activity " << endl;
		cout << "[1] - Order food" << endl;
		cout << "[2] - Go to water park" << endl;
		cout << "[3] - Buy a VIP membership" << endl;
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
			vipMenu(clientPtr);
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
	srand(time(NULL));

	RoomList listOfRooms;

	listOfRooms.singleRooms[0].pin = 4336;
	listOfRooms.singleRooms[0].price = 50.0;
	listOfRooms.singleRooms[0].roomNumber = 1;

    listOfRooms.doubleRooms[0].pin = 8432;
    listOfRooms.doubleRooms[0].price = 100.0;
	listOfRooms.doubleRooms[0].roomNumber = 2;

	listOfRooms.tripleRooms[0].pin = 6423;
    listOfRooms.tripleRooms[0].price = 175.0;
	listOfRooms.tripleRooms[0].roomNumber = 3;

	//listOfRooms.doubleRooms[0] = firstDoubleRoom;
	//listOfRooms.tripleRooms[0] = firstTripleRoom;


	Client client = getClientDetail();
	Client* clientPtr2;
	clientPtr2 = &client;
	roomBookingMenu(listOfRooms, clientPtr2);
	chooseActivity(clientPtr2);
	cout << "Your dept: " << (*clientPtr2).dept << endl;

	return 0;
}
