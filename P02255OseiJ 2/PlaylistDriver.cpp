// PlaylistDriver.cpp -- MOST FUNCTIONS ARE COMPLETE -- "processMenuChoice" needs to be done
// DO NOT INCLUDE ANYTHING OTHER THAN THESE LIBRARIES/CLASSES
#include <iostream>
#include <limits>
#include "Playlist.h"

using namespace std;

// THE FOLLOWING FUNCTION DECLARATIONS ARE COMPLETE -- DO NOT CHANGE
char getMenuChoice();
void processMenuChoice(char, Playlist&);
int getInteger();
bool isInteger(const string& s);

// THE FOLLOWING FUNCTION IS COMPLETE -- DO NOT CHANGE
int main() {
	Playlist playlist;
	char choice = ' ';

	choice = getMenuChoice();

	while (choice != 'q') {
		processMenuChoice(choice, playlist);
		choice = getMenuChoice();
	}

	cout << "\n>>> Exiting Playlist <<<" << endl;

	return 0;
}

// THE FOLLOWING FUNCTION IS COMPLETE -- DO NOT CHANGE
char getMenuChoice() {
	// Output menu option, prompt users for valid selection
	string menuOptions = "adpstocq";
	char choice = ' ';

	do {
		cout << "\n ************** PLAYLIST MENU **************************" << endl;

		cout << "\ta - Add song" << endl;
		cout << "\td - Remove song" << endl;
		cout << "\tp - Change position of song" << endl;
		cout << "\ts - Output songs by specific artist" << endl;
		cout << "\tt - Output total time of playlist (in seconds)" << endl;
		cout << "\to - Output full playlist" << endl;
		cout << "\tc - Clear playlist" << endl;
		cout << "\tq - Quit" << endl << endl;

		cout << "\tChoose option: ";
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << " *******************************************************" << endl;

	} while (menuOptions.find(choice) == string::npos);

	return choice;
}

// ************************** TO BE COMPLETED ******************************************
void processMenuChoice(char choice, Playlist& playlist) {
	// Declaration of local variables needed for this function
	SongNode* songNode = nullptr;
	string uniqueID;
	string songName;
	string artistName;
	int songLength = 0;

	int nodeCount = 0;
	int currPosition = 0;
	int newPosition = 0;

	// COMPLETE THE ACTIONS FOR EACH CHOICE
	// Call corresponding menu action -- don't forget to add "break" statements
	switch (choice) {
	case 'a':
		// Add song to playlist
		// Prompt user for song unique id
		// if the playlist already contains this id
		//		print message and break
		// otherwise
		//		prompt for the rest of the song information
		//		create a new SongNode
		//		insert at the front of the playlist
		//		print the playlist
		cout << "\n\tAdd Song - Enter song's unique ID: ";
		cin >> uniqueID;
		if (playlist.contains(uniqueID)) {
			cout << endl;
			cout << "\t<<< Duplicate unique ID-not added! >>>" << endl;
		
		}
		else {

			cout << "\t    Enter song's name: ";
			cin.ignore();
			getline(cin, songName);
			cout << "\t    Enter artist's name: ";
			//cin.ignore();
			getline(cin, artistName);
			//cout << endl;
			cout << "\t    Enter song's length (in seconds): ";
			cin >> songLength;
			//songNode = new SongNode;
			playlist.insertFront(new SongNode(uniqueID, songName, artistName, songLength, NULL));
			playlist.printPlaylist();
		}
		
		break;
	case 'd':
		// Remove song from playlist
		// Prompt user for song unique id
		// call remove
		// print appropriate message based on results from remove
		// print the playlist
		cout << endl << "\tDelete Song - Enter song's unique Id: ";
		cin >> uniqueID;
		cout << endl;
		if (playlist.remove(uniqueID)) {
			cout << "\t<<< Successfully deleted song with unique ID " << uniqueID << " >>>" << endl;


		}
		else {

			cout << "\t<<<Song with unique ID " << uniqueID << " is not in playlist! >>>" << endl;
		}
		cin.ignore();
		playlist.printPlaylist();

		break;
	case 'p':
		// Change song position in playlist
		// count the number of songs in the list
		// if the count <=1
		//		print appropriate message
		// otherwise
		//		ask user for valid current position -- use getInteger() to get value
		//			if entry invalid break with appropriate message
		//		ask user for valid new position -- use getInteger() to get value
		//			if entry invalid break with appropriate message
		//
		//		call changeSongPosition
		//		print out message
		//		print playlist
		cout << "\n\tChange Song's Playlist Position -" << endl;
		nodeCount = playlist.getNodeCount();

		cout << "\t    Current position(1 through " << nodeCount << "): ";
		//cin.ignore();
		currPosition = getInteger();
		if ((currPosition > nodeCount) || (currPosition < 1)) {
			cout << "\n\t<<<Invalid current position!>>>" << endl;
			break;
		}

		cout << "\t   New position(1 through " << playlist.getNodeCount() << "): ";
		//cin.ignore();
		newPosition = getInteger();
		if ((newPosition > nodeCount) || (newPosition < 1) || (newPosition == currPosition)) {
			cout << "\n\t    <<<Invalid new position!>>>" << endl;
			break;

		}
		playlist.changeSongPosition(currPosition, newPosition);
		cout << "\t>>> Song moved from position " << currPosition << " to position " << newPosition << ">>>" << endl;
		playlist.printPlaylist();

		break;
	case 's':
		// prompt the user for the artist's name
		// Output playlist for specific artist
		cout << endl << "\tSearch Playlist- Enter artist's name: ";
		getline(cin, artistName);
		playlist.printByArtist(artistName);

		break;
	case 't':
		// Output playlist total time
		cout << endl << "\tPlaylist Total Time - ";
		cout << playlist.getTotalTime() << endl;
		break;
	case 'o':
		// Print the playlist
		playlist.printPlaylist();
		break;
	case 'c':
		// Clear the playlist
		playlist.clearList();
		cout << endl << "\t>>> Playlist has been cleared! <<<" << endl;
		break;
	}
}

// THE FOLLOWING FUNCTIONS ARE COMPLETE.
// CAN BE USED TO GET AN INTEGER AND DO THE APPROPRIATE VALIDATION
//		getInteger() uses isInteger()
int getInteger() {
	string str = "";
	getline(cin, str);

	while (!(isInteger(str))) {
		cout << "\t\t\t>>> Invalid integer - please enter an integer: ";
		getline(cin, str);
	}

	// convert str to an int
	return stoi(str);
}

bool isInteger(const std::string& s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char* p; //stores the first location of non-integer character

	// The C library function long int strtol(const char *str, char **endptr, int base)
	//		converts the initial part of the string in str to a long int value according
	//		to the given base, which must be between 2 and 36 inclusive, or be the special value 0.
	strtol(s.c_str(), &p, 10);

	return (*p == 0); // will be true if s contains an integer
}

