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


	//construcor
	World()
	{
		//creating locations
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
		
		//setting up exits for each location
		en->setExits(dc, nullptr, nullptr, nullptr);
		dc->setExits(wr, en, gr, kt);
		gr->setExits(ba, nullptr, nullptr, dc);
		ba->setExits(nullptr, gr, nullptr, nullptr);
		wr->setExits(nullptr, dc, nullptr, ld);
		kt->setExits(gh, ib, dc, ld);
		ib->setExits(kt, nullptr, nullptr, nullptr);
		ld->setExits(br, wr, kt, nullptr);
		gh->setExits(br, kt, tr, mr);
		br->setExits(nullptr, ld, gh, nullptr);
		tr->setExits(lb, gh, nullptr, mr);
		lb->setExits(nullptr, tr, nullptr, mr);
		mr->setExits(lb, tr, gh, nullptr);

		//adding location to vector (for looping if needed)
		locations.push_back(en);
		locations.push_back(dc);
		locations.push_back(gr);
		locations.push_back(ba);
		locations.push_back(wr);
		locations.push_back(kt);
		locations.push_back(ib);
		locations.push_back(ld);
		locations.push_back(gh);
		locations.push_back(br);
		locations.push_back(tr);
		locations.push_back(lb);
		locations.push_back(mr);
	}

	//destructor
	~World() {};


};

int main()
{
	World* world = new World();

	Player* player = new Player();
	

	

	return 0;
}
