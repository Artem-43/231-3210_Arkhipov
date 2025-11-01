#ifndef TOY_H
#define TOY_H

#include <QString>

class Toy
{
public:
    Toy() = default;

    Toy(int id, const QString &name, double price,
        const QString &category, const QString &size)
        : m_id(id), m_name(name), m_price(price),
        m_category(category), m_size(size) {}

    // --- Геттеры ---
    int id() const { return m_id; }
    QString name() const { return m_name; }
    double price() const { return m_price; }
    QString category() const { return m_category; }
    QString size() const { return m_size; }

    // --- Сеттеры ---
    void setId(int id) { m_id = id; }
    void setName(const QString &name) { m_name = name; }
    void setPrice(double price) { m_price = price; }
    void setCategory(const QString &category) { m_category = category; }
    void setSize(const QString &size) { m_size = size; }

    // --- Возможные категории ---
    enum Category {
        Plush,
        Educational,
        Electronic,
        Puzzle,
        Outdoor
    };

    // --- Возможные размеры ---
    enum Size {
        Small,
        Medium,
        Large
    };

    // Преобразование строк в enum и обратно (по желанию)
    static QString categoryToString(Category c) {
        switch (c) {
        case Plush: return "plush";
        case Educational: return "edu";
        case Electronic: return "electronic";
        case Puzzle: return "puzzle";
        case Outdoor: return "outdoor";
        }
        return {};
    }

    static QString sizeToString(Size s) {
        switch (s) {
        case Small: return "small";
        case Medium: return "medium";
        case Large: return "large";
        }
        return {};
    }

private:
    int m_id{};
    QString m_name;
    double m_price{};
    QString m_category;
    QString m_size;
};

#endif // TOY_H
