# https://asecuritysite.com/encryption/aes_modes
from Crypto.Cipher import AES
import hashlib
import sys
import binascii
import Padding

val='hello'
password='hello'
ival=10

if (len(sys.argv)>1):
	val=sys.argv[1]

if (len(sys.argv)>2):
	password=str(sys.argv[2])

if (len(sys.argv)>3):
	ival=int(sys.argv[3])

plaintext=val

def encrypt(plaintext,key, mode):
	encobj = AES.new(key,mode)
	return(encobj.encrypt(plaintext))

def decrypt(ciphertext,key, mode):
	encobj = AES.new(key,mode)
	return(encobj.decrypt(ciphertext))

def encrypt2(plaintext,key, mode,iv):
	encobj = AES.new(key,mode,iv)
	return(encobj.encrypt(plaintext))

def decrypt2(ciphertext,key, mode,iv):
	encobj = AES.new(key,mode,iv)
	return(encobj.decrypt(ciphertext))


key = hashlib.sha256(password.encode()).digest()

iv= hex(ival)[2:8].zfill(16)



print ("IV: "+iv)


plaintext = Padding.appendPadding(plaintext,blocksize=Padding.AES_blocksize,mode=0)
print ("Input data (CMS): "+binascii.hexlify(plaintext.encode()).decode())

ciphertext = encrypt(plaintext.encode(),key,AES.MODE_ECB)
print ("Cipher (ECB): "+binascii.hexlify(bytearray(ciphertext)).decode())


plaintext = decrypt(ciphertext,key,AES.MODE_ECB)
plaintext = Padding.removePadding(plaintext.decode(),mode=0)
print ("  decrypt: "+plaintext)


plaintext=val
plaintext = Padding.appendPadding(plaintext,blocksize=Padding.AES_blocksize,mode=0)

ciphertext = encrypt2(plaintext.encode(),key,AES.MODE_CBC,iv.encode())
print ("Cipher (CBC): "+binascii.hexlify(bytearray(ciphertext)).decode())

plaintext = decrypt2(ciphertext,key,AES.MODE_CBC,iv.encode())
plaintext = Padding.removePadding(plaintext.decode(),mode=0)
print ("  decrypt: "+plaintext)



plaintext=val
plaintext = Padding.appendPadding(plaintext,blocksize=Padding.AES_blocksize,mode=0)

ciphertext = encrypt2(plaintext.encode(),key,AES.MODE_CFB,iv.encode())
print ("Cipher (CFB): "+binascii.hexlify(bytearray(ciphertext)).decode())

plaintext = decrypt2(ciphertext,key,AES.MODE_CFB,iv.encode())
plaintext = Padding.removePadding(plaintext.decode(),mode=0)
print ("  decrypt: "+plaintext)



plaintext=val
plaintext = Padding.appendPadding(plaintext,blocksize=Padding.AES_blocksize,mode=0)

ciphertext = encrypt2(plaintext.encode(),key,AES.MODE_OFB,iv.encode())
print ("Cipher (OFB): "+binascii.hexlify(bytearray(ciphertext)).decode())

plaintext = decrypt2(ciphertext,key,AES.MODE_OFB,iv.encode())
plaintext = Padding.removePadding(plaintext.decode(),mode=0)
print ("  decrypt: "+plaintext)