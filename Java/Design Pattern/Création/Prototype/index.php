<?php

class Shop
{
    private $theme;

    public function getTheme() 
    {
        return $this->theme;
    }
    
    public function setTheme(Theme $theme)
    {
        $this->theme = $theme;
    }
    
    public function __clone()
    {
        // maintenant qu'il est différent
        // on pourra mettre à jour le theme seulement sur la copie
        $this->theme = clone $this->theme;
    }
}

class ShopCloner
{
    public function cloneWithTheme(Shop $shop, Theme $theme)
    {
        $newShop = clone $shop;
        $newShop->setTheme($theme);
        
        return $newShop;
    }
}

$shop = new ShopFactory->createShop(/* ... */); // beaucoup d'opérations
$shopCloner = new ShopCloner();
$theme = new Theme('modern-theme'); // par exemple

$newShop = $shopCloner->cloneWithTheme($shop, $theme);

var_dump($shop->getTheme() === $newShop->getTheme()); // false

?>
