#include "toyrequester.h"
#include "toyparser.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>
#include <Qstring>
#include <QJsonObject>
ToyRequester::ToyRequester(QObject *parent)
    : QObject(parent)
{
    manager = new QNetworkAccessManager(this);

    // Подключаем сигнал завершения запроса к слоту
    connect(manager, &QNetworkAccessManager::finished,
            this, &ToyRequester::onReplyFinished);
}


// Запрос ко всем элементам
void ToyRequester::fetchToys()
{
    QUrl url("http://localhost:8000/toy/");
    QNetworkRequest request(url);
    manager->get(request); // Асинхронный GET-запрос
}


// Запрос к элементу по id
void ToyRequester::fetchToy(int id)
{
    QString path = "http://localhost:8000/toy/" + QString::number(id) + "/";
    QUrl url(path);
    QNetworkRequest request(url);
    manager->get(request); // Асинхронный GET-запрос
}


// добавить элемент
void ToyRequester::addToy(QString name, QString price, QString category, QString size)
{
    QUrl url("http://127.0.0.1:8000/toy/");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Формируем JSON
    QJsonObject json;
    json["name"] = name;
    json["price"] = price.toDouble();     // Число, не строка!
    json["category"] = category;          // "plush", "edu", "outdoor" и т.д.
    json["size"] = size;                  // "small", "medium", "large"

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    qDebug() << "POST data:" << data;     // Чтобы видеть, что реально отправляется

    manager->post(request, data);
}

// удаление элемента
void ToyRequester::deleteToy(int id)
{
    QString path = "http://localhost:8000/toy/" + QString::number(id) + "/";
    QUrl url(path);
    QNetworkRequest request(url);

    manager->deleteResource(request); // DELETE-запрос
}

// Изменение элемента
void ToyRequester::updateToy(QString id, QString name, QString price, QString category, QString size)
{
    QString path = "http://127.0.0.1:8000/toy/" + id + "/";
    QUrl url(path);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["name"] = name;
    json["price"] = price.toDouble();
    json["category"] = category;
    json["size"] = size;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    qDebug() << "PUT data:" << data;

    manager->put(request, data);
}

// void ToyRequester::onReplyFinished(QNetworkReply *reply)
// {
//     if (!reply) return;
//     QByteArray data = reply->readAll();
//     QList<Toy> toys = parseToyListFromJson(data);

//     qDebug() << "Получено игрушек:" << toys.size();
//     for (const Toy &t : toys)
//     {
//         qDebug() << t.id() << t.name() << t.price()
//         << t.category() << t.size();
//     }

//     reply->deleteLater();
// }


void ToyRequester::onReplyFinished(QNetworkReply *reply)
{
    if (!reply) return;

    QByteArray data = reply->readAll();
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "Ошибка парсинга JSON:" << parseError.errorString();
        qWarning() << "Ответ сервера:" << data;
        reply->deleteLater();
        return;
    }

    QList<Toy> toys;

    // Проверяем тип корневого элемента
    if (doc.isArray()) {
        // Несколько объектов
        toys = parseToyListFromJson(data);
    }
    else if (doc.isObject()) {
        // Один объект
        Toy toy = parseToyFromJson(data);
        toys.append(toy);
    }
    else {
        qWarning() << "Неожиданный формат JSON";
    }

    // Отладочный вывод
    qDebug() << "Получено игрушек:" << toys.size();
    for (const Toy &t : toys) {
        qDebug() << t.id() << t.name() << t.price()
        << t.category() << t.size();
    }

    reply->deleteLater();
}

