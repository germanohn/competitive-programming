def f(sem, semana, accuSum, n, h):
    qntdBaixou = (1 + n*sem)*(n*sem)//2
    qntBaixouNoDia = n*sem + 1
    alturaExpNoInicio = h - qntdBaixou
    alturaRealmente = 0 + (accuSum * sem)

    for x in xrange(n):
        alturaExpNoInicio = alturaExpNoInicio - qntBaixouNoDia
        qntBaixouNoDia = qntBaixouNoDia + 1
        alturaRealmente = alturaRealmente + semana[x]
        if alturaExpNoInicio <= alturaRealmente:
            return True

    return False

def solve():

    n, h = map(int, raw_input().split())
    semana = list(map(int, raw_input().split()))
    accuSum = int(0)
    for x in semana:
        accuSum = accuSum + x

    expect = h
    curH = 0
    dec = 1
    for x in xrange(n):
        curH = curH + semana[x]
        expect = expect - dec
        dec = dec + 1
        if curH >= expect:
            return x+1

    lo = int(0)
    hi = int(1e11)
    mid = int(0)
    for x in range(150):
        mid = (lo + hi) // 2
        if f(mid, semana, accuSum, n, h):
            hi = mid
        else:
            lo = mid + 1

    achei = lo
    diaInicial = n*achei + 1
    qntdBaixou = (1+n*achei) * (n*achei)//2
    qntBaixouNoDia = n*achei + 1
    alturaExpNoInicio = h - qntdBaixou
    alturaRealmente = 0 + (accuSum * achei)
    for x in range(n):
        alturaExpNoInicio = alturaExpNoInicio - qntBaixouNoDia
        qntBaixouNoDia = qntBaixouNoDia + 1
        alturaRealmente = alturaRealmente + semana[x] 
        if alturaExpNoInicio <= alturaRealmente:
            return diaInicial + x

k = solve()
print(k)
