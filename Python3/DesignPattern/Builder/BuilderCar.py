from abc import ABC, abstractmethod


class IMotor(ABC):

    @property
    @abstractmethod
    def power(self):
        return 9


class VolwagenMotor(IMotor):

    def power(self):
        return 10


class Car:
    def __init__(self):
        self._seats: int = 0
        self._engine: IMotor | None = None
        self._gps: bool = False
        self._tripComputer: bool = False

    @property
    def seats(self):
        return self._seats

    @seats.setter
    def seats(self, value):
        self._seats = value

    @property
    def engine(self):
        return self._engine

    @engine.setter
    def engine(self, value):
        self._engine = value

    @property
    def gps(self):
        return self._gps

    @gps.setter
    def gps(self, value):
        self._gps = value

    @property
    def tripComputer(self):
        return self._tripComputer

    @tripComputer.setter
    def tripComputer(self, value):
        self._tripComputer = value


class Manual:
    def __init__(self):
        self._document: str = ""

    def addArticles(self, content: str):
        self._document += content + "\n"


class ICarBuilder(ABC):

    @abstractmethod
    def reset(self):
        pass

    @abstractmethod
    def setSeats(self, seats: int):
        pass

    @abstractmethod
    def setEngine(self, motor: IMotor):
        pass

    @abstractmethod
    def setTripComputer(self, tripComputer: bool):
        pass

    @abstractmethod
    def setGPS(self, gps: bool):
        pass

    @abstractmethod
    def build(self):
        pass


class CarBuilder(ICarBuilder):

    def __init__(self):
        self._car = None
        self.reset()

    def reset(self):
        self._car = Car()

    def setSeats(self, seats: int):
        self._car.seats = seats

    def setEngine(self, motor: IMotor):
        self._car.engine = motor

    def setTripComputer(self, tripComputer: bool):
        self._car.tripComputer = tripComputer

    def setGPS(self, gps: bool):
        self._car.gps = gps

    def build(self):
        product = self._car
        self.reset()
        return product


class CarManualBuilder(ICarBuilder):
    def __init__(self):
        self._manual: Manual | None = None
        self.reset()

    def reset(self):
        self._manual: Manual = Manual()

    def setSeats(self, seats: int):
        self._manual.addArticles(f"The car have {seats} seats")

    def setEngine(self, motor: IMotor):
        self._manual.addArticles(f"The car have a {motor} engine")

    def setTripComputer(self, tripComputer: bool):
        if tripComputer:
            self._manual.addArticles(f"The car have a trip computer")
        else:
            self._manual.addArticles(f"The car have doesn't have trip computer")

    def setGPS(self, gps: bool):
        if gps:
            self._manual.addArticles(f"The car have a GPS")
        else:
            self._manual.addArticles(f"The car have doesn't have a GPS")

    def build(self):
        product = self._manual
        self.reset()
        return product


class CarDirector:

    def __init__(self):
        self._builder : ICarBuilder | None = None

    def setBuilder(self, builder: ICarBuilder):
        self._builder = builder

    def constructSportCar(self):
        self._builder.setSeats(2)
        self._builder.setTripComputer(True)
        self._builder.setGPS(True)
        self._builder.setEngine(VolwagenMotor())


if __name__ == "__main__":

    # Construct Car
    director : CarDirector = CarDirector()
    builder : ICarBuilder = CarBuilder()
    director.setBuilder(builder)
    director.constructSportCar()
    car: Car = builder.build()
    print(car.__dict__)

    # Construct Manual
    ManualBuilder: ICarBuilder = CarManualBuilder()
    director.setBuilder(ManualBuilder)
    director.constructSportCar()
    carManual: Manual = ManualBuilder.build()
    print(carManual.__dict__)
