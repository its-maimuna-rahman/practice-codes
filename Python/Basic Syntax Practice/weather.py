# Write a program that reads temperature, humidity, and wind speed,
# and uses nested if statements to determine the weather condition.
# Rules:
 #If temp > 35
   #  If humidity > 70 → “Hot and Humid”
   # Else → “Hot and Dry”
# Else if temp between 20–35
   # If wind > 30 → “Pleasant but Windy
   # Else → “Pleasant”
# Else if temp < 20
   # If humidity > 80 → “Cold and Foggy”
   # Else → “Cold and Clear”


temp = float(input("enter temperature = "))
humid = float(input("enter humidity = "))
wind = float(input("enter wind speed = "))
  
if temp > 35 : 

    if humid > 70 :
        print("Hot and Humid")
    else : 
        print("Hot and Dry")

elif 20 <= temp <= 35 :

    if wind > 30 :
      print("Pleasant but Windy")
    else :
      print("plesant")
    
elif temp < 20 :

    if humid > 80 :
      print("cold and foggy")
    else :
      print("cold and clear")
    
else :
    print("invalid input for variables")
  
