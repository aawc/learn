class School(object):
    def __init__(self, school_name):
        self._school_name = school_name
        self.db = {}

    def add(self, student_with_name, to_grade):
        students_in_grade = self.db.get(to_grade, set())
        students_in_grade.add(student_with_name)
        self.db[to_grade] = students_in_grade

    def grade(self, in_grade):
        return self.db.get(in_grade, set())

    def sort(self):
        result = []
        for grade in sorted(self.db):
            result.append((grade, tuple(sorted(self.grade(grade)))))
        return result
