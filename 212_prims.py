l=[[0,0,8,0,13,17,0],
   [0,0,20,0,0,0,6],
   [8,20,0,11,0,0,0],
   [0,0,11,0,12,0,0],
   [13,0,0,12,0,15,0],
   [17,0,0,0,15,0,18],
   [0,6,0,0,0,18,0]]
v=[0,0,0,0,0,0,0]
inf=99999
v_no=7
no_ed=0
v[0]=True
while no_ed<v_no-1:
    min=inf
    x=0
    y=0
    for i in range(v_no):
        if v[i]:
            for j in range(v_no):
                if l[i][j]==0:
                    l[i][j]=inf
                     
