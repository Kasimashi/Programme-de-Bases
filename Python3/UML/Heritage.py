class Person:
    def __init__(self, fname, lname, address):
        self.fname = fname
        self.lname = lname
        self.address = address

    def display(self):
        print("First Name: ", self.fname)
        print("Last Name: ", self.lname)
        print("Address: ", self.address)


class Student(Person):
    def __init__(self, fname, lname, address, age, gradYear):
        super().__init__(fname, lname, address)
        self.age = age
        self.gradYear = gradYear

    def display(self):
        super().display()
        print("Age: ", self.age)
        print("Graduation Year: ", self.gradYear)


# person object
per = Person("Adam", "Ho", "1234 abc blvd")
per.display()
print("===========================================")
std = Student("Peter", "kee", "9876 xyz blvd", 28, 2008)
std.display()