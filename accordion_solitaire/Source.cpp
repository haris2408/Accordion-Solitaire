#include<iostream>
#include<conio.h>
#include<stack>
#include<vector>
#include"card.h"
#include"deck.h"
#include"accordion.h"

int main() {
	//card c("hearts",to_string(1));
	//c.print_card();
	//deck d;
	//d.shuffle();
	//d.print_deck();

	/*vector<stack<card*>> piles;
	card* c = d.get_card();
	stack<card*> s1;
	s1.push(c);
	piles.push_back(s1);

	c = d.get_card();
	stack<card*> s2;
	s2.push(c);
	piles.push_back(s2);

	c = d.get_card();
	stack<card*> s3;
	s3.push(c);
	piles.push_back(s3);*/

	accordion acc;
	acc.play();
	/*int choice = 0;
	do {
		cout << "1.move to neighbor pile\n2.move to third neighbor pile\n    choice:";
		cin >> choice;
	} while (choice < 1 || choice > 2);*/
	
	return _getch();
}