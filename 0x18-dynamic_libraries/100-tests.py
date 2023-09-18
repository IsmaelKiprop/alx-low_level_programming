import random
import ctypes

# Load the dynamic library
ops = ctypes.CDLL('./100-operations.so')

a = random.randint(-111, 111)
b = random.randint(-111, 111)

result_add = ops.add(a, b)
result_sub = ops.sub(a, b)
result_mul = ops.mul(a, b)
result_div = ops.div(a, b)
result_mod = ops.mod(a, b)

print(f"{a} + {b} = {result_add}")
print(f"{a} - {b} = {result_sub}")
print(f"{a} x {b} = {result_mul}")
print(f"{a} / {b} = {result_div}")
print(f"{a} % {b} = {result_mod}")
