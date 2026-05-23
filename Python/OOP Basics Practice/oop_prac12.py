# @PROPERTY decorator is used to define a method in a class
    # that can be accessed like an attribute (variable) instead of a method.

# Keep ENCAPSULATION
# Getter → reads attribute value
# Setter → controls & validates setting attribute value (checks input validation)
# Deleter → controls deletion of attribute

class Rectangle:

    def __init__(self, width, height):
        self._width = width
        self._height = height

    # -------- WIDTH --------
    @property                               # getter
    def width(self):
        return f"{self._width:.1f} cm"

    @width.setter                           # setter
    def width(self, new_width):
        if new_width > 0:
            self._width = new_width
        else:
            print("Width must be greater than zero")

    @width.deleter                          # deleter
    def width(self):
        print("Deleting width...")
        # DEBUG: Instead of 'del self._width', we set it to 0 
        # so the next print() statement doesn't crash.
        self._width = 0

    # -------- HEIGHT --------
    @property
    def height(self):
        return f"{self._height:.1f} cm"

    @height.setter
    def height(self, new_height):
        if new_height > 0:
            self._height = new_height
        else:
            print("Height must be greater than zero")

    @height.deleter
    def height(self):
        print("Deleting height...")
        # DEBUG: Setting to 0 to keep the attribute alive
        self._height = 0


# -------- CREATE OBJECT --------
rectangle = Rectangle(3, 4)

print(rectangle.width)
print(rectangle.height)

rectangle.width = -1    # it will give error msg and won't change the width from 3 to -1
rectangle.height = 20

print(rectangle.width)
print(rectangle.height)

# These calls trigger the @deleter methods
del rectangle.width
del rectangle.height

# Now these will print "0.0 cm" instead of throwing an AttributeError
print(rectangle.width)
print(rectangle.height)