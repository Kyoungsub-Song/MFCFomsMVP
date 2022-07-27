#include "pch.h"
#include "CUser.h"

long CUser::GetID()
{
    return m_id;
}

string CUser::GetName()
{
    return m_name;
}

int CUser::GetAge()
{
    return m_age;
}

string CUser::GetAddress()
{
    return m_address;
}

void CUser::SetID(long id)
{
    m_id = id;
}

void CUser::SetName(string name)
{
    m_name = name;
}

void CUser::SetAge(int age)
{
    m_age = age;
}

void CUser::SetAddress(string address)
{
    m_address = address;
}
