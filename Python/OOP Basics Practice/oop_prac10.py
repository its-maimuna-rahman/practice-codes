# Nested class (a class under a class)
# to avoid name conflict (same name for diff class)
# to organize the code

class Company:
 
    class Employee:                           # this is the detail of ONE employess

        def __init__(self, name, position):
            self.name = name
            self. position = position

        def get_details(self):
            return f"{self.name} {self.position}"    


    def __init__(self, company_name):
        self.company_name = company_name
        self.employees = []

    def add_employee(self, name, position):    # here adding ONE/MANY employees for the COMPANY
        
        new_employee = self.Employee(name, position)
        self.employees.append(new_employee)

    def list_employee(self):
        return[employee.get_details() for employee in self.employees]

company = Company("FC Barcelona")

company.add_employee("Pedri", "midfielder")
company.add_employee("Lewandowski", "stricker")
company.add_employee("Gavi", "midfielder")

for employee in company.list_employee() :
    print(employee)