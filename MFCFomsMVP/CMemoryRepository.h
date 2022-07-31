#pragma once
#include "IUserFormRepository.h"
#include <map>

using namespace std;

class CMemoryRepository : public IUserFormRepository
{
public:
	
	void SaveUser(CUser user) override;
	virtual CUser GetUser(long id) override;
	virtual map<long, CUser> GetAllUsers() override;
	virtual CUser FindbyName(string name) override;
	virtual CUser FindbyID(long id) override;
	virtual void UpdateUser(CUser user) override;

private:
	long sequence = 0;
	map<long, CUser> m_mapMemoryStorage;
};