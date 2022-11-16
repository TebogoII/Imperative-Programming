#ifndef TOME_H
#define TOME_H
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

class tome;
ostream& operator<<(ostream& output, const tome& t);

class tome
{
private:
	string references[10];
	string tomeName;
	string author;
	int currSpells;
public:
	tome(string name, string author);
	tome(string, int, string, string*);
	~tome();
	int getTomeSize() const;
	string getSpell(int) const;
	string getName() const;
	string getAuthor() const;
	friend ostream& operator<<(ostream& output, const tome& t);
	tome operator+(const string& add);
	tome operator-(const string& sub);
	tome& operator=(const tome& oldTome);
	bool operator>(const tome& t);
	bool operator<(const tome& t);
	bool operator==(const tome& t);
};
#endif