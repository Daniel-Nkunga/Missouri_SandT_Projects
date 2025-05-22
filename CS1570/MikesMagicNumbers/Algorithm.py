"""
    Programmer: Daniel Nkunga
    Date: 11/11/24
    File: Algorithm.py
    Purpose: This program is a proof of Mike's Magic Numbers (Collatz Conjecture) for number between [1, 1_000_000_000]
"""

import time

# Variables
chain = []
start = time.time()
with open("Test.csv", mode='w', newline='') as file:
    for i in range(1, 1_000_000, 1):  # 1_000_000_000
        print(i)
        current = i
        sequence = []
        sequence.append(current)
        while current != 1:
            if current % 2 == 0:
                current = current // 2
                sequence.append(current)
            else:
                current = current * 3 + 1
                sequence.append(current)
        # print(sequence)
        file.write(f"{', '.join(map(str, sequence))}\n")
        sequence = []
print(f"Time: {time.time() - start} seconds")