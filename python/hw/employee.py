
class Employee:
    def __init__(self, idNum: int, name: str, dept: str,
                 age: int, score: float, salary: int):
        self.idNum = idNum
        self.name = name
        self.dept = dept
        self.age = age
        self.score = score
        self.salary = salary
    
    @staticmethod
    def createEmployee(record: str) -> "Employee":
        # a string representing a line of employee data
        # (comma-separated) from input file
        # Example: "1001, Alice Johnson,Engineering,29,88,75000"
        fields = [field.strip() for field in record.split(",")]
        idNum = int(fields[0])
        name = fields[1]
        dept = fields[2]
        age = int(fields[3])
        score = float(fields[4])
        salary = int(fields[5])
        return Employee(idNum, name, dept, age, score, salary)

    def rating(self) -> str:
        if self.score > 90:
            return "Excellent"
        elif self.score > 80:
            return "Good"
        elif self.score > 70:
            return "Fair"
        else:
            return "Bad"
    
    def __lt__(self, other) -> bool:
        return self.idNum < other.idNum

    def __eq__(self, other) -> bool:
        return (self.idNum == other.idNum and self.name == other.name and
                self.dept == other.dept and self.age == other.age and
                self.score == other.score and self.salary == other.salary)
   
    def __repr__(self) -> str:
        # returns a multi-line string representation of the Employee object
        string = (f"Name: {self.name}\n" + f"ID: {self.idNum}\n" +
                  f"Department: {self.dept}\n" + f"Rating: {self.rating()}\n" +
                  f"Age: {self.age}\n" + f"Score: {self.score}\n" +
                  f"Salary: {self.salary}")
        return string


## Test code
emp1 = Employee(1001, "Alice Johnson", "Engineering", 29, 88, 75000)
print(emp1)
emp2 = Employee.createEmployee("1002,Bob Smith, Marketing,35,92,80000")
print(emp2)
print(emp1.__lt__(emp2))  # True, since 1001 < 1002
print(emp1.__eq__(emp2))  # False, since emp1 and emp2 have different attributes
