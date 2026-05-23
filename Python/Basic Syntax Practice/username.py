# username validity checker
# username must not be more than 15 characters
# username must not contain any spaces
# username must not contain any numbers

while True : 

    username = input("enter username = ")

    if len(username) > 15 :
        print("invalid username")
        
    elif not username.find(" ") == -1 :
        print("invalid username")

    elif not username.isalpha() :
        print("invalid username")

    else :
        print(f"\nWelcome {username}!!!!!!!!!!!!!!!!!!!!!\n")
        break