#Create a shopping cart program:
#Ask user to enter product names (comma separated)
#Convert into list

# Logic Requirements
# Use extend() when adding multiple products
# Use copy() to create backup cart
# Use index() to replace product
# Use clear() to empty
# Use + to merge two carts
# Use slicing to show first 3 products only

# After backup is created:
# Modify original
# Show that backup is unchanged


def yes_no_input(prompt):
    while True:
        answer = input(prompt).strip().lower()
        if answer in ("yes", "no"):
            return answer
        print("Invalid input. Please enter 'yes' or 'no'.")


def print_list(x):
    if not x:
        print("(cart is empty)")
    for i in range(len(x)):
        print(f"  {i+1}. {x[i]}")

print()
products = input("Enter product names (comma separated): ")
product_list = products.split(",")

for i in range(len(product_list)):
    product_list[i] = product_list[i].strip()

backup_cart = []

print()
print("Initial cart:")
print_list(product_list)

while True:
    print()
    print("========= Menu =========")
    print("1. Show cart")
    print("2. Add product(s)")
    print("3. Remove product")
    print("4. Replace a product")
    print("5. Duplicate cart (backup copy)")
    print("6. Merge with another cart")
    print("7. Show first 3 products")
    print("8. Clear cart")
    print("9. Exit")

    while True:
        try:
            choice = int(input("Enter your choice: "))
            if 1 <= choice <= 9:
                break
            else:
                print("Please enter a number between 1 and 9.")
        except ValueError:
            print("Invalid input. Please enter a number.")

    if choice == 1:
        print()
        print("1. Show cart")
        print("----------------------------------")
        print_list(product_list)

    elif choice == 2:
        print()
        print("2. Add product(s)")
        print("----------------------------------")
        new_products = input("Enter product(s) to add (comma separated): ")
        new_list = [p.strip() for p in new_products.split(",") if p.strip()]
        if new_list:
            product_list.extend(new_list)
            print(f"Added: {', '.join(new_list)}")
            print("Updated cart:")
            print_list(product_list)
        else:
            print("No valid products entered.")

    elif choice == 3:
        print()
        print("3. Remove product")
        print("----------------------------------")
        if not product_list:
            print("Cart is empty.")
        else:
            print("Current cart:")
            print_list(product_list)
            remove_item = input("Enter product name to remove: ").strip()
            if remove_item in product_list:
                product_list.remove(remove_item)
                print(f"'{remove_item}' removed.")
                print("Updated cart:")
                print_list(product_list)
            else:
                print(f"'{remove_item}' not found in cart.")

    elif choice == 4:
        print()
        print("4. Replace a product")
        print("----------------------------------")
        if not product_list:
            print("Cart is empty.")
        else:
            print("Current cart:")
            print_list(product_list)
            old_item = input("Enter product name to replace: ").strip()
            if old_item in product_list:
                new_item = input(f"Enter new product to replace '{old_item}' with: ").strip()
                if new_item:
                    idx = product_list.index(old_item)
                    product_list[idx] = new_item
                    print(f"'{old_item}' replaced with '{new_item}'.")
                    print("Updated cart:")
                    print_list(product_list)
                else:
                    print("No replacement name entered.")
            else:
                print(f"'{old_item}' not found in cart.")

    elif choice == 5:
        print()
        print("5. Duplicate cart (backup copy)")
        print("----------------------------------")
        backup_cart = product_list.copy()
        print("Backup created successfully!")
        print("Backup cart:")
        print_list(backup_cart)

        print()
        test_item = input("Enter a test item to add to original (to prove backup is unchanged): ").strip()
        if test_item:
            product_list.append(test_item)
            print(f"\nOriginal cart (after adding '{test_item}'):")
            print_list(product_list)
            print("\nBackup cart (unchanged):")
            print_list(backup_cart)

            if yes_no_input("\nRemove test item from original? (yes/no): ") == "yes":
                product_list.remove(test_item)
                print(f"'{test_item}' removed. Cart restored.")

    elif choice == 6:
        print()
        print("6. Merge with another cart")
        print("----------------------------------")
        print("Current cart:")
        print_list(product_list)
        extra_products = input("Enter products for the second cart (comma separated): ")
        second_cart = [p.strip() for p in extra_products.split(",") if p.strip()]
        if second_cart:
            merged_cart = product_list + second_cart
            print("\nSecond cart:")
            print_list(second_cart)
            print("\nMerged cart:")
            print_list(merged_cart)

            if yes_no_input("\nApply merged cart as your current cart? (yes/no): ") == "yes":
                product_list = merged_cart
                print("Cart updated with merged items.")
            else:
                print("Merge cancelled. Cart unchanged.")
        else:
            print("No valid products entered for second cart.")

    elif choice == 7:
        print()
        print("7. Show first 3 products")
        print("----------------------------------")
        first_three = product_list[:3]
        if first_three:
            print("First 3 products:")
            print_list(first_three)
        else:
            print("Cart is empty.")

    elif choice == 8:
        print()
        print("8. Clear cart")
        print("----------------------------------")
        if yes_no_input("Are you sure you want to clear the cart? (yes/no): ") == "yes":
            product_list.clear()
            print("Cart cleared.")
        else:
            print("Clear cancelled.")

    elif choice == 9:
        print()
        print("====== Goodbye! ======")
        print()
        break