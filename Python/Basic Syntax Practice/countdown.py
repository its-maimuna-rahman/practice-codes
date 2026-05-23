import time

my_time = int(input("Enter time in seconds = "))

for x in range(my_time, 0, -1) :
    seconds = x % 60
    minutes = int(x / 60)
    hours = int(x / 3600)

    print(f"{hours : 03} :{minutes : 03} :{seconds : 03}")
    time.sleep(1)

print("TIME UP!!")    