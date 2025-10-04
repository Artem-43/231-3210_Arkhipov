import random, string, datetime
from .models import *
from django.db import transaction
import faker
from faker import Faker
from decimal import Decimal


fk = Faker()


def gentestdata():
    # try:
    with transaction.atomic():
        for i in range(1000):
            newToy = Toy()
            newToy.name = fk.name()
            newToy.price = Decimal(str(round(random.uniform(10, 1000), 2)))
            newToy.category = random.choice(('plush','edu','electronic','puzzle','outdoor'))
            newToy.size = random.choice(('small','medium','large'))
            newToy.save()
    # <<< тут заканчивается транзакция
    print('OK gentestdata()')
