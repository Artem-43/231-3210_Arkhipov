from rest_framework import serializers
from .models import Toy

class ToySerializer(serializers.ModelSerializer):
    class Meta:
        model = Toy
        # перечисляем поля, которые будут попадать в JSON
        fields = '__all__'
