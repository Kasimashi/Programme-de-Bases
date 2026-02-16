from jinja2 import Environment, FileSystemLoader, select_autoescape
from datetime import datetime

modules = [
    {
        "name": "users",
        "description": "Gestion des utilisateurs",
        "functions": [
            {
                "name": "get_user",
                "description": "Retourne un utilisateur.",
                "params": [
                    {"name": "id", "type": "int"}
                ],
                "deprecated": False
            },
            {
                "name": "delete_user",
                "description": "Supprime un utilisateur.",
                "params": [
                    {"name": "id", "type": "int"}
                ],
                "deprecated": True
            }
        ]
    },
    {
        "name": "auth",
        "description": "Authentification",
        "functions": [
            {
                "name": "login",
                "description": "Connexion utilisateur.",
                "params": [
                    {"name": "email", "type": "string"},
                    {"name": "password", "type": "string"}
                ],
                "deprecated": False
            }
        ]
    },
    {
        "name": "utils",
        "functions": []
    }
]

env = Environment(
    loader=FileSystemLoader("templates"),
    autoescape=select_autoescape(["html"])
)

template = env.get_template("api.html")

html = template.render(
    title="SuperAPI",
    version="2.1.0",
    modules=modules,
    now=datetime.now()
)

with open("output.html", "w", encoding="utf-8") as f:
    f.write(html)

print("Documentation générée : output.html")
