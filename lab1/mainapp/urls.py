from django.contrib import admin
from django.urls import path, include
from rest_framework import routers
from rest_framework.routers import DefaultRouter
from .views import ToyViewSet

# создаём роутер
router = DefaultRouter()
# регистрируем ViewSet
router.register(r'toys', ToyViewSet, basename='toy')

# urlpatterns = [
#     path('', include(router.urls)),  # подключаем все маршруты из роутера
# ]


urlpatterns = [
    path('admin/', admin.site.urls),
    path('Toy', ToyViewSet.as_view({'get': 'list'})),  
    path('Toy/<pk>', ToyViewSet.as_view({'get': 'retrieve'})),    
    # path('Toy', ToyViewSet.as_view({'post': 'create'})),  
]
