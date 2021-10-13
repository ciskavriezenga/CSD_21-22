# separate example applying the double for loop that can be used to generate
# the indices 0, 0, 2, 0, 2, 4, 6, 0, 2, 4, 6, 8, 0, 2, ...etc.

num_iterations = 3

for i in range(num_iterations):
  num_splits = 2 ** i
  print("i:", i, "num_splits", num_splits)

  for j in range(num_splits):
    index = j * 2
    print("index:", index)
