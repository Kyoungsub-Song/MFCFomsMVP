#pragma once
#include "pch.h"
#include "IUserFormView.h"
#include "IUserFormRepository.h"

class UserFormPresenter
{
public:
	UserFormPresenter();
	~UserFormPresenter();

	void SetIUserForm(IUserFormView* i_IUserForm);
	void SetIUserFormRepository(IUserFormRepository* i_IUserFormRepository);
	void UpdateUser();
	void UpdateUserListView();
	void SaveUser();
	

protected:
private:
	IUserFormView* m_IUserForm;
	IUserFormRepository* m_IUserFormRepository;
};