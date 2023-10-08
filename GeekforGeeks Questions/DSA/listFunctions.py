# # # list1=[1,2,3,4]
# # # list2=[5,6,7,8]
# # # print(list1+list2)



# # list3=[1,2,3]
# # list3.append(5)
# # print(list3)
# # list3.append("hello")
# # print(list3)


# # list4=["hello","world","python","java","c++","ruby","perl"]
# # list3.append(list4[2:6])
# # print(list3)
# # =


# #append, pop, sort, count
# #pop function
# # list1=[1,2,3,4,5,6,7,8,9]
# # list1.pop() #if no parameter is passed in pop then it will remove the last element
# # print(list1)
# # list1.pop(2)
# # print(list1)


# # #pop using if statement
# # quantity=[4,0,5,1,3,8,9]
# # for i in range(0,len(quantity)):
# #     if quantity[i]==0:
# #         quantity.pop(i)
# # print(quantity)


# #EX :given a list of quantity you have to print "Buy more" or "Don't buy more"
# # if the quantity is > 3 then print "Don't buy more"
# # if the quantity is <= 3 then print "Buy more"

# # list1=["a","b","c","d","e","f","g","h","i","j"]
# # for i in range(0,len(list1)):
# #     print(list1[i])


# # for i in list1:
# #     print(i)


# # str1="hello world python"
# # for i in range(0,len(str1)):
# #     print(str1[i])

# # for i in str1:
# #     print(i)

# list1=[5,4,3,2,1]
# list1.sort() 
# print(list1)#by default in ascending order
# list1.sort(reverse=True) 
# print(list1)#descending order


# #list functions:
# #append : add it to the end
# # pop: remove the last element (if no parameter is passed)
# # sort: sort the list
# # len: find the length of the list
# # split : split the string into list
# #empty list : list1=[]
# #concatenation : +
# #slicing : list1[2:5]


# #string functions: 
# #empty string
# #concatenation, slicing, len, strip, join ,split, 


# #int, float, bool, for loop, if/else, range, menu driven program, mutable immutable

# #swapping two numbers
# #wrong way
# # a=8
# # b=6
# # a=b
# # b=a
# # print(a,b)

# #right way
# # a=8
# # b=6
# # temp=a
# # a=b
# # b=temp
# # print(a,b)

# # #alternate way (only in python)
# # a=8
# # b=6
# # a,b=b,a
# # print(a,b)

# # #swapping strings
# # str1="hello"
# # str2="world"
# # str1,str2=str2,str1
# # print(str1,str2)

# # #swapping lists
# # list1=[1,2,3,4]
# # list2=[5,6,7,8]
# # list3=[9,10,11,12]
# # list4=[13,14,15,16]
# # list1,list3=list3,list1
# # print(list3,list1)


# #swap two elements in a list (example of mutability)
# list1=[1,2,3,4,5,6,7,8,9]
# list1[0],list1[8]=list1[8],list1[0]
# print(list1)

#swapping characters in a string (example of immutability)
# list1="Hi Hello"
# list1[0],list[7]=list1[7],list1[0]
# print(list1)

# str1='1223'
# str1[0],str1[3]=str1[3],str1[0]
# print(str1)
