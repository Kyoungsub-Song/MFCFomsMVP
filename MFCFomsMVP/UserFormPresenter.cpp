#include "pch.h"
#include "UserFormPresenter.h"

UserFormPresenter::UserFormPresenter()
{
}

UserFormPresenter::~UserFormPresenter()
{
}

void UserFormPresenter::SetIUserForm(IUserFormView* i_IUserForm)
{
	m_IUserForm = i_IUserForm;
	m_IUserForm->SetPresenter(this);
}

void UserFormPresenter::UpdateUser()
{
}

void UserFormPresenter::UpdateUserListView()
{
}

void UserFormPresenter::SaveUser()
{
	
}