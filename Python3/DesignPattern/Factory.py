from abc import ABCMeta, abstractmethod
class IFrame(metaclass=ABCMeta):
    """
    The Product interface declares the operations that all concrete products
    must implement.
    """

    @abstractmethod
    def operation(self) -> str:
        pass

class FrameA(IFrame):
    def operation(self):
        return "Decode Frame A"


class FrameB(IFrame):
    def operation(self):
        return "Decode Frame B"

class FrameFactory:
    """
    The Creator class declares the factory method that is supposed to return an
    object of a Product class. The Creator's subclasses usually provide the
    implementation of this method.
    """

    @abstractmethod
    def factory_method(self,Type):
        """
        Note that the Creator may also provide some default implementation of
        the factory method.
        """
        if (Type == "A"):
            return FrameA()
        if (Type == "B"):
            return FrameB()

if __name__ == "__main__":
    Creator = FrameFactory()
    ObjectA = Creator.factory_method("A")
    print(ObjectA.operation())
    print(type(ObjectA))