<?php
require 'Personnage.php';

// On envoie une « FORCE_MOYENNE » en guise de force initiale.
$perso = new Personnage(Personnage::FORCE_MOYENNE);
$perso->parler();
$perso->gagnerExperience(); // On gagne de l'expérience.
$perso->getExperience(); // On affiche la nouvelle valeur de l'attribut.
$perso->afficheExperience();

$perso1 = new Personnage(Personnage::FORCE_PETITE); // Un premier personnage
$perso2 = new Personnage(Personnage::FORCE_MOYENNE); // Un second personnage

echo '<br>';

$perso1->setForce(10);
$perso1->setExperience(2);

$perso2->setForce(90);
$perso2->setExperience(58);


$perso1->frapper($perso2);  // $perso1 frappe $perso2
$perso1->gagnerExperience(); // $perso1 gagne de l'expérience

$perso2->frapper($perso1);  // $perso2 frappe $perso1
$perso2->gagnerExperience(); // $perso2 gagne de l'expérience

echo 'Le personnage 1 a ', $perso1->getForce(), ' de force, contrairement au personnage 2 qui a ', $perso2->getForce(), ' de force.<br />';
echo 'Le personnage 1 a ', $perso1->getExperience(), ' d\'expérience, contrairement au personnage 2 qui a ', $perso2->getExperience(), ' d\'expérience.<br />';
echo 'Le personnage 1 a ', $perso1->getDegats(), ' de dégâts, contrairement au personnage 2 qui a ', $perso2->getDegats(), ' de dégâts.<br />';
?>
