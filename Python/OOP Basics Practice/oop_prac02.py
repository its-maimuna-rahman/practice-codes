# OOP (Inheritance from 1 Class)

class Animal:                   # parent (super) class
    def __init__(self, name):
        self.name = name
        self.is_alive = True

    def eat(self):
        print(f"{self.name} is eating.")

    def sleep(self):
        print(f"{self.name} is sleeping")


class Dog(Animal):              # child (sub) class1 (inheritance)
    def speak(self):
        print("WOOF!")

class Cat(Animal):              # child (sub) class2 (inheritance)
    def speak(self):
        print("YAPAPA MMMM")

class Cow(Animal):              # child (sub) class3 (inheritance)
    def speak(self):
        print("MUUUUU") 

d1 =  Dog("scooby")
c1 = Cat("meow")
co1 = Cow("mickey")  

# Using the methods and attributes that are inherited from the parent class
print(c1.name)
print(c1.is_alive)
c1.eat()
c1.sleep()
print()

# Using the methods that are NOT inheried from the parent class
c1.speak()
d1.speak()
co1.speak()
