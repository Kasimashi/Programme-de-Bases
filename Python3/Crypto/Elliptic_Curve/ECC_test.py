from tinyec import registry
from tinyec.ec import make_keypair

## https://neuromancer.sk/std/secg/secp256r1
ecc_curve = registry.get_curve('secp256r1')
print("G :")
print(ecc_curve.g)
print("a :")
print(hex(ecc_curve.a))
print("b :")
print(hex(ecc_curve.b))
print("n :")
print(hex(ecc_curve.field.n))

key = make_keypair(ecc_curve)

print(key.priv)
print(key.pub)