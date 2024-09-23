"""
Il définit un type de relation fort. Il peut être défini comme lorsqu'une classe peut référencer un ou plusieurs objets d'une autre classe à l'intérieur de sa variable d'instance. En composition, les objets ne peuvent pas exister indépendamment.

Nous pouvons implémenter l'exemple ci-dessus d'étudiants et de départements de manière compositionnelle. Dans cet exemple, l'objet étudiant est instancié à l'intérieur de l'objet département. Chaque fois qu'un objet département est détruit, un objet étudiant est automatiquement détruit.
"""

class Student:

    def __init__(self, id):
        self._id = id

    def registration_number(self, department_id) -> str:
        return str(self._id) + '-' + department_id


class Department:

    def __init__(self, department_id, student_id):
        self._id = department_id
        self._student = Student(student_id)

    def student_registration(self):
        return self._student.registration_number(self._id)


if __name__ == '__main__':
    department = Department('ENG', 10)
    print(department.student_registration())