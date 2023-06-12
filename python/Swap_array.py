array = eval(input("Enter the element :"))
a = int(input("Enter 1st Index = "))
b = int(input("Enter 1st Index = "))

array[a],array[b]=array[b],array[a]
print("After Swapping given position:",array)
