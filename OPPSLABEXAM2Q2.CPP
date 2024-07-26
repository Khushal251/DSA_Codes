#include <bits/stdc++.h>
using namespace std;
#define int long long int


class Customer {
public:
    int customerID;
    string companyName;
    string alsoKnownAs;
    string contactNumber;
    string addressLine1;
    string addressLine2;
    string addressLine3;
    string country;
    string postCode;
    string telephoneNumber;
    string fax;
    string mobile;
    string emailAddress;
    string websiteAddress;

    void selectCustomer() {
        std::cout << "Selecting customer: " << companyName << std::endl;
    }

    void addCustomer() {
        std::cout << "Adding customer: " << companyName << std::endl;
    }

    void deleteCustomer() {
        std::cout << "Deleting customer: " << companyName << std::endl;
    }

    void updateCustomer() {
        std::cout << "Updating customer: " << companyName << std::endl;
    }
};

class Project {
public:
    int projectID;
    int customerID;
    std::string projectName;
    std::string startDate;
    std::string accountManager;
    std::string projectDescription;
    std::string purchaseOrderNumber;

    void selectProject() {
        std::cout << "Selecting project: " << projectName << std::endl;
    }

    void addProject() {
        std::cout << "Adding project: " << projectName << std::endl;
    }

    void deleteProject() {
        std::cout << "Deleting project: " << projectName << std::endl;
    }

    void updateProject() {

        std::cout << "Updating project: " << projectName << std::endl;
    }
};

class Employee {
public:
    int employeeID;
    int userID;
    std::string foreName;
    std::string surname;
    double chargeOutRate;

    void selectEmployee() {

        std::cout << "Selecting employee: " << foreName << " " << surname << std::endl;
    }

    void addEmployee() {

        std::cout << "Adding employee: " << foreName << " " << surname << std::endl;
    }

    void deleteEmployee() {
 
        std::cout << "Deleting employee: " << foreName << " " << surname << std::endl;
    }

    void updateEmployee() {

        std::cout << "Updating employee: " << foreName << " " << surname << std::endl;
    }
};

class Task {
public:
    int taskID;
    int projectID;
    int employeeID;
    std::string accountManager;
    std::string title;
    std::string startDate;
    std::string targetEndDate;
    std::string maxEffortPriority;
    std::string taskDescription;
    std::string username;
    std::string password;
    std::string versionNumber;
    std::string localWebsite;
    std::string liveWebsite;
    int likes;
    int dislikes;
    std::string taskStatus;

    void selectTask() {
        
        std::cout << "Selecting task: " << title << std::endl;
    }

    void addTask() {
        std::cout << "Adding task: " << title << std::endl;
    }

    void deleteTask() {
        
        std::cout << "Deleting task: " << title << std::endl;
    }

    void updateTask() {
        
        std::cout << "Updating task: " << title << std::endl;
    }

    void listPriorityTasks() {
        
        std::cout << "Listing priority tasks" << std::endl;
    }

    void listUnassignedTasks() {
   
        std::cout << "Listing unassigned tasks" << std::endl;
    }
};

class Document {
public:
    int documentID;
    int projectID;
    int taskID;
    std::string filePath;
    std::string documentName;
};

int32_t main(){

    Customer customer1;
    customer1.customerID = 1;
    customer1.companyName = "ABC Inc.";
    customer1.addCustomer();

    Project project1;
    project1.projectID = 101;
    project1.customerID = 1;
    project1.projectName = "Website Redesign";
    project1.addProject();

    Employee employee1;
    employee1.employeeID = 1001;
    employee1.foreName = "John";
    employee1.surname = "Doe";
    employee1.addEmployee();

    Task task1;
    task1.taskID = 10001;
    task1.projectID = 101;
    task1.employeeID = 1001;
    task1.title = "Front-end Development";
    task1.addTask();

    Document document1;
    document1.documentID = 100001;
    document1.projectID = 101;
    document1.taskID = 10001;
    document1.documentName = "Design Mockup";
    

    task1.listPriorityTasks();
    task1.listUnassignedTasks();

    return 0;
}
