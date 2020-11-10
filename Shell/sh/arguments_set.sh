#!/bin/bash
# ./arguments_shift.sh peche pomme poire

set param1 param2 param3

echo "Nombre de paramètres : $#"
echo "Le second paramètre est : $2"
echo "Les paramètres sont : $@"

set pêche pomme
echo "Nombre de paramètres : $#"
echo "Le second paramètre est : $2"
echo "Les paramètres sont : $@"


echo "Appuyer la touche <Entrée> pour continuer..."
read touche
case $touche in
*)	echo "Reprise du script..."
	;;
	
exit
