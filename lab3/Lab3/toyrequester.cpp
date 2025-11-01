#include "toyrequester.h"
#include "toyparser.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

ToyRequester::ToyRequester(QObject *parent)
    : QObject(parent),
    manager(new QNetworkAccessManager(this))
{
    connect(manager, &QNetworkAccessManager::finished,
            this, &ToyRequester::onReplyFinished);
}

void ToyRequester::fetchToys()
{
    QUrl url("http://localhost:80/toy/");
    QNetworkRequest request(url);
    manager->get(request);
}

void ToyRequester::onReplyFinished(QNetworkReply *reply)
{
    QByteArray buffer = reply->readAll();
    QList<Toy> toys = parseToyListFromJson(buffer);

    qDebug() << "Получено игрушек:" << toys.size();
    for (const Toy &t : toys)
    {
        qDebug() << t.id() << t.name() << t.price()
        << t.category() << t.size();
    }

    reply->deleteLater();
}
