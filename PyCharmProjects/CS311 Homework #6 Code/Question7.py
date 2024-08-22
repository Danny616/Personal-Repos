def calculate_airfare(destination):
    if destination == "Sydney":
        return 1413
    elif destination == "Maui":
        return 503
    elif destination == "Paris":
        return 916
    else:
        return None


def calculate_hotel_cost(destination, days):
    if destination == "Sydney":
        return 184 * days
    elif destination == "Maui":
        return 351 * days
    elif destination == "Paris":
        return 170 * days
    else:
        return None


destination = input("Where do you want to go (Sydney, Maui, or Paris)? ")
days = int(input("How many days will you stay? "))

airfare = calculate_airfare(destination)
hotel_cost = calculate_hotel_cost(destination, days)

if airfare is None or hotel_cost is None:
    print("Invalid destination.")
else:
    total_cost = airfare + hotel_cost
    print(f"Your total cost for airfare and hotel is ${total_cost}.")
