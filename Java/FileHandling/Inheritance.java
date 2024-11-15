class Employee{
  String name;
  int age;
  String phoneNumber;
  String address;
  long salary;

  Employee(String name, int age, String phoneNumber, String address, long salary){
    this.name=name;
    this.age=age;
    this.phoneNumber = phoneNumber;
    this.address = address;
    this.salary = salary;
  }

  void display(){
    System.out.println("Name:"+name+" Age:"+age+" PhoneNumber:"+phoneNumber+" Address"+address);
  }

  void printSalary(long salary){
    System.out.println("The salary is:"+salary);
  }

}

class Officer extends Employee{
  String specialization;


  Officer(String name, int age, String phoneNumber, String address, long salary,String specialization){
    super(name, age, phoneNumber, address, salary);
    this.specialization=specialization;
    display();
    printSalary(salary);
  }
  
 

}

class Manager extends Employee{
  String department;


  Manager(String name, int age, String phoneNumber, String address, long salary,String department){
    super(name, age, phoneNumber, address, salary);
    this.department=department;
    display();
    printSalary(salary);
  }

}


public class Inheritance {
  public static void main(String[] args){
    Officer off=new Officer("Sree",40,"8111834242","London",90000,"Software Developer");
   

    


  }
  
}
