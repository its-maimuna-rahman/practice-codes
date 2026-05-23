# OOP basics (Class, Object, Constructor, Attritute, Method)

class Car :         # class - holds the design/structure of objects (SAME for car1, car2, ...)

    year = 2025     # class variable - the variable which is same for all objects of this class
                    # all cars are made in year 2025
    total_car = 0               
    base_price = 200000

    def __init__(self, model, brand, for_sale) :    # constructor - structure, that holds instance variables
        self.model = model         
        self.brand = brand          # all these inside the constucture are instance variables (ATTRIBUTES)
        self.for_sale = for_sale    # they are different for every obj. (DIFFERENT for car1, car2, ...)
        self.price = Car.base_price # setting a default price attribute
        Car.total_car += 1          # keeps track of the total car (used CLASS NAME instead of SELF)

    def drive(self) :
        print(f"you drive the {self.brand}")        # these are METHODS (works like functions)
        
    def stop(self) :
        print(f"you stop the {self.brand}")
        
    def made(self) :
        print(f"the car {self.brand} was made in {self.year}")

    def get_price(self) :
        return (self.price * 2)

# --- USER INPUT SECTION ---

print("--- Enter Details for Car 1 ---")
u_brand = input("Enter Brand: ")
u_model = input("Enter Model: ")
u_sale = input("Is it for sale? (yes/no): ").lower() == "yes"

car1 = Car(u_model, u_brand, u_sale)

print("\n--- Enter Details for Car 2 ---")
u_brand2 = input("Enter Brand: ")
u_model2 = input("Enter Model: ")
u_sale2 = input("Is it for sale? (yes/no): ").lower() == "yes"

car2 = Car(u_model2, u_brand2, u_sale2)

# --- OUTPUT SECTION ---

print("-" * 40)
print(f"Car 1: {car1.brand} {car1.model} | For Sale: {car1.for_sale}")
print(f"Car 2: {car2.brand} {car2.model} | For Sale: {car2.for_sale}")

print(f"\nTotal cars created: {Car.total_car}")

print("\nTesting methods for Car 1:")
car1.drive()
car1.made()

# class variable can be changed for an/more than 1 obj if needed
car1.price = 300000         
print(f"Updated price for {car1.brand}: {car1.get_price()}")

print("\nObject Data Dictionary:")
print(car1.__dict__)    # dict dunder give all info about an object