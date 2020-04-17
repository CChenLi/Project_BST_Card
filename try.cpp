#include <iostream>
using namespace std;

class card{
private:
	char suit;
	char num;

public:
	card* next;
	card(char s, char n);
	char getS() const;
	char getN() const;
	//void setS(char s);
	//void setN(char n);
	friend bool operator==(const card& c1, const card& c2);
};

card::card(char s, char n){
	suit = s;
	num = n;
	next = 0;
}

char card::getN() const{ 
	return num;
}

char card::getS() const{
	return suit;
}

bool operator==(const card& c1, const card& c2){
	return (c1.num == c2.num && c1.suit == c2.suit);
}

class Player{
private:
	string name;
	card* head;
	int len;

public:
	Player(string playername);
	~Player();
	int search(card* c1);
	bool Myturn(Player& p2);
	void insert(card c);
	void removeCard(int n);
	friend ostream& operator<<(ostream& out, const Player& p);
};

Player::Player(string playername){
	name = playername;
	head = 0;
	len = 0;
}

Player::~Player(){
	//cout << "reach destructor of " << name << endl;
	card* tem = 0;
	while(head){
		tem = head->next;
		delete head;
		head = tem;
	}
}

void Player::insert(card c){
	if(!head){
		head = new card(c.getS(), c.getN());
		head->next = 0;
	} else {
		card* nc = head;
		while(nc->next){
			nc = nc->next;
		}
		nc->next = new card(c.getS(), c.getN());
	}
}

void Player::removeCard(int n){
	assert(head);
	card* c = head;
	card* beforeC = head;
	for(int i = 1; i < n; i++){
		beforeC = c;
		c = c->next;
	}
	if(n<2){
		head = head->next;
		delete c;
		beforeC = 0;
	}else if(c->next == 0){
		beforeC->next = 0;
		delete c;
	} else{
		beforeC->next = c->next;
		delete c;
	}

}

int Player::search(card* c1){
	if(!head) return 0;
	card* c2 = head;
	int pos = 1;
	while(c2){
		if(*c1 == *c2){
			this->removeCard(pos);
			return pos;
		} else {
			c2 = c2->next;
			pos++;
		}
	}
	return 0;
}

bool Player::Myturn(Player& p2){
	card* c1 = head;
	int pos1 = 1;
	while(c1){
		if(p2.search(c1)){
			cout << name <<" picked matching card: " << c1->getS() << " " <<c1->getN() << endl;
			this->removeCard(pos1);
			return true;
		} else {
			c1 = c1->next;
			pos1++;
		}
	}
	return false;
}

ostream& operator<<(ostream& out, const Player& p){
	out << p.name << "'s cards:" << endl;
	card* c = p.head;
	while(c){
		out << c->getS() << " " << c->getN() << endl;
		c = c->next;
	}
	return out;
}

int main(){
	card c1('h', '3');
	card c2('s', '2');
	card c3('c', 'a');
	card c4('c', '3');
	card c5('h', '9');
	card c6('s', 'a');

	card c7('c', '2');
	card c8('s', 'a');
	card c9('d', 'j');
	card c0('h', '9');
	card c11('c', '3');
	

	Player p1("Alice");
	Player p2("Bob");

	p1.insert(c1);
	p1.insert(c2);
	p1.insert(c3);
	p1.insert(c4);
	p1.insert(c5);
	p1.insert(c6);

	p2.insert(c7);
	p2.insert(c8);
	p2.insert(c9);
	p2.insert(c0);
	p2.insert(c11);
	
	p1.Myturn(p2);
	p2.Myturn(p1);
	p1.Myturn(p2);

	cout << p1;
	cout << p2;

	return 0;

}










