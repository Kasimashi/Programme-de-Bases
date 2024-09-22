class Test:

    def __init__(self):
        self._test: str = ""

    @property
    def test(self):
        """ Helloworld ! """
        return "self._test"

    @test.setter
    def test(self, value):
        self._test = value


test = Test()

print([attr for attr in dir(Test) if not attr.startswith('__')])

properties = []
for k, v in vars(Test).items():
    print(f"key : {k}, value : {v}")
    if type(v) is property and v.fset is not None:
        properties.append(k)

print(properties)

for attribute in properties:
    print(test.__getattribute__(attribute))
