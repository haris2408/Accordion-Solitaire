#include"deck.h"
#include"card.h"
#include<iostream>
#include<stack>
#include<vector>
#include<conio.h>
using namespace std;
#pragma once
class accordion
{
private:
	vector<stack<card*>> piles;
	deck d1;
	void printPiles_and_newcard(card* c) {
		for (int i = 0; i <= 16 * (piles.size() + 1); i++) {
			cout << "-";
		}
		cout << "\n";
		for (int i = 0; i < piles.size() + 1; i++) {
			cout << "-\t\t-";
		}
		cout << "\n";
		for (int i = 0; i < piles.size(); i++) {
			cout << "-\t" << piles[i].top()->get_rank() << "\t-";
		}
		cout << "-\t" << c->get_rank() << "\t-";
		cout << "\n";
		for (int i = 0; i < piles.size() + 1; i++) {
			cout << "-\t\t-";
		}
		cout << "\n";
		for (int i = 0; i < piles.size(); i++) {
			cout << "-\t" << piles[i].top()->get_suit() << "\t-";
		}
		cout << "-\t" << c->get_suit() << "\t-";
		cout << "\n";
		for (int i = 0; i < piles.size() + 1; i++) {
			cout << "-\t\t-";
		}
		cout << "\n";

		for (int i = 0; i <= 16 * (piles.size() + 1); i++) {
			cout << "-";
		}
	}
	void printPiles() {
		for (int i = 0; i <= 16 * piles.size(); i++) {
			cout << "-";
		}
		cout << "\n";
		for (int i = 0; i < piles.size(); i++) {
			cout << "-\t\t-";
		}
		cout << "\n";
		for (int i = 0; i < piles.size(); i++) {
			cout << "-\t" << piles[i].top()->get_rank() << "\t-";
		}
		cout << "\n";
		for (int i = 0; i < piles.size(); i++) {
			cout << "-\t\t-";
		}
		cout << "\n";
		for (int i = 0; i < piles.size(); i++) {
			cout << "-\t" << piles[i].top()->get_suit() << "\t-";
		}
		
		cout << "\n";
		for (int i = 0; i < piles.size(); i++) {
			cout << "-\t\t-";
		}
		cout << "\n";

		for (int i = 0; i <= 16 * piles.size(); i++) {
			cout << "-";
		}
		cout << endl;
	}
	void printScreen(card* c) {
		cout << "NEW CARD: " << c->get_rank() << " of " << c->get_suit() << endl;
		this->printPiles_and_newcard(c);
		cout << "\n\tNum Of Piles: " << this->piles.size() << endl;
		cout << "\tDeck Size: " << this->d1.getSize() << endl<<endl<<endl;
	}
	bool isNeighborMatch(card* c) {
		if (c->get_rank() == this->piles[this->piles.size() - 1].top()->get_rank() || c->get_suit() == this->piles[this->piles.size() - 1].top()->get_suit()) {
			return true;
		}
		return false;
	}

	bool isThirdNeighborMatch(card* c) {
		if (this->piles.size()>3 && (c->get_rank() == this->piles[this->piles.size() - 3].top()->get_rank() || c->get_suit() == this->piles[this->piles.size() - 3].top()->get_suit())) {
			return true;
		}
		return false;
	}
	
	bool isNeighborMatch(card* c,int i) {
		if (c->get_rank() == this->piles[i - 1].top()->get_rank() || c->get_suit() == this->piles[i - 1].top()->get_suit()) {
			return true;
		}
		return false;
	}
	bool isThirdNeighborMatch(card* c, int i) {
		if (i > 3 && (c->get_rank() == this->piles[i - 3].top()->get_rank() || c->get_suit() == this->piles[i - 3].top()->get_suit())) {
			return true;
		}
		return false;
	}

	void checkRestOfDeckForMovement() {
		for (int i = 1; i < this->piles.size(); i++) {
			card* c = this->piles[i].top();
			if (isNeighborMatch(c,i) && isThirdNeighborMatch(c,i)) {
				this->printPiles();
				int choice = 0;
				do {
					cout <<"1.move"<< c->get_rank() << " of " << c->get_suit() <<" to neighbor pile"
						<<"\n2.move"<< c->get_rank() << " of " << c->get_suit() <<" to third neighbor pile\n    choice:";
					cin >> choice;
				} while (choice < 1 || choice>2);
				if (choice == 1) {

					this->piles[i - 1].push(c);
					this->piles.erase(this->piles.begin() + i);
				}
				else {

					this->piles[i - 3].push(c);
					this->piles.erase(this->piles.begin() + i);
				}
				cout << "\n\n";
			}
			else if (isNeighborMatch(c,i)) {
				this->printPiles();
				cout << "Moving " << c->get_rank() << " of " << c->get_suit() << " to the neighbor pile\nPress Enter to continue\n\n\n";
				_getch();
				this->piles[i - 1].push(c);
				this->piles.erase(this->piles.begin() + i);
			}
			else if (isThirdNeighborMatch(c,i)) {
				this->printPiles();
				cout << "Moving " << c->get_rank() << " of " << c->get_suit() << " to the third neighbor pile\nPress Enter to continue\n\n\n";
				_getch();
				this->piles[i - 3].push(c);
				this->piles.erase(this->piles.begin() + i);
			}
		}
	}
public:
	accordion() {
	}
	void play() {

		this->d1.shuffle();

		stack<card*> s1;
		card* c = this->d1.get_card();
		s1.push(c);
		this->piles.push_back(s1);
		while (this->d1.getSize() > 0) {
			card* c = this->d1.get_card();
			this->printScreen(c);
			if (isNeighborMatch(c) && isThirdNeighborMatch(c)) {
				int choice = 0;
				do {
					cout << "1.move new card to neighbor pile\n2.move new card to third neighbor pile\n    choice:";
					cin >> choice;
				} while (choice < 1 || choice>2);
				if (choice == 1) {
					
					this->piles[this->piles.size() - 1].push(c);
				}
				else {
					
					this->piles[this->piles.size() - 3].push(c);
				}
				cout << "\n\n";
				checkRestOfDeckForMovement();
			}
			else if (isNeighborMatch(c)) {
				cout << "Moving to new card the neighbor pile\nPress Enter to continue\n\n\n";
				_getch();
				this->piles[this->piles.size() - 1].push(c);
				checkRestOfDeckForMovement();
			}
			else if (isThirdNeighborMatch(c)) {
				cout << "Moving new card to the third neighbor pile\nPress Enter to continue\n\n\n";
				_getch();
				this->piles[this->piles.size() - 3].push(c);
				checkRestOfDeckForMovement();
			}
			else {
				stack<card*> s;
				s.push(c);
				this->piles.push_back(s);
				cout << "No move available\nPress Enter to continue\n\n\n";
				_getch();
			}
		}
		if (this->piles.size() > 1) {
			cout << "\n\n\n\t\t\t Objective not achieved"
				<< "\n\t\t\t You were suppose to get the whole deck into 1 pile"
				<< "\n\t\t\t You created " << this->piles.size() << " piles\n\n\n\n";
		}
		else if (this->piles.size() == 1) {
			cout << "\n\n\n\t\t\tCONGRATULATIONS!!!"
				<< "Objective Achieved\n\n\n\n\n";
		}
	}
};

