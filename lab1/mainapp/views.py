from django.shortcuts import render

# Create your views here.
from django.conf import settings
import rest_framework
from rest_framework import viewsets
from .models import Toy
from .serializers import ToySerializer

class ToyViewSet(viewsets.ModelViewSet):
    """
    ViewSet для выполнения CRUD+List операций с игрушками
    """
    queryset = Toy.objects.all()           # какие объекты брать из базы
    serializer_class = ToySerializer       # какой сериализатор использовать
