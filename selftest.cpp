
#include <cassert>
#include <iostream>
using namespace std;

struct card{
		char suit;
		char num;
		card* next;
		card* prev;
		friend bool operator==(card c1, card c2);
	};

class Player{
private:
	
	card* head;
	string name;
	int len;


	//bool compareHelper(card* p1, card* head);

public:
	Player(string playername);
	~Player();
	void insert(char s, char n);
	void delecard(card* ptr);
	void deleNth(int n);
	void compare(int n, Player p);
	string Name() const;
	card* first() const;
	int NumCards();
	//friend bool operator==(card c1, card c2);
	friend ostream& operator<<(ostream& out, const Player& p);
};
//bool operator==(card c1, card c2);
ostream& operator<<(ostream& out, const Player& p);

Player::Player(string playername){
	head = 0;
	name = playername;
	len = 0;
}

void DeconHelper(card *head){
	if(!head) return;
	DeconHelper(head->next);
	delete head;
}

Player::~Player(){
	DeconHelper(head);
}

string Player::Name() const{
	return name;
}

card* Player::first() const{
	return head;
}

int Player::NumCards(){
	return len;
}

void Player::insert(char s, char n){
	if(!head){
		head = new card;
		head->suit = s;
		head->num = n;
		head->next = 0;
		head->prev = 0;
	} else {
		card* c = head;
		while(c->next){
			c = c->next;
		}
		c->next = new card;
		c->next->suit = s;
		c->next->num = n;
		c->next->next = 0;
		c->next->prev = c;
	}
	len++;
}

void Player::delecard(card* ptr){
	if(ptr->prev == 0){
		head = ptr->next;
		head->prev = 0;
		delete ptr;
	}else if(ptr->next == 0){
		ptr->prev->next = 0;
		delete ptr;
	}else {
	ptr->prev->next = ptr->next;
	ptr->next->prev = ptr->prev;
	delete ptr;
	}	
	cout << "breakpoint5" << endl;
	len--;
}

void Player::deleNth(int n){
	card* c = head;
	for(int i = 1; i < n; i++){
		c = c->next;
	}
	delecard(c);
}


void Player::compare(int n, Player p){
	card* c = this->head;
	int i = 1;
	while(i < n){
		c = c->next;
		i++;
	}
	card* c2 = p.head;
	while(c2){
		cout << "breakpoint1" << endl;
		if(c->suit == c2->suit && c->num == c2->num){
			cout << "breakpoint 2" << endl;
			cout << name <<" picked matching card " << c->suit << " " << c->num << endl;
			this->delecard(c);
			cout << "breakpoint3" << endl;
			p.delecard(c2);
			cout << "breakpoint4" << endl;
			return;
		} else {
			c2 = c2->next;
		}
	}

	
}
/*
bool operator==(card c1, card c2){
	return (c1.suit == c2.suit && c1.num == c2.num);
}
*/
ostream& operator<<(ostream& out, const Player& p){
	out << p.Name() << "'s cards:"<< endl;
	card* c = p.first();
	while(c){
		out << c->suit << " " << c->num << endl;
		c = c->next;
	}
	return out;
}




int main(){
	Player p1("Alice");
	p1.insert('h', '3');
	p1.insert('s', '2');
	p1.insert('c', 'a');
	p1.insert('c', '3');
	p1.insert('h', '9');
	p1.insert('s', 'a');

	//p1.deleNth(2);
	//p1.deleNth(4);
	cout << p1;
	cout << p1;

	Player p2("Bob");
	p2.insert('c', '2');
	p2.insert('c', '3');
	p2.insert('d', 'j');
	p2.insert('h', '9');
	p2.insert('c', '3');

	p1.compare(4, p2);

	//cout << c2==c1 << endl;



	//p1.compare(1, p2);

	//cout << *(p1.head== *(p2.head) << endl;


	
	
}

