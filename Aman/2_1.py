def create_dictionary(size):
    table = [[] for _ in range(size)]
    return table

def _hash_function(key, size):
    return hash(key) % size

def insert(dictionary, key, value):
    size = len(dictionary)
    index = _hash_function(key, size)
    chain = dictionary[index]

    for pair in chain:
        if pair[0] == key:
            pair[1] = value
            return

    chain.append((key, value))

def find(dictionary, key):
    size = len(dictionary)
    index = _hash_function(key, size)
    chain = dictionary[index]

    for pair in chain:
        if pair[0] == key:
            return pair[1]

    return None

def delete(dictionary, key):
    size = len(dictionary)
    index = _hash_function(key, size)
    chain = dictionary[index]

    for i, pair in enumerate(chain):
        if pair[0] == key:
            del chain[i]
            return

def display(dictionary):
    size = len(dictionary)

    for index, chain in enumerate(dictionary):
        print(f"Index {index}: ", end="")
        for pair in chain:
            print(f"({pair[0]}, {pair[1]})", end=" ")
        print()


# Example usage:
dictionary = create_dictionary(10)

# Inserting key-value pairs
insert(dictionary, "apple", 5)
insert(dictionary, "banana", 7)
insert(dictionary, "cherry", 3)
insert(dictionary, "date", 2)
insert(dictionary, "elderberry", 9)

# Displaying the dictionary
display(dictionary)
# Output:
# Index 0: (elderberry, 9) 
# Index 1: 
# Index 2: 
# Index 3: (cherry, 3) 
# Index 4: (date, 2) 
# Index 5: (apple, 5) 
# Index 6: 
# Index 7: 
# Index 8: (banana, 7) 
# Index 9: 

# Finding values by key
print(find(dictionary, "cherry"))  # Output: 3
print(find(dictionary, "banana"))  # Output: 7
print(find(dictionary, "grape"))   # Output: None

# Deleting a key-value pair
delete(dictionary, "date")
display(dictionary)
# Output:
# Index 0: (elderberry, 9) 
# Index 1: 
# Index 2: 
# Index 3: (cherry, 3) 
# Index 4: 
# Index 5: (apple, 5) 
# Index 6: 
# Index 7: 
# Index 8: (banana, 7) 
# Index 9: 
