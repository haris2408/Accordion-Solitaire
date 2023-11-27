#include<string>
#include<iostream>
using namespace std;
#pragma once
class card
{
private:
	string suit;
	string rank;
public:
	card() {
		this->suit = "not initialized";
		this->rank = "not initialized";
	}
	card(string suitt, string rankk) {
		this->suit = suitt;
		this->rank = rankk;
	}
	string getcard() {
		return this->rank + this->suit;
	}
	string get_rank() {
		return this->rank;
	}
	string get_suit() {
		return this->suit;
	}
	void print_card() {
		for (int i = 0; i <= 16; i++){
			cout << "-";
		}
		cout << "\n";
		cout << "-\t\t-\n";
		cout << "-\t"<<this->rank<<"\t-\n";
		cout << "-\t\t-\n";
		cout << "-\t" << this->suit << "\t-\n";
		cout << "-\t\t-\n";

		for (int i = 0; i <=16; i++) {
			cout << "-";
		}
	}
};

