#include<iostream>
#include<vector>
using namespace std;


//LOCATION CLASS
class Location
{
public:
	string name;
	string desc;
	
	//4 locations representing extits from current one
	Location* north = nullptr;
	Location* south = nullptr;
	Location* west = nullptr;
	Location* east = nullptr;

	void setExits(Location*,Location*,Location*,Location*);
	

	Location(string);
	~Location();
};

//LOCATION FUNCTIONS
Location::Location(string n)
{
	name = n;
}
Location::~Location()
{

}

void Location::setExits(Location* n, Location* s, Location* w, Location* e)
{
	north = n;
	south = s;
	west = w;
	east = e;

}

//PLAYER CLASS
class Player 
{
public:
	Location* currentLoc=nullptr;

	Player();
	~Player();

	void setLocation(Location*);
	Location* getLocation();
};

//PLAYER FUNCTIONS

Player::Player() {}
Player::~Player() {}

void Player::setLocation(Location* c)
{
	currentLoc = c;
}
Location* Player::getLocation()
{
	return currentLoc;
}

class World
{
public:
	vector<Location*> locations; //vector holding locations

	World()
	{
		Location* en = new Location("Entrance");
		Location* dc = new Location("Damp Cavern");
		Location* gr = new Location("Guard Room");
		Location* ba = new Location("Barracks");
		Location* wr = new Location("Well Room");
		Location* kt = new Location("Kitchen");
		Location* ib = new Location("Ice Box");
		Location* ld = new Location("Larder");
		Location* gh = new Location("Great Hall");
		Location* br = new Location("Bottle Room");
		Location* tr = new Location("Trolls Room");
		Location* lb = new Location("Library");
		Location* mr = new Location("Mysterious Room");
		
		

	}


};

