from employee import Employee

class Processor:
    def __init__(self, fname: str):
        # A string representing the filename "data.txt" containing employee records
        self.fname = fname
        # set up empty dictionary to hold employee objects, with names as keys
        self.employees = {}
        # call readFile to populate the employees dictionary
        self.readFile()
    
    def readFile(self) -> None:
        # read employee records from file and create Employee objects
        with open(self.fname, "r") as file:
            for line in file:
                emp = Employee.createEmployee(line)
                self.employees[emp.name] = emp
    def printAllEmployees(self) -> None:
        # print all employee records in the employees dictionary
        # sorted by department and idNum
        # __repr__ method of Employee class should be used to print each employee
        sorted_emps = sorted(self.employees.values(), key=lambda e: (e.dept, e.idNum))
    
        for emp in sorted_emps:
            print(emp)
            
    def findEmployee(self, searched: str) -> list[Employee]:
        # return a list of Employee objects whose name contains the searched string
        # case-insensitive search
        result = []
        for emp in self.employees.values():
            if searched.lower() in emp.name.lower():
                result.append(emp)
        return result
    
    def printSearchResult(self, searched: str) -> None:
        # print the search result, displaying the number of employees found
        # or "No result"
        # __repr__ method of Employee class should be used to print each employee in the search result
        result = self.findEmployee(searched)
        if result:
            print(f"{len(result)} employee(s) found:")
            for emp in result:
                print(emp)
        else:
            print("No result")
        
    def departmentStats(self, dept: str) -> str:
        # return a string showing the average score and average salary of employees in the given department
        # Example: "Department: Engineering, Average Score: 85.5, Average Salary: 75000"
        total_score = 0
        total_salary = 0
        count = 0
        for emp in self.employees.values():
            if emp.dept.lower() == dept.lower():
                total_score += emp.score
                total_salary += emp.salary
                count += 1
        if count > 0:
            avg_score = total_score / count
            avg_salary = total_salary / count
            return f"Department: {dept}, Average Score: {avg_score:.1f}, Average Salary: {avg_salary:.2f}"
        else:
            return f"No employees found in department: {dept}"



p = Processor("data.txt")
p.printAllEmployees()