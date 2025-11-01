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
    explicit ToyRequester(QObject *parent = nullptr);
    void fetchToys();  // выполняет GET-запрос

private slots:
    void onReplyFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
};

#endif // TOYREQUESTER_H
