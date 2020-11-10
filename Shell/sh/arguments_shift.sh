#!/bin/bash
# ./arguments_shift.sh 1 2 3 4 5 6 7 8 9 10

echo "Nombre de paramètres : $#"
echo "Le 1er paramètre est : $1"
echo "Le 3ème paramètre est : $3"
echo "Le 6ème paramètre est : $6"
echo "Le 10ème paramètre est : ${10}"
echo "============================================="
echo "Décalage d'un pas avec la commande "shift""
shift
echo "Nombre de paramètres : $#"
echo "Le 1er paramètre est : $1"
echo "Le 3ème paramètre est : $3"
echo "Le 6ème paramètre est : $6"
echo "Le 10ème paramètre est : ${10}"
echo "============================================="
echo "Décalage de quatre pas avec la commande "shift 4""
shift 4
echo "Nombre de paramètres : $#"
echo "Le 1er paramètre est : $1"
echo "Le 3ème paramètre est : $3"
echo "Le 6ème paramètre est : $6"
echo "Le 10ème paramètre est : ${10}"
echo

echo "Appuyer la touche <Entrée> pour continuer..."
read touche
case $touche in
*)	echo "Reprise du script..."
	;;
	
exit
