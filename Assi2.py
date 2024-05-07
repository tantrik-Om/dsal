size=int(input("Enter the size of set1"))
size1=int(input("Enter the size of set 2"))
print("\nFor set 1")
list1=[]
for i in range(size):
    element=int(input("Enter element:"))
    list1.append(element)
print("set 1=",list1)


print("\nFor set 2")
list2=[]
for i in range(size1):
    element=int(input("Enter element:"))
    list2.append(element)
print("set 2=",list2)
choice=0
while choice!=10:
    print("******MENU*******")
    print("1.Add")
    print("2.Remove")
    print("3.Contains")
    print("4.Size")
    print("5.Intersection")
    print("6.Union")
    print("7.Difference")
    print("8.Subset")
    
    print("10.Exit")
    
    choice=int(input("Enter choice:"))
    print()
    if choice==1:
        e=int(input("Enter number to add:"))
        list1.append(e)
        print("Set1=",list1)
    elif choice==2:
        e=int(input("Enter number to Remove:"))
        if e in list1:
            list1.remove(e)
            print("Set1=",list1)
        else:
            print(e,"is not in set 1")
    elif choice==3:
        e=int(input("Enter number to search in set 1:"))
        if e in list1:
            print("Number present in Set1")
        else:
            print("Number is not present in Set1")
        print("set 1=",list1)
    elif choice==4:
        print("Set 1 contains {} elements !!".format(len(list1)))
    elif choice==5:
        list3=[]
        for element in list1:
            if element in list2:
                list3.append(element)
        print("Set1=",list1)
        print("Set2=",list2)
        print("Intersection=",list3)
    elif choice==6:
        list3=[]
        list3=list1.copy()
        for element in list2:
            if element not in list1:
                list3.append(element)
        print("Set1=",list1)
        print("Set2=",list2)
        print("Union=",list3)
    elif choice==7:
        list3=[]
        for element in list1:
            if element not in list2:
                list3.append(element)
        print("Set1=",list1)
        print("Set2=",list2)
        print("Set1.set2=",list3)
    elif choice==8:
        print("Set1=",list1)
        print("Set2=",list2)
        list3=[]
        def sub():
            flag=0
            for e in list2:
                if e in list1:
                    flag=1
                else:
                    print("Set 2 is not subset of se1!")
                    return
            if flag==1:
                print("Set 2 is the subset of se1!")
        sub()
    elif choice==9:
        print("Set1=",list1)
        print("Set2=",list2)
        if sorted(list1)==sorted(list2):
            print("Set 2 is the proper subset of Set1")
        else:
            print("Set 2 is not proper subset of Set1")
    elif choice==10:
        print("Thanks for using this program!!!")
        break
    elif choice<1 or choice>10:
        print("Please enter valid choice!")
              
            
                                 
        
