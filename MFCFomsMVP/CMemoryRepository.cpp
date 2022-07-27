#include "pch.h"
#include "CMemoryRepository.h"

void CMemoryRepository::SaveUser(CUser user)
{
    m_listMemoryStorage.push_back(user);
}

CUser CMemoryRepository::GetUser(long id)
{
    CUser* user = new CUser();

    for each (auto i in m_listMemoryStorage)
    {
        if (id == i.GetID())
        {
           /* user.SetID(i.GetID());
            user.SetName(i.GetName());
            user.SetAge(i.GetAge());
            user.SetAddress(i.GetAddress());*/

            return i;
        }
    }
    return *user;
}

list<CUser> CMemoryRepository::GetAllUsers()
{
    return m_listMemoryStorage;
}
