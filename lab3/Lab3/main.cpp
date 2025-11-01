// #include <QCoreApplication>
// #include "toyrequester.h"

// int main(int argc, char *argv[])
// {
//     QCoreApplication a(argc, argv);

//     ToyRequester requester;
//     requester.fetchToys();

//     return a.exec();
// }

#include <QCoreApplication>
#include "toyrequester.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ToyRequester* requester = ToyRequester::instance();

    requester->fetchToy(4);
    requester->addToy("Mishka","1001.11","puzzle","large");
    requester->deleteToy(128);
    requester->updateToy("996","Car","19299.12","electronic","large");
    requester->fetchToys();

    return a.exec();
}
