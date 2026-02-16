from model import House

class HouseBuilder:
    def __init__(self):
        self.reset()

    def reset(self):
        self.house = House()
        return self

    def set_name(self, name):
        self.house.name = name
        return self

    def set_type(self, type_):
        self.house.type = type_
        return self

    def set_surface(self, surface):
        self.house.surface = surface
        return self

    def set_floors(self, floors):
        self.house.floors = floors
        return self

    def set_garage(self, garage):
        self.house.garage = garage
        return self

    def add_material(self, material):
        self.house.materials.append(material)
        return self

    def add_room(self, name, area, windows=1):
        self.house.rooms.append({"name": name, "area": area, "windows": windows})
        return self

    def add_option(self, option):
        self.house.options.append(option)
        return self

    def build(self):
        built_house = self.house
        self.reset()  # reset automatique pour la prochaine construction
        return built_house
