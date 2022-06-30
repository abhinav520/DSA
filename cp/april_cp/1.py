for n in range(2,21):
    for k in range(0,2**n+100):
        ctr=0
        for a in range(0,2**n):
            for b in range(0,2**n):
                for c in range(0,2**n):
                    if a^b^c==k and a!=b and b!=c and a!=c:
                        ctr+=1
        print(k,ctr)