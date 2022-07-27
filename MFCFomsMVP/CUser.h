#pragma once
#include <string>

using namespace std;

class CUser
{
public:
	//getter
	long GetID();
	string GetName();
	int GetAge();
	string GetAddress();
	//setter
	void SetID(long id);
	void SetName(string name);
	void SetAge(int age);
	void SetAddress(string address);

private:
	long m_id;
	string m_name;
	int m_age;
	string m_address;
};
