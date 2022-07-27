#include "pch.h"
#include "UserFormPresenter.h"
#include "CUser.h"

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

void UserFormPresenter::SetIUserFormRepository(IUserFormRepository* i_IUserFormRepository)
{
	m_IUserFormRepository = i_IUserFormRepository;
}

void UserFormPresenter::UpdateUser()
{
}

void UserFormPresenter::UpdateUserListView()
{
	list<CUser> allUserLIst = m_IUserFormRepository->GetAllUsers();
	
	m_IUserForm->SetUserListBox(allUserLIst);
}

void UserFormPresenter::SaveUser()
{
	CUser user;
	user.SetName(m_IUserForm->GetName());
	user.SetAge(m_IUserForm->GetAge());
	user.SetAddress(m_IUserForm->GetAddress());

	m_IUserFormRepository->SaveUser(user);

	UpdateUserListView();
}