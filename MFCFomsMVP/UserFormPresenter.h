#pragma once
#include "pch.h"
#include "IUserFormView.h"

class UserFormPresenter
{
public:
	UserFormPresenter();
	~UserFormPresenter();

	void SetIUserForm(IUserFormView* i_IUserForm);
	void UpdateUser();
	void UpdateUserListView();
	void SaveUser();
	

protected:
private:
	IUserFormView* m_IUserForm;
};