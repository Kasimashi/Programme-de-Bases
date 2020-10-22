<?php
/*

require "Personnage.php"

// On admet que $db est un objet PDO.
$request = $db->query('SELECT id, nom, forcePerso, degats, niveau, experience FROM personnages');
    
while ($donnees = $request->fetch(PDO::FETCH_ASSOC)) // Chaque entrée sera récupérée et placée dans un array.
{
  // On passe les données (stockées dans un tableau) concernant le personnage au constructeur de la classe.
  // On admet que le constructeur de la classe appelle chaque setter pour assigner les valeurs qu'on lui a données aux attributs correspondants.
  $perso = new Personnage($donnees);
        
  echo $perso->nom(), ' a ', $perso->forcePerso(), ' de force, ', $perso->degats(), ' de dégâts, ', $perso->experience(), ' d\'expérience et est au niveau ', $perso->niveau();
}


?>
*/
require "Personnage.php";
require "PersonnagesManager.php";

$perso = new Personnage([
  'nom' => 'Victor',
  'forcePerso' => 5,
  'degats' => 0,
  'niveau' => 1,
  'experience' => 0
]);

echo 'Le personnage crée a le nom de ', $perso->nom(), ' il possède une force de ', $perso->forcePerso(), ' fait ', $perso->degats() , 'de dégats et de niveau : ',$perso->niveau(),' de plus il a une expérience de ',$perso->experience();

$db = new PDO('mysql:host=127.0.0.1;dbname=test1', 'user', 'user');
$manager = new PersonnagesManager($db);
    
$manager->add($perso);

?>
