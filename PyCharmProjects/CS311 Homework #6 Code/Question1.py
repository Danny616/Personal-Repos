router_price = 199.99
tax_rate = 0.12
num_routers = 5

total_price = (router_price + router_price * tax_rate) * num_routers

print("Total price of", num_routers, "routers is: $", round(total_price, 2))
