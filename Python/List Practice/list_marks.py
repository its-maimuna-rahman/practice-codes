def mark_print(marks) :

    if len(marks) ==  0:
        print("no marks in the list")

    else :
        for i in range(len(marks)):
            print(marks[i])    

def input_mark() :
    while True :
        x = int(input("enter marks : "))
        if x < 0 or x > 100:
            print("invalid mark input.")
        else:
            return x

def input_index(current_size) :

    while True :
        i = int(input("enter index of the mark : "))
        if i < 0 or i > current_size:
            print("invalid index input")
        else:
            return i

print()
while True :
    n = int(input("how many students? : "))
    if n < 0 :
        print("invalid student input.")
    else :
        break

marks = []

for i in range(n) :
    a = int(input("Enter marks : "))
    marks.append(a)
print()

while True:
    print()
    print("============= Menu =============")
    print("1. Print marks' list.")
    print("2. Add new marks")
    print("3. Remove a mark")
    print("4. Show highest & lowest")
    print("5. Count how many got a specific mark")
    print("6. Sort ascending")
    print("7. Sort descending")
    print("8. Reverse current list")
    print("9. Exit")
    choice = int(input("enter choice : "))

    if choice == 1 :
        print()
        print("1. print marks' list.")
        print("----------------------------------")
        mark_print(marks)

    elif choice == 2 :
        print()
        print("2. Add new marks")
        print("----------------------------------------")

        while True :    
            m1 = int(input("how many marks you want to add? : "))

            if m1 <= 0 :
                print("invalid input")
            else :
                break

        for i in range(m1):
            x1 = input_mark()
            i1 = input_index(len(marks))
            marks.insert(i1, x1)

        print()    
        print("Updated list:")
        mark_print(marks)

    elif choice == 3 :
        print()
        print("3. Remove a mark")
        print("----------------------------------------")

        while True :    
            m2 = int(input("how many marks you want to remove? : "))

            if m2 <= 0 or m2 > len(marks):
                print("invalid input")
            else :
                break

        for i in range(m2) :
            x1 = input_mark()
            if x1 in marks :
                marks.remove(x1)
            else :
                print("mark not found")

        print()        
        print("Updated list:")
        mark_print(marks)

    elif choice == 4 :
        print()
        print("4. Show highest & lowest")
        print("----------------------------------------")
        if len(marks) == 0 :
            print("no marks available")
        else :
            print("highest =", max(marks))
            print("lowest =", min(marks))

    elif choice == 5 :
        print()
        print("5. Count how many got a specific mark")
        print("----------------------------------------")
        x4 = input_mark()
        if x4 in marks :
            print(f"The mark {x4} appeared {marks.count(x4)} times.")
        else:
            print("the mark is not in the list")

    elif choice == 6 :
        print()
        print("6. Sort ascending")
        print("----------------------------------")
        marks.sort()
        mark_print(marks)

    elif choice == 7 :
        print()
        print("7. Sort descending")
        print("----------------------------------")
        marks.sort(reverse=True)
        mark_print(marks)

    elif choice == 8 :
        print()
        print("8. Reverse current list")
        print("----------------------------------")
        marks.reverse()
        mark_print(marks)

    elif choice == 9 :
        print()
        print("====== 9. Exit =====")
        print()
        break

    else :
        print()
        print("invalid choice.")
        print("----------------------------------")