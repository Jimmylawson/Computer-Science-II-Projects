// Playlist.cpp -- MOST FUNCTIONS TO BE COMPLETED -- READ COMMENTS
// DO NOT INCLUDE ANYTHING OTHER THAN THESE LIBRARIES/CLASSES
#include <iostream>
#include "Playlist.h"
using namespace std;

// ************************** TO BE COMPLETED ******************************************
//Default and only constructor -- call private function init
Playlist::Playlist() {
	init();
}

// ************************** TO BE COMPLETED ******************************************
//Destructor -- call private function eraseList with head
Playlist::~Playlist() {
	clearList();
	cout << "\t>>>Playlist destructor called<<<" << endl;
}

// ************************** TO BE COMPLETED ******************************************
int Playlist::getNodeCount() {
	/*int count = 0;
	SongNode* newNode = head;
	while (newNode != NULL) {
		count++;
		newNode->getNext();
	}
	return count;
	*/
	return nodeCount;
}

// ************************** TO BE COMPLETED ******************************************
//Add a SongNode to the front of the list
void Playlist::insertFront(SongNode* songNode) {
	if (head == NULL) {
		head = songNode;

	}
	else {
		songNode->setNext(head);
		head = songNode;
	}
	nodeCount++;

}

// ************************** TO BE COMPLETED ******************************************
//Remove an SongNode from the list; if the value doesn't exist in the list return false;
//   otherwise search for the SongNode, adjust pointers, and return true.
bool Playlist::remove(string id) {
/*	int numCount = 0;
	SongNode* newNode = head;
	SongNode* nodetoRemove = head;
	while (nodetoRemove != nullptr) {
		if (nodetoRemove->getUniqueID() == id) {
			if (nodetoRemove != head) {
				for (int i = 0; i < numCount - 1; i++) {
					newNode = newNode->getNext();
				}
				newNode->setNext(nodetoRemove->getNext());
				delete nodetoRemove;
				nodeCount--;
			}
			else if (nodetoRemove == head && nodeCount == 1) {
				delete nodetoRemove;
				init();
			}
			else {
				head = nodetoRemove->getNext();
				delete nodetoRemove;
				nodeCount--;
			}
			return true;
		}
		nodetoRemove = nodetoRemove->getNext();
		numCount++;
	}
	*/
	int numCount = 0;
	SongNode* newNode = head;
	SongNode* nodetoRemove = head;
	if (!contains(id)) {
		return false;
	}
	while (newNode->getUniqueID() != id) {
		nodetoRemove = newNode;
		newNode = newNode->getNext();
	}
	
	if (newNode == head) {
		head = newNode->getNext();
		delete newNode;
	}
	else {
		nodetoRemove->setNext(newNode->getNext());
		delete newNode;
	}
	nodeCount--;
	return true;
}

// ************************** TO BE COMPLETED ******************************************
//This function is the most complicated
//   songPosition and newPosition values have been validated in main
//		before this function is called
void Playlist::changeSongPosition(int songPosition, int newPosition) {

	// STEP 1: Find songNode that is at songPosition

	SongNode* currNode = head;
	SongNode* temp = head;
	SongNode* newNode = head;
	int count = getNodeCount();
	// STEP 2: Remove songNode at songPosition from list. Keep reference to that songNode.
	if (songPosition == 1) {
		currNode = head;
	}
	else {
		for (int i = 0; i < songPosition - 1; i++) {
			currNode = currNode->getNext();
		}
		for (int i = 0; i < songPosition - 2; i++) {
			temp = temp->getNext();
		}
	}
	newNode = currNode->getNext();
	// If songPosition was 1, song being moved was the head of the list
	//		so change what head points to
	// otherwise
	//		find the node before songNode in the list and adjust that node's
	//		next pointer

	// At this point songNode is no longer in the list
	if (songPosition == 1) {
		head = newNode;
	}
	else {
		temp->setNext(newNode);
	}
	if (newPosition == 1) {
		SongNode* temp2 = head;
		head = currNode;
		currNode->setNext(temp2);
	}
	else {
		SongNode* temp3 = head;
		for (int i = 0; i < songPosition - 2; i++) {
			temp3 = temp3->getNext();
		}
		insertAfter(temp3, currNode);
	}


	// STEP 3: Insert song at newPosition
	//	If the newPosition was 1 ... the songNode will become the head of the list
	//		adjust pointers appropriately
	//	otherwise
	//		find the node that is before the newPosition
	//		it will be somewhere after original head position or at
	//		the end of the list
	//		call insertAfter
}

