#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QSqlDatabase>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QNetworkAccessManager m_pnarn;

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

    std::cout << "Ok";
    return a.exec();
}
