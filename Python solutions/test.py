from collections import Counter

t = 2e32 - 1

# Using format() function
formatted_t = format(t, '.0f')  # '.0f' specifies fixed-point notation with 0 decimal places.
print(formatted_t)

# Using an f-string
formatted_t_fstring = f"{t:.0f}"  # Similarly, '.0f' specifies fixed-point notation with 0 decimal places.
print(formatted_t_fstring)
