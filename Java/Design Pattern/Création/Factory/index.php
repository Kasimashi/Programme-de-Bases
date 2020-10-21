<?php
/*
design pattern Factory Method dans le cadre de la résolution du problème présenté. Commençons par mettre en place l’interface sur le type de transport*/

// Interface sur le type de transport -- Commune à tout les transports

interface Transport
{
    public function deliverOrder();
}

//Type de transport camion : implémentation concrète et différente de l'interface
class Truck implements Transport
{
    public function deliverOrder()
    {
        // ...
    }

    // et toutes les autres méthodes utiles à cet objet!
}

class Ship implements Transport
{
    public function deliverOrder()
    {
        // ...
    }
    
    // et toutes les autres méthodes utiles à cet objet!
}

// Interface qui définit la méthode "Factory" : défini la méthode en charge de la création du produit.
/*
Comme nous pouvons le voir, la création d’un objet n’est généralement pas la responsabilité principale de ce type de classe. Ici, c’est la fonction deliver qui aura le plus de valeur "métier", et elle doit être commune à toutes nos implémentations concrètes.
Nous avons rendu notre système de livraison complètement indépendant de chaque mode de transport, et rendu possible l’ajout d’un nombre infini de modes de livraison. Pour cela, il nous suffit de créer deux nouvelles classes : le type de transport et son "transport handler", dont il faudra seulement implémenter la méthode createTransport.
*/
interface TransportHandler
{
    public function createTransport() : Transport;
    
    public function deliver();
}

// Pour modéliser cela, nous pouvons définir une classe abstraite

abstract class AbstractTransportHandler implements TransportHandler
{
    abstract public function createTransport() : Transport;
    
    /**
     * cette fonction ne doit pas être surchargée
     */ 
    final public function deliver()
    {
        $transport = $this->createTransport();
        
        return transport->deliverOrder();
    }
}

// Cela ayant été fait, nous aurons donc une implémentation concrète d’Usine par type de transport

class TruckTransportHandler extends AbstractTransportHandler
{
    public function createTransport()
    {
        return new Truck();
    }
}

class ShipTransportHandler extends AbstractTransportHandler
{
    public function createTransport()
    {
        return new Ship();
    }
}
?>
