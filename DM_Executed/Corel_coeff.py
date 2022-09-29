#http://192.168.1.8:8090/httpclient.html


import pandas

data = pandas.read_csv("cc.csv")

X = data['X'].tolist()
Y = data['Y'].tolist()

tot = len(X)

pro_X = 0
pro_Y = 0
pro_X_Y = 0

for i in range(tot):
    if X[i] and Y[i]:
        pro_X_Y += 1

    if X[i] == 1:
        pro_X += 1
    
    if Y[i] == 1:
        pro_Y += 1


res = (pro_X_Y)/(pro_X*pro_Y)

print(res)