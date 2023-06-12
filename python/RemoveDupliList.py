li= list(map(int,input("Enter your array = ").strip().split()))
newli=[]

for item in li:
    if item not in newli:
        newli.append(item)

print(newli)

#using set
newliSet = list(set(li))
print(newliSet)
