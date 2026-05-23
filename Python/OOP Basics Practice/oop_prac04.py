# Abstact class
# Abstract method = method without body
# It forces child classes to implement their own version (like car and cycle have different method to stop)

from abc import ABC, abstractmethod

class Vehicle(ABC):                # Abstract class

    @abstractmethod                # Abstract method
    def go(self):
        pass

    @abstractmethod                # Abstract method
    def stop(self):
        pass


class Car(Vehicle):                # child class
                                   # MUST include ALL the abstract METHODS of abstract class
    def go(self):
        print("you drive the car")

    def stop(self):
        print("you stop the car")


class Cycle(Vehicle):              # child class
                                   # MUST include ALL the abstract METHODS of abstract class
    def go(self):
        print("you pedal the cycle")

    def stop(self):
        print("you apply brake on the cycle")

car = Car()
car.go()
car.stop()

cycle = Cycle()
cycle.go()
cycle.stop()
