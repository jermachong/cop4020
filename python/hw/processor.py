#
# Author: Jeremy Achong
# PID: 5124781
# This file contains the Processor class which processes employee records from a file,
# allows searching for employees, generates reports, and provides a menu interface for user interaction.
#
from Employee import Employee

class Processor:
    def __init__(self, fname: str):
        # A string representing the filename "data.txt" containing employee records
        self.fname = fname
        # set up empty dictionary to hold employee objects, with names as keys
        self.employees = {}
        # call readFile to populate the employees dictionary
        self.readFile()
    
    # open the file and read employee records
    def readFile(self) -> None:
        # read employee records from file and create Employee objects
        try:
            with open(self.fname, "r") as file:
                for line in file:
                    emp = Employee.createEmployee(line)
                    self.employees[emp.name] = emp
        # exception handling for file not found or invalid data format can be added here if desired
        except:
            print(f"cannot open file")
            exit(1)
    
    # print all employee records in the employees dictionary
    def printAllEmployees(self) -> None:
        # print all employee records in the employees dictionary
        # sorted by department and idNum
        # __repr__ method of Employee class should be used to print each employee
        sorted_emps = sorted(self.employees.values(), key=lambda e: (e.dept, e.idNum))
    
        for emp in sorted_emps:
            print(emp)
            print()
            
    # search for employees whose name contains the searched string (case-insensitive)     
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
            print(f"{len(result)} employee/s found:")
            for emp in result:
                print(emp)  
                print()
        else:
            print("No result")
    
    # may need to change depending on prof's email response
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
            return f"{dept} Department:\n- Employees: {count}\n- Average Performance: {avg_score:.2f}\n- Average Salary: {avg_salary:.2f}\n"
        else:
            return f"No employees found in department: {dept}"

    def calculate_department_average(self, department: str, criteria: str) -> float:
        # return the average of a specified criteria (score or salary) for employees in a given department
        total = 0
        count = 0
        for emp in self.employees.values():
            if emp.dept.lower() == department.lower():
                if criteria == "score":
                    total += emp.score
                elif criteria == "salary":
                    total += emp.salary
                count += 1
        if count > 0:
            return total / count
        else:
            return 0.0
    
    def totalAvg(self, criteria: str) -> float:
        # returns the average of the averages for the specified criteria (score or salary) across all departments
        # result shuld be rounded to two decimal places
        dept_averages = {}
        for emp in self.employees.values():
            dept = emp.dept
            if dept not in dept_averages:
                dept_averages[dept] = []
            if criteria == "score":
                dept_averages[dept].append(emp.score)
            elif criteria == "salary":
                dept_averages[dept].append(emp.salary)
        total_avg = 0
        for dept, values in dept_averages.items():
            avg = sum(values) / len(values)
            total_avg += avg
        if dept_averages:
            return round(total_avg / len(dept_averages), 2)
        else:
            return 0.0
    
    def generateReport(self) -> None:
        # Generate a text report with company-wide and department-specific statistics
        # and save it to "report_<datafilename>.txt"
        report_filename = f"report_{self.fname}"
        with open(report_filename, "w") as report_file:
            report_file.write("=================\n")
            report_file.write(f"Generated from: {self.fname}\n\n")
            
            report_file.write("Company Statistics:\n")
            report_file.write(f"Total Employees: {len(self.employees)}\n")
            report_file.write(f"Overall Average Performance: {self.totalAvg('score')}\n")
            report_file.write(f"Average Salary: {self.totalAvg('salary')}\n\n")

            report_file.write(f"Department Breakdown:\n")
            report_file.write("-------------\n")
            departments = set(emp.dept for emp in self.employees.values())
            for dept in sorted(departments):
                report_file.write(f"{self.departmentStats(dept)}\n")
            # report_file.write("----\n")
    
    def menu(self) -> None:
        # display a menu to the user and allow them to choose options to view statistics, search for employees, or generate a report
        while True:
            print("Choice 1 For searching users")
            print("Choice 2 For generating report")
            print("Choice 3 For printing all employees")
            print("Choice 4 For exiting")
            choice = input("Enter choice: ")
            if choice == "1":
                search_name = input("Enter searched string: ")
                self.printSearchResult(search_name)
            elif choice == "2":
                self.generateReport()
                print(f"Report generated")
            elif choice == "3":
                self.printAllEmployees()
            elif choice == "4":
                print("Exiting program.")
                break
            else:
                print("Invalid choice. Please enter a number from 1 to 5.")


# Test code
# p = Processor("data.txt")
# p.printAllEmployees()

# main method will create instence of Processor.
# then it will run menu method
if __name__ == "__main__":
    print("Enter file name")
    fname = input()
    employee_processor = Processor(fname)
    employee_processor.menu()