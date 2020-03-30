#ifndef DATABASE_H
#define DATABASE_H
#include <QWidget>
#include <QSqlDatabase>


class Database: public QWidget
{
    Q_OBJECT

private:
    QSqlDatabase_db;
public:
    explicit Database(QWedgit *paitents = nullptr);
    ~Database();

    void closeDatabase() {_db.close(); }
    bool createConnection(bool fresh);
    bool scriptExecHelper(QString path);
};

#endif // DATABASE_H
