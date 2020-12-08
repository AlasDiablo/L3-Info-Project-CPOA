#ifndef DATADB_H
#define DATADB_H

#include <QSqlDatabase>
#include "data.h"

namespace model {
    class DataDB : public Data
    {
    private:
        QSqlDatabase db;
    public:
        DataDB();
    };
}
#endif // DATADB_H
