# Polymorphism (by duck typing)
# basically try to fit something forcefully
    # even though they don't belong there, just because you can
# "if it looks like a duck, quacks like a duck, it must be a duck"

class Animal:
    alive = True

class Dog(Animal):              # child (sub) class1 (inheritance)
    def speak(self):
        print("WOOF!")

class Cat(Animal):              # child (sub) class2 (inheritance)
    def speak(self):
        print("YAPAPA MMMM")

class Car:

    alive = False               # added this to match with animal's child classes

    def speak(self):            # even though the car makes sound (DON'T SPEAK)
        print("HONK!")          # added SPEAK method instead of SOUND to fit with animals

animals = [Dog(), Cat(), Car()] 

for animal in animals:

    animal.speak()
    print(animal.alive)