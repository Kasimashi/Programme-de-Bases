from jinja2 import Environment, FileSystemLoader

# Données qui décrivent ton projet
data = {
    "project": {
        "name": "SuperAPI",
        "version": "1.0.0",
        "author": "Alice",
        "modules": [
            {
                "name": "users",
                "description": "Gestion des utilisateurs",
                "functions": [
                    {
                        "name": "get_user",
                        "params": ["id"],
                        "description": "Retourne un utilisateur par son identifiant."
                    },
                    {
                        "name": "create_user",
                        "params": ["email", "password"],
                        "description": "Crée un nouvel utilisateur."
                    }
                ]
            },
            {
                "name": "auth",
                "description": "Authentification",
                "functions": [
                    {
                        "name": "login",
                        "params": ["email", "password"],
                        "description": "Connecte un utilisateur."
                    }
                ]
            }
        ]
    }
}

# Chargement du template
env = Environment(loader=FileSystemLoader("."))
template = env.get_template("template.md.jinja")

# Rendu
result = template.render(data)

# Écriture dans un fichier
with open("output.md", "w", encoding="utf-8") as f:
    f.write(result)

print("Documentation générée dans output.md")
