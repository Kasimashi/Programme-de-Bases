from builder import HouseBuilder

class HouseDirector:
    def __init__(self, builder: HouseBuilder):
        self.builder = builder

    def build_villa(self):
        return (self.builder
                .set_name("Villa Luxe")
                .set_type("Villa")
                .set_surface(180)
                .set_floors(2)
                .set_garage(True)
                .add_material("Brique")
                .add_material("Verre")
                .add_room("Salon", 40, 4)
                .add_room("Cuisine", 20, 2)
                .add_room("Chambre", 18, 1)
                .add_option("Piscine")
                .add_option("Domotique")
                .build())

    def build_cabane(self, name):
        return (self.builder
                .set_name(name)
                .set_type("Cabane")
                .set_surface(35)
                .set_floors(1)
                .set_garage(False)
                .add_material("Bois")
                .add_room("Séjour", 20, 2)
                .add_room("Chambre", 10, 1)
                .add_option("Poêle à bois")
                .build())
