from random import *
from datetime import timedelta
from datetime import datetime
import  random
def random_date(start, end):
    """
    This function will return a random datetime between two datetime
    objects.
    """
    delta = end - start
    int_delta = (delta.days * 24 * 60 * 60) + delta.seconds
    random_second = randrange(int_delta)
    return start + timedelta(seconds=random_second)
nom=["Attia","Abdelli","Kacem","Gharbi","Abbaasi","Amara","Hachfi","Slema","Abidi","Sghaier","Tlili"]
prenom=["Raed","Saif","Ghassen","Imen","Ahmed","Rahma","Amira","Sarra","Khaled","Amir","Anouar"]
mat=[("1","Analyse",4.00),("2","Algebre",4.00),("3","Physique",4.00),
     ("4","Francais",2.00),("5","Anglais",2.00),("6","Math et Statistique",2.50),
     ("7","Conception",3.00),("8","Java",3.50),("9","Algorithique",3.50),
     ("10","Pyhton",2.50),("11","Microprocesseur",3.00),("12","CCNA",2.50)]
def generer():
    d1 = datetime.strptime('1/1/1990', '%m/%d/%Y')
    d2 = datetime.strptime('1/1/2003', '%m/%d/%Y')

    file1 = open("c:/text/groupe.txt", "w")
    g=15;
    e = 30;
    file1.write(str(g)+"\n")
    v = 0
    for i in range(1,g+1):
        file1.write("G"+str(i)+" "+str(e)+"\n")


        for j in range (1,e+1):
            v = v + 1
            if(v<10):
                t="0"+str(v)
            else:
                t=str(v)

            file1.write("|19IFJ"+t+"|")
            n=random.randint(0,len(nom)-1)
            p=random.randint(0,len(prenom)-1)
            file1.write(nom[n]+"|"+prenom[p])
            x = random_date(d1, d2)
            dd = str(x.day) + "/" + str(int(x.month)) + "/" + str(x.year)
            file1.write("|"+dd+"|")
            file1.write(str(6) + "|")
            file1.write("13|supp|0.00|0.00|")
            l=[]
            for k in range(1,6):
                while True:
                    m=random.randint(0,11)
                    if(m not in l):
                        break;
                l.append(m);
                file1.write(mat[m][0]+"|")
                file1.write(mat[m][1]+"|")
                ds = random.uniform(4,20)
                ex= random.uniform(4,20)
                file1.write("%.2f"%ds)
                file1.write("|")
                file1.write("%.2f" %ex)
                file1.write("|")

            file1.write("0.00|")

            file1.write("\n")

    print(v)



    file1.close()


if __name__ == '__main__':
    """d1 = datetime.strptime('1/1/1990', '%m/%d/%Y' )
    d2 = datetime.strptime('1/1/2003', '%m/%d/%Y')
    for i in range (0,10):
        x= random_date(d1, d2)
        ch=str(x.day)+"/"+str(int(x.month))+"/"+str(x.year)

        print(ch)"""
    a=3.520
    b=4.500
    print("%.2f"%a,"%.2f"%b)
    generer()