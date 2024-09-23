"""
Il s'agit d'une association unidirectionnelle. Lorsqu'un objet peut accéder à un autre objet, cette relation est appelée agrégation. Les objets peuvent exister indépendamment dans cette relation.

Nous pouvons le définir de manière plus concise, l'agrégation se produit lorsqu'un objet d'une classe peut posséder ou accéder à l'objet d'une autre classe.

Prenons l'exemple d'un étudiant et d'un département. Il y a deux classes, l'une est celle des étudiants et l'autre celle des départements. Les étudiants se voient attribuer un numéro d'inscription en fonction du département spécifique. Implémentons son code en Python.
"""

class Student:

    def __init__(self, id):
        self._id = id

    def registration_number(self, department_id) -> str:
        return str(self._id) + '-' + department_id


class Department:

    def __init__(self, id, student):
        self._id = id
        self._student = student

    def student_registration(self):
        return self._student.registration_number(self._id)


if __name__ == '__main__':
    student = Student(10)
    department = Department('ENG', student)
    print(department.student_registration())

