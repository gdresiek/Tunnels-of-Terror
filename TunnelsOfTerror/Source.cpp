#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
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
	int costN = NULL;
	int costS = NULL;
	int costW = NULL;
	int costE = NULL;


	void setExits(Location*,Location*,Location*,Location*,int, int, int, int);
	void getDesc();

	Location(string,string);
	~Location();
};

//LOCATION FUNCTIONS
Location::Location(string n,string d)
{
	name = n;
	desc = d;
}
Location::~Location()
{

}
void Location::getDesc()
{
	cout << desc << endl;
}
void Location::setExits(Location* n, Location* s, Location* w, Location* e, int costNorth, int costSouth, int costWest, int costEast)
{
	north = n;
	south = s;
	west = w;
	east = e;

	costN = costNorth;
	costS = costSouth;
	costW = costWest;
	costE = costEast;

}

//PLAYER CLASS
class Player 
{
public:
	Location* currentLoc=nullptr;
	int energy = 100;

	Player();
	~Player();

	void setLocation(Location*);
	Location* getLocation();
	void travel();
	void getEnergy();
	int retEnergy();
};

//PLAYER FUNCTIONS

Player::Player() {}
Player::~Player() {}

int Player::retEnergy()
{
	return energy;
}
void Player::getEnergy()
{
	cout << "Energy left: " << energy << endl;
}
void Player::setLocation(Location* c)
{
	currentLoc = c;
}
Location* Player::getLocation()
{
	return currentLoc;
}

void Player::travel()
{
	int direction = 0;  // 1-north 2-south 3-west 4-east 	
	bool north = false;
	bool south = false;
	bool west = false;
	bool east = false;
	if (currentLoc->north != nullptr)
		north = true;
	if (currentLoc->south != nullptr)
		south = true;
	if (currentLoc->west != nullptr)
		west = true;
	if (currentLoc->east != nullptr)
		east = true;
	cout << "Where do you want to travel? ";

	while (direction < 1 || direction>4)
	{
		cin >> direction;
		if (direction == -999)
			exit(1);
	}

	if (direction == 1 && north == true)
	{
		energy -= currentLoc->costN;
		setLocation(currentLoc->north);

	}
	else if (direction == 1 && north == false)
	{
		cout << "You cannot travel north! Choose another direction." << endl;
		currentLoc->getDesc();
		travel();
	}
	if (direction == 2 && south == true)
	{
		energy -= currentLoc->costS;
		setLocation(currentLoc->south);
	}
	else if (direction == 2 && south == false)
	{
		cout << "You cannot travel south! Choose another direction." << endl;
		currentLoc->getDesc();
		travel();
	}
	if (direction == 3 && west == true)
	{
		energy -= currentLoc->costW;
		setLocation(currentLoc->west);
	}
	else if (direction == 3 && west == false)
	{
		cout << "You cannot travel west! Choose another direction." << endl;
		currentLoc->getDesc();
		travel();
	}
	if (direction == 4 && east == true)
	{
		energy -= currentLoc->costE;
		setLocation(currentLoc->east);
	}
	else if (direction == 4 && east == false)
	{
		cout << "You cannot travel east! Choose another direction." << endl;
		currentLoc->getDesc();
		travel();
	}
}


class World
{
public:
	vector<Location*> locations; //vector holding locations


	//construcor
	World()
	{
		//creating locations
		Location* en = new Location("Entrance","You arrive at the Entrance. You can go north(1) to Damp Cavern.");
		Location* dc = new Location("Damp Cavern","You find yourself in the Damp Cavern, you can travel north to (1)Well Room, south to (2)Entrance, west to (3)Guard Room and east to the (4)Kitchen.");
		Location* gr = new Location("Guard Room", "You are in Guard Room, you can travel north to (1)Barracks and east to the (4)Damp Cavern.");
		Location* ba = new Location("Barracks", "You see many beds and weapons rakcks by the walls. You must be in Barracks, you travel south to (2)Guard Room.");
		Location* wr = new Location("Well Room","You are in the Well Room, you can go south to (2)Damp Cavern or east to  the (4)Larder.");
		Location* kt = new Location("Kitchen","You are in the Kitchen. You can travel in every direction. (1)Great Hall, (2)Ice Box, (3)Damp Cavern, (4)Larder.");
		Location* ib = new Location("Ice Box","You feel cold. You see ice. Ice Box. Cold. Go north to (1)Kitchen.");
		Location* ld = new Location("Larder","You are in the Larder, you can go north to (1)Bottle Room, south to (2)Well Room or west to (3)Kitchen.");
		Location* gh = new Location("Great Hall","You are in the Great Hall. It looks trully impressive. You can travel north to (1)Bottle Room, south to (2)Kitchen, west to (3)Trolls Room or east to (4)Mysterious Room.");
		Location* br = new Location("Bottle Room" ,"You are in Bottle Room, you see passage to the (2)Larder on the south and entrance to the (3)Great Hall to the west.");
		Location* tr = new Location("Trolls Room","You see trolls gathered around a bonfire, better keep quiet. You can go to the (1)Library, (2)Great Hall or (4)Mysterious Room.");
		Location* lb = new Location("Library","Books, books, books, so much knowlegde, if only you could read... You see only one door leading south to (2)Trolls Room... but wait! You spot a secret entrence to the (4)Mysterious Room.");
		Location* mr = new Location("Mysterious Room","You are in the Mysterious Room. You get the whole mystery now. Not that amazing. You can travel north to (1)Library, south to (2)Trolls Room or west to (3)Great Hall.");
		
		//setting up exits for each location
		en->setExits(dc, nullptr, nullptr, nullptr,2,NULL,NULL,NULL);
		dc->setExits(wr, en, gr, kt,1,2,1,2);
		gr->setExits(ba, nullptr, nullptr, dc,2,NULL,NULL,1);
		ba->setExits(nullptr, gr, nullptr, nullptr,NULL,2,NULL,NULL);
		wr->setExits(nullptr, dc, nullptr, ld,NULL,1,NULL,10);
		kt->setExits(gh, ib, dc, ld,1,2,2,1);
		ib->setExits(kt, nullptr, nullptr, nullptr,10,NULL,NULL,NULL);
		ld->setExits(br, wr, kt, nullptr,1,10,1,NULL);
		gh->setExits(br, kt, tr, mr,2,1,2,4);
		br->setExits(nullptr, ld, gh, nullptr,NULL,1,2,NULL);
		tr->setExits(lb, gh, nullptr, mr,1,2,NULL,3);
		lb->setExits(nullptr, tr, nullptr, mr,NULL,1,NULL,3);
		mr->setExits(lb, tr, gh, nullptr,3,4,3,NULL);

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

//SEARCHES

//DFS SEARCH
class DFSsearch
{
	int noRooms;
	Location* start;
	Location* target;
	vector<Location*> list;
	struct Node
	{
		Location* location;
		bool visited = false;
	
	};

	
	
	void search()
	{
		
	}
	DFSsearch(int nR, Node s, Node t, vector<Location*> l)
	{
		
		
		

		vector<Node*> vList;
		
		//vList.push_back(s);

	}


};

int main()
{

	

	World* world = new World();

	Player* player = new Player();

	player->setLocation(world->locations.front());

	//game loop

	cout << "Welcome to Tunnels of Terror!";


	while (player)
	{
		cout << "-999 to exit" << endl;
		player->currentLoc->getDesc();
		player->getEnergy();
		player->travel();
		if (player->energy < 1)
			break;
		
		
	}
	cout << "You died." << endl;
	
	getchar();
	getchar();
	

	return 0;
}
