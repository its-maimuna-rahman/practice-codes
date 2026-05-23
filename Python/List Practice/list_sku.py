# Challenge 1: The Supply Chain Reconciliation Tool Scenario:
# Your job is to find the discrepancies so the company doesn't pay for items they didn't get. Requirements:
    # Input: Ask the user to enter the "EXPECTED SKUs" (e.g., APP-01, ORA-02, BAN-03, CHR-04) 
                             # and the "RECEIVED SKUs".
# Logic - The Discrepancy Check: list => MISSING_ITEMS. (expected, not received)
#                                list => called UNEXPECTED_ITEMS. (unexpected, received)

# User Intervention: ASK the user if any of the unexpected_items should be kept and added to the official inventory. 
# If they type a SKU, move it from unexpected_items to the FINAL INVENTORY.
# Rate using this formula: Fulfillment Rate = (final / Total Items Expected) x 100
# Output: Display the missing_items, the unexpected_items that were rejected, and the final fulfillment percentage.

print()
expected = [expected.strip() for expected in input("Enter expected SKUs (comma separated): ").split(",")]
received = [received.strip() for received in input("Enter received SKUs (comma separated): ").split(",")]

print("\nExpected SKUs:")
for i in range(len(expected)) :
    print(f"{i+1}. {expected[i]}")

print("\nReceived SKUs:")
for i in range(len(received)) :
    print(f"{i+1}. {received[i]}")

unexpected = []

for item in received :
    if item not in expected :
        unexpected.append(item)

print("\nunexpected SKUs:")
for i in range(len(unexpected)) :
    print(f"{i+1}. {unexpected[i]}")

print("\nwhich unexpected items you wanna keep ? (enter 0 if you don't want any items to keep) : ")
keep_indexes = [int(x.strip()) - 1 for x in input("Enter indexes (comma separated): ").split(",")]
# 1 based index input

print("\n============ FINAL OUTPUT ============\n")

missing = []

for item in expected :
    if item not in received :
        missing.append(item)

print("\nMissing SKUs:")
for i in range(len(missing)) :
    print(f"{i+1}. {missing[i]}")

keep = []
reject = []

for idx in keep_indexes :
    if 0 <= idx < len(unexpected) :
        keep.append(unexpected[idx])

for item in unexpected:
    if item not in keep:
        reject.append(item)

print("\nItems you chose to keep:")
for i in range(len(keep)) :
    print(f"{i+1}. {keep[i]}")

print("\nItems you chose to reject:")
for i in range(len(reject)) :
    print(f"{i+1}. {reject[i]}")    

received_expected = []

for item in received :
    if item not in unexpected :
        received_expected.append(item)

final = received_expected + keep

print("\nFINAL Items you chose to keep:")
for i in range(len(final)) :
    print(f"{i+1}. {final[i]}")

fulfillment_rate = round((len(final) / len(expected)) * 100, 2)

print(f"\nFulfillment RATE = {fulfillment_rate}%")

