#include <QCoreApplication>
#include "toyrequester.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ToyRequester requester;
    requester.fetchToys();

    return a.exec();
}
