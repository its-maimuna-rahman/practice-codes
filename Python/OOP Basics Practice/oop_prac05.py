# SUPER - when child classes have their own contructor
        # we use super to call CONSTRUCTOR of parent class
        # then we add child classes' OWN ATTRIBUTES in THEIR OWN CONSTRUCTOR
        
# child constuctor = parent constructor (super) + own attributes

class Shape:
    def __init__(self, color, is_filled):
        self.color = color
        self.is_filled = is_filled
    
    def describe(self):
        print(f"It is {self.color} color and {'filled' if self.is_filled else 'not filled'}")

class Circle(Shape):
    def __init__(self, color, is_filled, radius):
        super().__init__(color, is_filled)      # calling parent's contructor under child's constructor
        self.radius = radius
        
    def area(self):
        print(f"It is a circle with the area of {self.radius * self.radius * 3.14159}")
        super().describe()                      # calling patent's method under child's method

class Square(Shape):
    def __init__(self, color, is_filled, width):
        super().__init__(color, is_filled)
        self.width = width
        
    def area(self):
        print(f"It is a square with the area of {self.width * self.width}") 
        super().describe()   
            
class Triangle(Shape):
    def __init__(self, color, is_filled, base, height):
        super().__init__(color, is_filled)
        self.base = base
        self.height = height
        
    def area(self):
        print(f"It is a triangle with the area of {0.5 * self.base * self.height}") 
        super().describe()   
            
c = Circle(color="red", is_filled=True, radius=5)            
            
s = Square(color="blue", is_filled=False, width=4) 

t = Triangle(color="black", is_filled=True, base=3, height=4)

print(c.color)
print(c.radius)
c.describe()
c.area()

print()
print(s.color)
print(s.width)
s.describe()
s.area()

print()
print(t.color)
print(t.base)
print(t.height)
t.describe()
t.area()