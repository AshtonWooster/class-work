def genTest():
    l = [1, 2, 3, 4, 5]

    for i in l:
        print(f"looping at {i}")
        yield i 

def fun1():
    pass

# print(type(fun1))
# print(type(genTest()))

# for r in genTest():
#     print(r)

g = genTest()

while True:
    try:
        print(next(g))
    except StopIteration as e:
        print("Done!")
        break


num = 20
string = "Hello World!"
boolean = True
my_list = [2, "Hi", False]
dictionary = {"Hello" : 2, "World" : True}

print(dictionary["Hello"])

