# polymorphism (by inheritance)
# here, pizza has many FORMS :
    # it is a pizza itself, it is circular, that's why circle
    # A circle is a shape, so it is also a shape 

from abc import ABC, abstractmethod

class Shape(ABC):
    
    @abstractmethod
    def area(self):
        pass

class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius
        
    def area(self):
        return (3.14159 * self.radius * self.radius)

class Square(Shape):
    def __init__(self, side):
        self.side = side
        
    def area(self):
        return (self.side * self.side)   
            
class Triangle(Shape):
    def __init__(self, base, height):
        self.base = base
        self.height = height
        
    def area(self):
        return (0.5 * self.height * self.base)

class Pizza(Circle):                       # so pizza is circular and circle is a shape
    def __init__(self, topping, radius):   # so pizza will inherit both from circle and shape (chain)
        super().__init__(radius)
        self.topping = topping   

shapes = [Circle(5), Square(6), Triangle(4, 5), Pizza("chicken", 15)]

for shape in shapes :
    print(f"area = {shape.area()} cm^2")