Les registres :
Les registres principaux : r0 à r12
r13 : sp : Stack Pointeur pointeur de pile
r14 : lr : Link Register
r15 : pc : Program Counter : indique l'adresse de la prochaine instruction à executer.
r16 : xpsr : Special-purpose program status registers : contient les flags conditionnels.
			bit 31 : N(Negative flag)	 -> 1(Negative) 0(Positive)
			bit 30 : Z(Zero flag)		-> 1 (Result of 0) 0(Non Zero result)
			bit 29 : C(Carry)			-> 1(carry true or borrow false) 0(carry false or borrow true)
			bit 28 : V(Overflow)		-> 1(Overflow) 0(No Overflow)
			[27:0] Reserved

Références : http://www.cburch.com/cs/230/arm-ref.pdf

Language C to Assembly : https://godbolt.org/

https://thinkingeek.com/2013/01/09/arm-assembler-raspberry-pi-chapter-1/