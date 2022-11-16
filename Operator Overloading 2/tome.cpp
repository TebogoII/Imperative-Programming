#include "tome.h"

tome::tome(string name, string author)
{
	this->tomeName=name;
	this->author=author;
	currSpells=0;	
}

tome::tome(string name, int tomeSize, string author, string* initialList)
{
	this->tomeName=name;
	currSpells=tomeSize;
	this->author=author;
	for (int i = 0; i < tomeSize; ++i)
		{
			references[i]=initialList[i];
			//cout<<references[i]<<endl;
		}	
}

tome::~tome()
{

}

int tome::getTomeSize() const
{
	return currSpells;
}

string tome::getSpell(int i) const
{
	if (i<10 && i>=0) 
		return references[i];
}

string tome::getName() const
{
	return tomeName;	
}

string tome::getAuthor() const
{
	return author;
}

ostream& operator<<(ostream& output, const tome& t)
{
	output<<"Tome Name: "<<t.tomeName<<endl;
	output<<"Author: "<<t.author<<endl;
	output<<"References: ";
	int count=0;
	for (int i = 0; i < 10; ++i)
	{
		if (""!=t.references[i])
		{	
			output<<t.references[i];
			count++;
			if (count!=t.currSpells)
			{
				output<<", ";
			}
		}	
	}
	output<<endl;
	return output;
}

tome tome::operator+(const string& add)
{
	if (currSpells<10)
	{
		for (int i = 0; i < 10; ++i)
		{
			if (""==this->references[i])
			{
				this->references[i]=add;
				currSpells++;
				return *this;
			}
		}
	}
	return *this;
}

tome tome::operator-(const string& sub)
{
	for (int i = 0; i < 10; ++i)
	{
		if (sub==this->references[i])
		{
			this->references[i]="";
			currSpells--;
			return *this;
		}
	}
	return *this;	
}

tome& tome::operator=(const tome& oldTome)
{
	this->tomeName=oldTome.tomeName;
	this->author=oldTome.author;
	this->currSpells=oldTome.currSpells;
	for (int i = 0; i < 10; ++i)
	{
		if (oldTome.references[i]!="")
		{
			this->references[i]=oldTome.references[i];
		}
	}
	return *this;
}

bool tome::operator>(const tome& t)
{
	bool out=false;
	if (this->currSpells>t.currSpells)
	{
		out=true;
	}
	return out;
}

bool tome::operator<(const tome& t)
{
	bool out=false;
	if (this->currSpells<t.currSpells)
	{
		out=true;
	}
	return out;
}

bool tome::operator==(const tome& t)
{
	bool out=false;
	if (this->currSpells==t.currSpells)
	{
		for (int i = 0; i < 10; ++i)
		{
			string ing=this->references[i];
			int old, curr;
			old=0;
			curr=0;
			for (int i = 0; i < 10; ++i)
			{
				if (ing==this->references[i])
				{
					old++;
				}
			}
			for (int i = 0; i < 10; ++i)
			{
				if (ing==t.references[i])
				{
					curr++;
				}
			}
			if (curr!=old)
			{
				return out;
			}
		}
		out=true;
	}
	return out;	
}
