// #ifndef TOYREQUESTER_H
// #define TOYREQUESTER_H

// #include <QObject>
// #include <QNetworkAccessManager>
// #include <QNetworkReply>
// #include "toy.h"

// class ToyRequester : public QObject
// {
//     Q_OBJECT
// public:
//     explicit ToyRequester(QObject *parent = nullptr);
//     void fetchToys();  // выполняет GET-запрос

// private slots:
//     void onReplyFinished(QNetworkReply *reply);

// private:
//     QNetworkAccessManager *manager;
// };
// #endif // TOYREQUESTER_H

#ifndef TOYREQUESTER_H
#define TOYREQUESTER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "toy.h"

class ToyRequester : public QObject
{
    Q_OBJECT
public:
    static ToyRequester* instance(QObject *parent = nullptr) {
        static ToyRequester* _instance = nullptr;
        if (!_instance) {
            _instance = new ToyRequester(parent);
        }
        return _instance;
    }

    void fetchToys();
    void fetchToy(int id);
    void addToy(QString name, QString price, QString category, QString size);
    void deleteToy(int id);
    void updateToy(QString id, QString name, QString price, QString category, QString size);


private slots:
    void onReplyFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
    explicit ToyRequester(QObject *parent = nullptr);
};

#endif // TOYREQUESTER_H
