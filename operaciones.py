# Programa para realizar operaciones aritméticas binarias

# Cambie a necesidad las siguientes variables

# Inputs:
N = int(input("Ingrese el número de variables: "))
print("Indique al final del número el formato, donde d es decimal, b es binario, o es octal y h es hexadecimal")

# Use a list to store the values for each variable
variables = []

# Loop through each variable
for i in range(N):
    # Ask the user to input the value and format for the current variable
    value = input(f"Ingrese el valor para la variable {i+1}: ")
    format = value[-1]  # Extract the format from the end of the input string
    value = value[:-1]  # Remove the format from the input string
    
    # Convert the value to an integer based on its format
    if format == "d":
        value = int(value)
    elif format == "b":
        value = int(value, 2)
    elif format == "o":
        value = int(value, 8)
    elif format == "h":
        value = int(value, 16)
    else:
        print(f"Error: formato {format} no reconocido")
        exit()
        
    # Add the converted value to the list of variables
    variables.append(value)

# Define a dictionary to map variable names to their values
variable_dict = {}
for i in range(N):
    variable_name = chr(ord('a') + i)  # use letters of the alphabet to name variables
    variable_dict[variable_name] = variables[i]
    print("Los valores de las variables son:")
    print(f"Variable '{variable_name}': {variables[i]}".center(50, " ")) # Print out the values for all the variables

# Ask the user to input the operation to perform
operation = input("Ingrese la operación a realizar: ")

# Use the eval() function to evaluate the user-specified operation using the variable values
result = eval(operation, {}, variable_dict)

# Print out the result of the operation
print(f"El resultado de la operación es: {result}".center(50, "-"))

# Output the result in a table format
print("{:<10}{:>10}{:>10}{:>10}".format("Decimal", "Binario", "Octal", "Hexadecimal"))
print("{:<10}{:>10}{:>10}{:>10}".format(result, bin(result)[2:], oct(result)[2:], hex(result)[2:]))
