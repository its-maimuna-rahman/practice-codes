# Composition (classes are not connected by inheritance and pass data through CONSTRUCTOR)
# CAR OWNS engine and wheel
# The Car class is independent, but:
        # The Car object depends on Engine and Wheel objects
        # Car cannot exist properly without them
# "owns a" relationship. if you destroy a CAR, the ENGINE and WHEELS of it will also get destroyed   
# A House has Rooms. If you demolish the house, the rooms will be destroyed too

class Engine:
    def __init__(self, horse_power):
        self.horse_power = horse_power


class Wheel:
    def __init__(self, size):
        self.size = size

class Car:
    def __init__(self, make, model, horse_power, wheel_size):
        self.make = make
        self.model = model
        self.engine = Engine(horse_power)                            # composition
        self.wheels = [Wheel(wheel_size) for wheel in range(4)]      # composition

    def display_car(self):
        return f"{self.make} {self.model} : {self.engine.horse_power} Hp and {self.wheels[0].size} inches wheels"


car1 = Car("Ford", "Mustang", 500, 18)
print(car1.display_car())

car2 = Car("Toyota", "Land Cruser", 680, 19)
print(car2.display_car())
    
