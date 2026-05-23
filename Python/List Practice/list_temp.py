# Input: The user enters a sequence of temperature readings (e.g., 4.5, 4.8, ERROR, 5.2, 300, 4.9, None, 5.0).
# list and remove any non-numeric strings (like "ERROR" or "None").
# Outlier Detection: Any temperature above 50°C or below -10°C => Remove.
# "Moving Average." => Create a new list where each value is the average of itself and the value before it (skip the very first index).
# example : If the list is [4.0, 5.0, 6.0], the smoothed list would be [4.5, 5.5].
# Alert System: * Check if the maximum value in your cleaned list exceeds 8°C. If it does, print a "CRITICAL ALARM:"

print()
all_temp = [item.strip() for item in input("enter temp (comma separated) : ").split(",")]
filtered_temp = []

# Remove non-numeric
for element in all_temp:
    try:
        element = round(float(element), 2)
        filtered_temp.append(element)
    except ValueError:
        pass

# Remove outliers (build a new list safely)
clean_temp = []

for temp in filtered_temp:
    if -10 <= temp <= 50:
        clean_temp.append(temp)


print("\nFiltered input temp (w/o non-number and outlier): ")
for element in clean_temp:
    print(f"{element:.2f}")

# Moving average
moving_temp = []

for i in range(len(clean_temp) - 1):
    avg = (clean_temp[i] + clean_temp[i+1]) / 2
    moving_temp.append(avg)

print("\nFiltered moving temp : ")
for i in range(len(moving_temp)):
    print(f"{i+1}. {moving_temp[i]:.2f}")

max_temp = max(moving_temp)

if max_temp > 35 :
    print("\n!!!!! CRITICAL ALARM. 35 degrees exceeded. !!!!!")
    print(f"maximum temp : {max_temp}\n")
else :
    print("\n===== SAFE =====")
    print(f"maximum temp : {max_temp}\n")    