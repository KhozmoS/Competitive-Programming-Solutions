# Fix Python 2.x.
try: input = raw_input
except NameError: pass

a = input()
b = a.split(' ')

print(int(b[0]) + int(b[1]))