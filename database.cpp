#include "database.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <qsqlerror.h>
#include <QtDebug>
#include <QFile>
#include <QDir>
#include "database.h"
#include <QFileInfo>

Database::Database(QWidget *paitent) : QWidget(paitent)
{

}

Database::~Database(){

}

bool Database::createConnection(bool fresh)
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName("paitents.db");

    if (!_db.open()) {
        return false;
    }

    QFileInfo check_file("paitents.db");
    //create database and load seed
    if(fresh || !check_file.exists())
    {
        QSqlQuery seed;

        if(!scriptExecHelper("Seed/paitents.seed.schema"))
        {
            qDebug() << seed.lastError();
        }
    }
    return  true;
}


//Helper to read a file and invoke sql commands ';' separated
//https://www.qtcentre.org/threads/27167-How-can-i-execute-a-database-script-within-Qt
bool Database::scriptExecHelper(QString path)
{
    qDebug() << QDir::currentPath();

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return  false;

    QTextStream in(&file);
    QString sql = in.readAll();
    QStringList sqlStatements = sql.split(';', QString::SkipEmptyParts);

    foreach(const QString& statement, sqlStatements)
    {
        if (statement.trimmed() != "")
        {
            QSqlQuery query;
            if (!query.exec(statement))
            {
                return false;
            }
        }
    }
    return true;
}
