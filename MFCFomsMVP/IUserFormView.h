#pragma once
#include "framework.h"
#include "CUser.h"

#include <string>
#include <map>

using namespace std;

class UserFormPresenter;

class IUserFormView
{
public:
	virtual void SetUserListBox(map<long, CUser> data) = 0;
	virtual void SetName(string value) = 0;
	virtual string GetName() = 0;
	virtual long getSelectedUserID() = 0;

	virtual void SetAge(int value) = 0;
	virtual int GetAge() = 0;

	virtual void SetAddress(string value) = 0;
	virtual string GetAddress() = 0;
	virtual void SetPresenter(UserFormPresenter* presenter) = 0;
};
