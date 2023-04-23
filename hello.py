import cppyy
from cppyy.gbl.std import vector
import solvera
from cppyy.gbl import hello


x = vector[int] (5, 2)

for i in range(5):
    print(x[i], end=" ")

hello.mutate_vector(x)

print("\nworks?\n")

for i in range(5):
    print(x[i], end=" ")


