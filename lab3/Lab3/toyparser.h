#ifndef TOYPARSER_H
#define TOYPARSER_H

#include <QByteArray>
#include <QList>
#include "toy.h"

// десериализация одного объекта
Toy parseToyFromJson(const QByteArray &data);

// десериализация массива объектов
QList<Toy> parseToyListFromJson(const QByteArray &data);

#endif // TOYPARSER_H
