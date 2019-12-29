# using selection sort to sort only specific type of numbers in a list
class mylist(list):
    def sel_sort(self, func=lambda n: n):
        for i in range(len(x)-1):
            if func(x[i]):
                min = x[i]
                for j in range(i+1,len(x)):
                    if func(x[j]) and x[j]<min:
                        x[i],x[j]=x[j],x[i]

if __name__ == "__main__":
    x = mylist(range(20,-1,-1))
    spl_odd = lambda x: x&1==1
    x.sel_sort(spl_odd)
    print(x)
# 20KTJ4524660