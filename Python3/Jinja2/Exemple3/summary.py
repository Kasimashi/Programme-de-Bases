from jinja2 import Environment, FileSystemLoader

from Jinja2.Exemple3.main import villa, cabane

env = Environment(
    loader=FileSystemLoader("templates"),
    trim_blocks=True,
    lstrip_blocks=True
)
template = env.get_template("summary.md.jinja")

houses = [villa.__dict__, cabane.__dict__]

output = template.render(houses=houses)

with open("summary.md", "w", encoding="utf-8") as f:
    f.write(output)
