#pragma once
#include "IUserFormRepository.h"

class CMemoryRepository : public IUserFormRepository
{
public:
	list<CUser> m_listMemoryStorage;

	// IUserFormRepository��(��) ���� ��ӵ�
	virtual void SaveUser(CUser user) override;

	virtual CUser GetUser(long id) override;

	virtual list<CUser> GetAllUsers() override;

};