from django.db import models

# Create your models here.

class Toy(models.Model):
    id = models.AutoField(primary_key=True)  # уникальный идентификатор
    name = models.CharField(max_length=100, verbose_name="Название")
    price = models.DecimalField(max_digits=8, decimal_places=2, verbose_name="Цена")

    CATEGORY_CHOICES = [
        ('plush', 'Плюшевые'),
        ('edu', 'Обучающие'),
        ('electronic', 'Электронные'),
        ('puzzle', 'Пазлы'),
        ('outdoor', 'Уличные'),
    ]
    category = models.CharField(max_length=20, choices=CATEGORY_CHOICES, verbose_name="Категория")

    SIZE_CHOICES = [
        ('small', 'Маленький'),
        ('medium', 'Средний'),
        ('large', 'Большой'),
    ]
    size = models.CharField(max_length=10, choices=SIZE_CHOICES, verbose_name="Размер")

    class Meta:
        verbose_name = "Игрушка"
        verbose_name_plural = "Игрушки"

    def __str__(self):
        return f"{self.name} ({self.get_category_display()}, {self.get_size_display()})"