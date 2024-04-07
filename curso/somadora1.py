# somadora1.py - somadora infinita - versao 1

print ('Digite os valores a somar seguidos de [ENTER].')
print ('Para encerrar digite zero: 0')
n = float(input(':'))
total = n
while 1:
    try:
        n = float(input(':'))
        total = total + n
        if (n==0):
            break
    except:
        n=0
print ('TOTAL: %s' % total)
