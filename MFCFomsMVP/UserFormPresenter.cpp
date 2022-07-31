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
	CUser user = m_IUserFormRepository->FindbyName(m_IUserForm->GetName());

	user.SetName(m_IUserForm->GetName());
	user.SetAge(m_IUserForm->GetAge());
	user.SetAddress(m_IUserForm->GetAddress());

	m_IUserFormRepository->UpdateUser(user);
}

void UserFormPresenter::UpdateUserListView()
{
	map<long, CUser> allUserLIst = m_IUserFormRepository->GetAllUsers();
	
	m_IUserForm->SetUserListBox(allUserLIst);
}

void UserFormPresenter::SaveUser()
{
	CUser user;
	user.SetName(m_IUserForm->GetName());
	user.SetAge(m_IUserForm->GetAge());
	user.SetAddress(m_IUserForm->GetAddress());

	bool validate = ValidateDuplicationUser(user);
	if (validate == false)
	{
		m_IUserFormRepository->SaveUser(user);
	}
	else
	{
		m_IUserFormRepository->UpdateUser(user);
	}

	UpdateUserListView();
}

void UserFormPresenter::SelectItem()
{
	long id = m_IUserForm->getSelectedUserID() + 1;
	CUser user = m_IUserFormRepository->FindbyID(id);

	m_IUserForm->SetName(user.GetName());
	m_IUserForm->SetAge(user.GetAge());
	m_IUserForm->SetAddress(user.GetAddress());
}

bool UserFormPresenter::ValidateDuplicationUser(CUser user)
{
	CUser existUser = m_IUserFormRepository->FindbyName(user.GetName());

	bool result = user.GetName() == existUser.GetName() ? true : false;

	return result;
}
