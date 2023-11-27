#include<iostream>
#include<vector>
#include <algorithm>
#include"card.h"
using namespace std;
#pragma once

class deck
{
private:
	vector<card*> cards;
	void init() {
		card* newcard;
		for (int i = 1; i <= 13; i++) {
			if (i == 1) {
				 newcard = new card("hearts", "A");
			}
			else if(i == 11){
				 newcard = new card("hearts", "J");
			}
			else if (i == 12) {
				 newcard = new card("hearts", "Q");
			}
			else if (i == 13) {
				 newcard = new card("hearts", "K");
			}
			else {
				 newcard = new card("hearts", to_string(i));
			}
			this->cards.push_back(newcard);
		}
		for (int i = 1; i <= 13; i++) {
			if (i == 1) {
				newcard = new card("diamond", "A");
			}
			else if (i == 11) {
				newcard = new card("diamond", "J");
			}
			else if (i == 12) {
				newcard = new card("diamond", "Q");
			}
			else if (i == 13) {
				newcard = new card("diamond", "K");
			}
			else {
				newcard = new card("diamond", to_string(i));
			}
			this->cards.push_back(newcard);
		}
		for (int i = 1; i <= 13; i++) {
			if (i == 1) {
				newcard = new card("spades", "A");
			}
			else if (i == 11) {
				newcard = new card("spades", "J");
			}
			else if (i == 12) {
				newcard = new card("spades", "Q");
			}
			else if (i == 13) {
				newcard = new card("spades", "K");
			}
			else {
				newcard = new card("spades", to_string(i));
			}
			this->cards.push_back(newcard);
		}
		for (int i = 1; i <= 13; i++) {
			if (i == 1) {
				newcard = new card("club", "A");
			}
			else if (i == 11) {
				newcard = new card("club", "J");
			}
			else if (i == 12) {
				newcard = new card("club", "Q");
			}
			else if (i == 13) {
				newcard = new card("club", "K");
			}
			else {
				newcard = new card("club", to_string(i));
			}
			this->cards.push_back(newcard);
		}
	}
	
public:
	deck() {
		this->init();
	}

	void shuffle() {
		srand(time(0));
		random_shuffle(this->cards.begin(), this->cards.end());
	}

	card* get_card() {
		card* ans = this->cards[0];
		this->cards.erase(this->cards.begin());
		return ans;
	}

	int getSize() {
		return this->cards.size();
	}

	void print_deck() {
		cout << this->cards.size() << endl;
		for (auto card : this->cards) {
			card->print_card();
			cout << endl;
		}
	}
};

