# Vehicle Rental System.

from abc import ABC, abstractmethod

class Vehicle(ABC):

    @abstractmethod                                 # Abstract method
    def vehicle_type(self):
        pass

    @abstractmethod
    def rental_rate(self):
        pass


class Car(Vehicle):
    base_rate = 2000                                # Class attribute 
    car_count = 0

    def __init__(self, car_name, rental_hr):        # Constructor
        self.car_name = car_name                    # Attributes
        self.rental_hr = rental_hr
        Car.car_count += 1

    @classmethod                                    # Class method
    def total_car(cls):
        return f"Total cars = {cls.car_count}"


class FuelCar(Car):                                 # Hierarchical inheritance

    fuel_list = []

    def __init__(self, car_name, rental_hr, fuel_amount):
        Car.__init__(self, car_name, rental_hr)
        self.fuel_amount = fuel_amount
        FuelCar.fuel_list.append(self.car_name)

    def vehicle_type(self):                 
        return f"A Fuel Car, named {self.car_name} has been rented."

    def rental_rate(self):                          # Instance method
        return self.base_rate + (1.8 * self.rental_hr)

    def list_fuel_car(self):
        return [f"{car}" for car in self.fuel_list]


class ElectricCar(Car):

    electric_list = []

    def __init__(self, car_name, rental_hr, battery_percentage):
        Car.__init__(self, car_name, rental_hr)
        self.battery_percentage = battery_percentage
        ElectricCar.electric_list.append(self.car_name)

    def vehicle_type(self):
        return f"An Electric Car, named {self.car_name} has been rented."

    def rental_rate(self):
        return self.base_rate + (1.5 * self.rental_hr)

    def list_electric_car(self):
        return [f"{car}" for car in self.electric_list]


# --- taking user input ---

print()
all_cars = []

print("Enter car details. Type 'done' as car name to stop.\n")

while True:

    car_name = input("Enter car name: ")
    if car_name.lower() == "done":
        break

    car_type = input("Enter car type (fuel / electric): ").lower()
    rental_hr = int(input("Enter rental hours: "))

    if car_type == "fuel":
        while True:
            try:
                fuel_amount = float(input("Enter fuel amount (max 40 liters): "))

                if 0 < fuel_amount <= 40:
                    break
                else:
                    print("invalid fuel amount input.")
            except ValueError:
                print("invalid fuel amount input.")           
        
        car = FuelCar(car_name, rental_hr, fuel_amount)

    elif car_type == "electric":
        while True:
            try:
                battery_percentage = float(input("Enter battery percentage: "))

                if 0 < battery_percentage <= 100:
                    break
                else:
                    print("invalid battrery percentage input.")
            except ValueError:
                print("invalid battery percentage input.")
        
        car = ElectricCar(car_name, rental_hr, battery_percentage)

    else:
        print("Invalid car type, skipping.\n")
        continue

    all_cars.append(car)
    print(f"{car_name} added successfully!\n")


# --- displaying all info ---

print("\n========== ALL CAR DETAILS ==========")

for car in all_cars:
    print(car.vehicle_type())
    print(f"  Rental Cost : {car.rental_rate()}")

    if isinstance(car, FuelCar):
        print(f"  Fuel Amount : {car.fuel_amount} liters")

    elif isinstance(car, ElectricCar):
        print(f"  Battery     : {car.battery_percentage}%")

    print()

print(f"Total cars created  : {Car.car_count}\n")

print("-------- Fuel Cars list -------")
for car in FuelCar.fuel_list:
    print(car)
print() 

print("------ Electric Cars list -----")
for car in ElectricCar.electric_list:
    print(car)
print()