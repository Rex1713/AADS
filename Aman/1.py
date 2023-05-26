size=3
list=[None]*size

def add():
    id=int(input("Enter id"))
    name=input("name")
    tp=int(input("Tp"))

    details=[id,name,tp]
    index=id%size

    for i in range (size):
        if(list[index]==None):
            list[index]=details
            print("added ", index, details)
            break
        else:
            index=(index+1)%size

def search():
    id=int(input("Enter the id"))
    index = id % size

    for i in range (size):
        if(list[index]!=None):
            if(list[index][0]==id):
                print("Found at", index)
                break
        index=(index+1)%size
    else:
        print("element not foud")

def delete():
    id=int(input("enter"))
    index=id%size
    for i in range(size):
        if(list[index]!=None):
            if(list[index][0]==id):
                list[index]=None
                print("Deleted")
                break
        index=(index+1)%size
    else:
        print("Not present")


add()
add()
add()
print("Search")
search()
print("Del")
delete()
print("searcj")
search()
