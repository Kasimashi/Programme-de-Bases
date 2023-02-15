import sys
import random
import hashlib
import libnum

from p256 import curve,scalar_mult,point_add

msg="Hello"

if (len(sys.argv)>1):
  msg=(sys.argv[1])

# Alice's key pair (dA,QA)
dA = random.randint(0, curve.n-1)
QA = scalar_mult(dA,curve.g)

h=int(hashlib.sha256(msg.encode()).hexdigest(),16)

k = random.randint(0, curve.n-1)

rpoint = scalar_mult(k,curve.g)

r = rpoint[0] % curve.n

# Bob takes m and (r,s) and checks
inv_k = libnum.invmod(k,curve.n)

s = (inv_k*(h+r*dA)) % curve.n

print (f"Msg: {msg}\n\nAlice's private key={dA}\nAlice's public key={QA}\nk= {k}\n\nr={r}\ns={s}")

# To check signature

inv_s = libnum.invmod(s,curve.n)
c = inv_s
u1=(h*c) % curve.n
u2=(r*c) % curve.n
P = point_add(scalar_mult(u1,curve.g), scalar_mult(u2,QA))

res = P[0] % curve.n
print (f"\nResult r={res}")

if (res==r):
	print("Signature matches!")