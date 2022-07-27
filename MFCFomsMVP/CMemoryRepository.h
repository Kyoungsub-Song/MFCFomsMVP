#pragma once
#include "IUserFormRepository.h"

class CMemoryRepository : public IUserFormRepository
{
public:
	list<CUser> m_listMemoryStorage;

	// IUserFormRepository을(를) 통해 상속됨
	virtual void SaveUser(CUser user) override;

	virtual CUser GetUser(long id) override;

	virtual list<CUser> GetAllUsers() override;

};