#include "toyparser.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

Toy parseToyFromJson(const QByteArray &data)
{
    Toy toy;
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isObject()) return toy;

    QJsonObject obj = doc.object();
    toy.setId(obj["id"].toInt());
    toy.setName(obj["name"].toString());
    toy.setPrice(obj["price"].toDouble());
    toy.setCategory(obj["category"].toString());
    toy.setSize(obj["size"].toString());

    return toy;
}

QList<Toy> parseToyListFromJson(const QByteArray &data)
{
    QList<Toy> toys;
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isArray()) return toys;

    QJsonArray arr = doc.array();
    for (const QJsonValue &value : arr)
    {
        if (value.isObject())
        {
            QJsonObject obj = value.toObject();
            Toy toy;
            toy.setId(obj["id"].toInt());
            toy.setName(obj["name"].toString());
            toy.setPrice(obj["price"].toDouble());
            toy.setCategory(obj["category"].toString());
            toy.setSize(obj["size"].toString());
            toys.append(toy);
        }
    }
    return toys;
}
