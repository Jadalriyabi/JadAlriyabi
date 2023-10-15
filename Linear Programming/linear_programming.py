from pulp import LpMaximize, LpProblem, LpVariable

# Create a linear programming problem
model = LpProblem(name="Production_Planning", sense=LpMaximize)

# Decision variables
x1 = LpVariable(name="product1", lowBound=0, cat="Integer")
x2 = LpVariable(name="product2", lowBound=0, cat="Integer")

# Objective function
model += 10 * x1 + 15 * x2, "Profit"

# Constraints
model += 2 * x1 + 3 * x2 <= 100, "RawMaterialConstraint"
model += 4 * x1 + 2 * x2 <= 80, "LaborConstraint"
model += x1 + x2 <= 30, "MachineConstraint"
model += x1 <= 20, "Product1Demand"
model += x2 <= 25, "Product2Demand"

# Solve the problem
model.solve()

# Display results
print(f"Optimal production quantity for Product 1: {x1.value()}")
print(f"Optimal production quantity for Product 2: {x2.value()}")
print(f"Maximized Profit: ${model.objective.value()}")
