print("===== CALCULATOR =====")
print()

a = float(input("enter first number = "))
b = float(input("enter second number = "))
op = input("enter basic mathematical operation (+,-,*,/,%): ")
print()

result = None

if op == "+" :
    result = a + b
    
elif op == "-" :
    result = a - b
    
elif op == "*" :
    result = a * b
    
elif op == "/" :
    
    if b == 0 :
        print("Invalid input for b")
    else:
        result = a / b
        
elif op == "%" :
    result = a % b

else :
    print("invalid operation input")

if result is not None :
    print(f"result = {result : .4f}")
else : 
    print("error")    

print()    