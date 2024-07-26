import requests
# import pip._vendor.requests 
from pprint import pprint

API_Key='331274d7de0e7284ba83f54e728a9057'

city=input("Enter the city: ")
base_url="https://home.openweathermap.org/data/2.5/weather?appid=" + API_Key+"&q="+city
weather_data=requests.get(base_url).json()
pprint(weather_data)