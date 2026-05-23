# Miltiple and multilevel inheritance

class Animal:                                    # parent of parents' classes (like chain)
                                                 # multilevel inheritance
    def __init__(self, name):
        self.name = name

    def eat(self):
        print(f"this {self.name} is eating")

    def sleep(self):
        print(f"this {self.name} is sleeping")    


class Prey(Animal):                              # parent class
    def flee(self):
        print(f"this {self.name} is fleeing")

class Predator(Animal):                          # parent class
    def hunt(self):
        print(f"this {self.name} is hunting")

class Rabbit(Prey):                         # child class
    pass

class Hawk(Predator):                       # child class
    pass

class Fish(Prey, Predator):                 # child class (2 parents)
    pass                                    # multiple inheritance


rabbit = Rabbit("Tom")
hawk = Hawk("Jerry")
fish = Fish("Dory")

rabbit.flee()       # hunt method won't work
hawk.hunt()         # flee method won't work
fish.hunt()         # both method will work
fish.flee()         # as fish inherited both parent class

# testing root parent (animal) methods if they work in child classes bec of chain
print()
rabbit.sleep()
fish.eat()