// ************************** TO BE COMPLETED ******************************************
// insertAfter ... inserts newNode after prevNode
void Playlist::insertAfter(SongNode* prevNode, SongNode* newNode) {
	newNode->setNext(prevNode->getNext());
	prevNode->setNext(newNode);
}

// ************************** TO BE COMPLETED ******************************************
// calculate total time in seconds in playlist
int Playlist::getTotalTime() {
	int sum = 0;
	SongNode* nodetime = head;
	while (nodetime != nullptr) {
		sum += nodetime->getSongLength();
		nodetime = nodetime->getNext();
	}
	return sum;
}

// ************************** TO BE COMPLETED ******************************************
// Print out all nodes in the list
void Playlist::printPlaylist() {
	printTableHeadings();
	SongNode* newNode = head;
	int value = 1;
	if (newNode == nullptr) {
		cout << endl;
		cout << "\t>>>Playlist is empty! <<<" << endl;
	}
	if (newNode != NULL) {
		while (newNode != NULL) {
			printTableRow(newNode, value);
			value++;
			newNode = newNode->getNext();
		}
	}
}

// ************************** TO BE COMPLETED ******************************************
// Print out all nodes in the list with the artist's name
void Playlist::printByArtist(string artist) {
	SongNode* newNode = head;
	int value = 1;

	printTableHeadings();
	while (newNode != NULL) {
		string artistName = newNode->getArtistName();
		if (artist == artistName) {
			printTableRow(newNode, value);

		}
		value++;
		newNode = newNode->getNext();
	}

}

// ************************** TO BE COMPLETED ******************************************
// Search to see if list contains the uniqueID
bool Playlist::contains(const string& id) {
	SongNode* newNode = head;
	/*bool isTrue = false;
	if (newNode != nullptr) {
		while (newNode != nullptr) {
			if (newNode->getUniqueID() == id) {
				isTrue = true;
			}
			else {
				newNode = newNode->getNext();
			}

		}
	}
	return isTrue;
*/
	while (newNode != NULL) {
		if (id == newNode->getUniqueID()) { return true; }
		newNode = newNode->getNext();
	}
	return false;
}

// ************************** TO BE COMPLETED ******************************************
// Clear the list -- remove all nodes and initialize the playlist again
void Playlist::clearList() {
	SongNode* clearNode = head;
	while (head != NULL) {
		clearNode = head;
		head = head->getNext();
		delete clearNode;
	}
	init();
}

// ************************** TO BE COMPLETED ******************************************
// Set up linked list starting values
void Playlist::init() {
	head = NULL;
	nodeCount = 0;
}

// ************************** TO BE COMPLETED ******************************************
// Delete all allocated objects
void Playlist::eraseList(SongNode* head) {
	clearList();
}

// COMPLETED -- DO NOT CHANGE
// Print headings for playlist table
void Playlist::printTableHeadings() {
	cout << "\n\t------------------------- PLAYLIST ------------------------------" << endl;
	cout << "\t" << setw(5) << left << "Pos  ";
	cout << setw(12) << left << "Unique Id";
	cout << setw(20) << left << "Song";
	cout << setw(20) << left << "Artist";
	cout << setw(4) << left << "Time" << endl;
}

// COMPLETED -- DO NOT CHANGE
void Playlist::printTableRow(SongNode* song, int position) {
	cout << "\t" << setw(5) << left << position;
	cout << setw(12) << left << song->getUniqueID();
	cout << setw(20) << left << song->getSongName();
	cout << setw(20) << left << song->getArtistName();
	cout << setw(4) << right << song->getSongLength() << endl;
}
