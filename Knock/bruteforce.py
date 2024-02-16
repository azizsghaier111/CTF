import hashlib

# Prompt the user for their name
name = input("Please enter your name: ")
# Prompt the user for the nonce
nonce = input("Please enter the nonce: ")

prefix = f"{name}-{nonce}-"

# The maximum number of iterations
max_iter = 1000000000000

# The loop counter
counter = 0

# The flag to indicate if a valid x is found
found = False

# The loop
while not found and counter < max_iter:
    # Generate random bytes for x

    # Concatenate the prefix and x
    string = prefix + str(counter)
    # Compute the sha256 hash of the string
    hash = hashlib.sha256((string + "\n").encode()).digest()
    # Check if the first three bytes of the hash are zero
    if int.from_bytes(hash[:3], "big").bit_length() == 0:
        # Print the value of x and the hash
        print(string)
        print(f"Found a valid x: {string}")
        print(f"Hash: {hash.hex()}")

        # Set the flag to True
        found = True

    # Increment the counter
    counter += 1

# Check if a valid x is found
if not found:
    # Print a message
    print(f"No valid x found after {max_iter} iterations")
