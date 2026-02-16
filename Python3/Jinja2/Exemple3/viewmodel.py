from jinja2 import Environment, FileSystemLoader
from builder import HouseBuilder
from director import HouseDirector
import os

class HouseViewModel:
    def __init__(self):
        self.env = Environment(loader=FileSystemLoader("templates"),
                               trim_blocks=True, lstrip_blocks=True)
        self.houses = []

        builder = HouseBuilder()
        director = HouseDirector(builder)

        # Création des maisons
        self.houses.append(director.build_villa())
        self.houses.append(director.build_cabane("Cabane 1"))
        self.houses.append(director.build_cabane("Cabane 2"))

        # Dossier d'export
        self.output_dir = "output"
        os.makedirs(self.output_dir, exist_ok=True)

    def generate_house_doc(self, house):
        template = self.env.get_template("house.md.jinja")
        content = template.render(house=house.__dict__)

        # Export fichier
        filename = os.path.join(self.output_dir, f"{house.name.replace(' ', '_').lower()}.md")
        with open(filename, "w", encoding="utf-8") as f:
            f.write(content)
        return content

    def generate_summary(self):
        template = self.env.get_template("summary.md.jinja")
        content = template.render(houses=[h.__dict__ for h in self.houses])

        # Export Markdown
        filename = os.path.join(self.output_dir, "summary.md")
        with open(filename, "w", encoding="utf-8") as f:
            f.write(content)
        return content
