import random
alpha = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
npt = open('test.txt', 'w')
a = random.randint(100, 999)
b = random.choice(alpha)
c = random.seed()
i = 0
a = input();
while i < int(a):
    npt.write (random.choice(alpha) + ' ' + str(random.randint(100, 999)) + ' ' + random.choice(alpha) + random.choice(alpha) + '  ' + str(random.randrange(1, pow(2,64), 1)) + '\n')
    i += 1
