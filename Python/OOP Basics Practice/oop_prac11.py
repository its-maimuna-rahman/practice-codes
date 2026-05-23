# Instance method - default method (works for ONE OBJECT of a class)
    # works with attributes that are INSIDE OF THE CONSTRUCTOR

# Class method - works for WHOLE CLASS (like employee count etc)
    # works with attributes that are OUTSIDE OF THE CONSTRUCTOR

# Static method - regular functions that happen to live inside a class. 
        # They don’t know anything about self (object) or cls (class)
        # it's like regular user defined function


class Student:

    count = 0
    total_gpa = 0

    def __init__(self, name, gpa):
        self.name = name
        self.gpa = gpa
        Student.count += 1
        Student.total_gpa += gpa
        
    def get_info(self):                     # INSTANCE METHOD
        return f"{self.name} {self.gpa}"

    @classmethod                            # CLASS METHOD
    def get_count(cls):
        return f"Total number of students: {cls.count}"

    @classmethod                            # CLASS METHOD
    def avg_gpa(cls):
        if cls.count == 0:
            return "error."
        return f"avg gpa = {cls.total_gpa / cls.count:.4f}"

    @staticmethod                           # STATIC METHOD
    def is_passing(gpa):
        return gpa >= 2.0                   # This doesn't need 'self' or 'cls'
                                            # It just performs a logic check on the input provided
        

# Creating instances
student1 = Student("meow", 3.8)
student2 = Student("meowmeow", 1.5)         # Let's give this one a low GPA for testing
student3 = Student("meowmeowna", 3.99)

# Printing Class Method outputs
print(Student.get_count())
print(Student.avg_gpa())

# Printing Static Method outputs
# Note: You can call it on the Class itself or an instance
print(f"Is {student1.name} passing? {Student.is_passing(student1.gpa)}")
print(f"Is {student2.name} passing? {Student.is_passing(student2.gpa)}")