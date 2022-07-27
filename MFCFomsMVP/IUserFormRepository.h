#pragma once
#include"CUser.h"

#include <list>

using namespace std;

class IUserFormRepository
{
public:
	virtual void SaveUser(CUser user) = 0;
	virtual CUser GetUser(long id) = 0;
	virtual list<CUser> GetAllUsers() = 0;
};