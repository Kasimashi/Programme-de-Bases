<?php

// Nous créons une classe « Personnage ».
class Personnage
{
  private $_force;
  private $_localisation;
  private $_experience = 50;
  private $_degats;
  
   // Déclarations des constantes en rapport avec la force.

  const FORCE_PETITE = 20;
  const FORCE_MOYENNE = 50;
  const FORCE_GRANDE = 80;
  
  public function __construct($forceInitiale)
  {
        // N'oubliez pas qu'il faut assigner la valeur d'un attribut uniquement depuis son setter !
    $this->setForce($forceInitiale);
  }
        
  // Nous déclarons une méthode dont le seul but est d'afficher un texte.
  public function parler()
  {
    echo "Je suis un personnage !<br>";
  }
  
  public function gagnerExperience()
  {
    //On ajoute 1 à notre attribut $_experience
    $this->_experience ++;
  }
  
    // Ceci est la méthode getDegats() : elle se charge de renvoyer le contenu de l'attribut $_degats.
  public function getDegats()
  {
    return $this->_degats;
  }
        
  // Ceci est la méthode getForce() : elle se charge de renvoyer le contenu de l'attribut $_force.
  public function getForce()
  {
    return $this->_force;
  }
        
  // Ceci est la méthode getExperience() : elle se charge de renvoyer le contenu de l'attribut $_experience.
  public function getExperience()
  {
    return $this->_experience;
  }
  
  public function afficheExperience()
  {
    echo $this->_experience;
  }
  
  public function setForce($force)
  {
    // On vérifie qu'on nous donne bien soit une « FORCE_PETITE », soit une « FORCE_MOYENNE », soit une « FORCE_GRANDE ».
    if (in_array($force, [self::FORCE_PETITE, self::FORCE_MOYENNE, self::FORCE_GRANDE]))
    {
      $this->_force = $force;
      return;
    }
    
    if(!is_int($force)) // S'il ne s'agit pas d'un nombre entier
    {
        trigger_error("La force d\'un personne doit être un nombre entier",E_USER_WARNING);
        return;
    }
    if ($force > 100) // On vérifie bien qu'on ne souhaite pas assigner une valeur supérieure à 100.
    {
      trigger_error('La force d\'un personnage ne peut dépasser 100', E_USER_WARNING);
      return;
    }
    
    $this->_force = $force;
  }
  
  // Mutateur chargé de modifier l'attribut $_experience.
  public function setExperience($experience)
  {
    if (!is_int($experience)) // S'il ne s'agit pas d'un nombre entier.
    {
      trigger_error('L\'expérience d\'un personnage doit être un nombre entier', E_USER_WARNING);
      return;
    }
    
    if ($experience > 100) // On vérifie bien qu'on ne souhaite pas assigner une valeur supérieure à 100.
    {
      trigger_error('L\'expérience d\'un personnage ne peut dépasser 100', E_USER_WARNING);
      return;
    }
    
    $this->_experience = $experience;
  }
  
  public function frapper(Personnage $persoAFrapper)
  {
    $persoAFrapper->_degats += $this->_force;
  }
  

}

?>
