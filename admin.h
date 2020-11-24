#ifndef ADMIN_H
#define ADMIN_H

#include <string>

namespace model {
    class Admin
    {
    private:
        std::string name;
    public:
        Admin(std::string name);
        std::string getName();
    };
}

#endif // ADMIN_H
