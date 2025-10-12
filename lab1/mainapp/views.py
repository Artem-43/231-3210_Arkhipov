from django.shortcuts import render
from django.views.decorators.csrf import csrf_exempt
from django.utils.decorators import method_decorator

# Create your views here.
from django.conf import settings
import rest_framework
from rest_framework import viewsets
from .models import Toy
from .serializers import ToySerializer

# @method_decorator(csrf_exempt, name='dispatch')     
class ToyViewSet(viewsets.ModelViewSet):
    """
    ViewSet для выполнения CRUD+List операций с игрушками
    """
    queryset = Toy.objects.all()           # какие объекты брать из базы
    serializer_class = ToySerializer       # какой сериализатор использовать



    
