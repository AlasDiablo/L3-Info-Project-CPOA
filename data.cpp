/**
 * @file data.cpp
 * @brief Data Class
 * @author Safyrus
 * @version 1.1
 */

#include "data.h"

model::Data::Data()
{
}

unsigned int model::Data::getUserSize()
{
    return users.size();
}

model::User* model::Data::getUser(int i)
{
    if(i < 0 || (unsigned)i >= users.size())
        return nullptr;
    return &users.at(i);
}

model::User* model::Data::getUser(std::string name)
{
    for(unsigned int i=0; i< users.size(); i++) {
        User *tmp = &users.at(i);
        if(tmp->getName().compare(name)==0)
        {
            return tmp;
        }
    }
    return nullptr;
}

std::vector<model::User> model::Data::getUser()
{
    return users;
}

unsigned int model::Data::getPCSize()
{
    return pcs.size();
}

model::PC* model::Data::getPC(int i)
{
    if(i < 0 || (unsigned)i >= pcs.size())
        return nullptr;
    return &pcs.at(i);
}

model::PC* model::Data::getPC(std::string name)
{
    for(unsigned int i=0; i< pcs.size(); i++) {
        PC *tmp = &pcs.at(i);
        if(tmp->getName().compare(name)==0)
        {
            return tmp;
        }
    }
    return nullptr;
}

std::vector<model::PC> model::Data::getPC()
{
    return pcs;
}

void model::Data::addUser(User u)
{
    users.push_back(u);
}

void model::Data::addPC(PC p)
{
    pcs.push_back(p);
}

void model::Data::removeUser(std::string name)
{
    for(unsigned int i=0; i< users.size(); i++) {
        model::User *tmp = &users.at(i);
        if(tmp->getName().compare(name)==0)
        {
            removeUser(i);
            break;
        }
    }
}

void model::Data::removePC(std::string name)
{
    for(unsigned int i=0; i< pcs.size(); i++) {
        PC *tmp = &pcs.at(i);
        if(tmp->getName().compare(name)==0)
        {
            removePC(i);
            break;
        }
    }
}

void model::Data::removeUser(int i)
{
    if(i < 0 || (unsigned)i >= users.size())
        return ;
    users.erase(users.begin()+i);
}

void model::Data::removePC(int i)
{
    if(i < 0 || (unsigned)i >= pcs.size())
        return ;
    pcs.erase(pcs.begin()+i);
}
