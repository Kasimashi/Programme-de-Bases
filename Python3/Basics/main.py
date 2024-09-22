print(__name__)

if __name__ == "__main__":

    print("Ce code ne sera exécuté que si le script Python est exécuté directement.")
    print("Si le module est importé, ce code ne sera pas exécuté car la variable __name__ ne sera pas égale à '__main__' mais au nom du module (donc du fichier python).")