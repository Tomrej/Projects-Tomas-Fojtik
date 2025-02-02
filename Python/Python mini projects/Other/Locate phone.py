import imp
import phonenumbers
from phonenumbers import geocoder
from phonenumbers import carrier

number = input("Your phonenumber:")

ch_number = phonenumbers.parse(number, "CH")    #State

print(geocoder.description_for_number(ch_number, "en"))

service_number = phonenumbers.parse(number, "RO")   #Provider 

print(carrier.name_for_number(service_number, "en"))