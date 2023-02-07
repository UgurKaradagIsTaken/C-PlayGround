//
//  main.cpp
//  Giraffe
//
//  Created by apple on 2.02.2023.
//
#include <cmath>
#include <iostream>
using namespace std;


class AbstractEmployee {
    
    virtual void askForPromotion()=0;
};


class Employee: AbstractEmployee {
protected:
    string name;
        string company;
        int age;
        
public:
    

    
    
    void introduceYourself() {
        cout << "Name " << name << endl;
        cout << "Company " << company << endl;
        cout << "Age " << age << endl;
    }
    Employee(string aName, string aCompany, int aAge) {
        name = aName;
        company = aCompany;
        age = aAge;
        
    }
    void setName(string aName) {
        name = aName;
    }
    string getName() {
        return name;
    }
    void setCompany(string aCompany) {
        company = aCompany;
    }
    string getCompany() {
        return company;
    }
    void setAge(int aAge) {
        if(aAge >= 18) {
            age = aAge;
        }
        
    }
    int getAge() {
        return age;
    }
    
    void askForPromotion() {
        if(age > 30) {
            cout << name << " got promoted !!" << endl;
        }else {
            cout << "Sorry " << name << " no promotion for you" << endl;
        }
    }
    
    virtual void work() {
        cout << name << " is checking email, task backlog, performing tasks" << endl;
    }
    
    
};


class Developer: public Employee {
  
public:
    string favoriteProgrammingLanguage;
    
    Developer(string aName, string aCompany, int aAge, string favProgramminglanguage):Employee(aName, aCompany, aAge) {
        favoriteProgrammingLanguage = favProgramminglanguage;
    }
    void fixBug() {
        cout << getName() << " fixing the bug using " << favoriteProgrammingLanguage << endl;
    }
    void work() {
        cout << name << " is writing " << favoriteProgrammingLanguage << " code" <<endl;
    }
};

class Teacher: public Employee {
public:
    string subject;
    void prepareLesson() {
        cout << name << " is preparing" << subject << " lesson " << endl;
    }
    Teacher(string aName, string aCompany, int aAge, string aSubject):Employee(aName, aCompany, aAge) {
        subject = aSubject;
    }
    void work() {
        cout << name << " is teaching" << subject << endl;
    }
};

int main(int argc, const char * argv[]) {
    Employee employee1 = Employee("Saldina" ,"YT-CodeBeauty", 25);
    employee1.introduceYourself();
    Employee employee2 = Employee("John", "Amazon", 35);

    employee2.introduceYourself();
    //employee1.setAge(52);
    cout << employee1.getName() << " is " << employee1.getAge() << " years old " << endl;
    
    employee1.askForPromotion();
    employee2.askForPromotion();
    Developer d = Developer("Ugur", "Ritmus", 21, "C++");
    d.fixBug();
    d.askForPromotion();
    Teacher t = Teacher("Jack","CoolSchool",35,"History");
    t.prepareLesson();
    t.askForPromotion();
    d.work();
    t.work();
    
    Employee* e1 = &d;
    Employee* e2 = &t;
    Employee* e3 = &d;
    employee1.work();
    e1->work();
    e2->work();
    
    e3->askForPromotion();
    e3->introduceYourself();
    
    /*
     class Chef {
     public:
         void makeChicken() {
             cout << "The chef makes chicken" << endl;
         }
         
         void makeSalad() {
             cout << "The chef makes salad" << endl;
         }
         void makeSpecialDish() {
             cout << "The chef makes bbq ribs" << endl;
         }
     };

     class ItalianChef : public Chef {
     public:
         void makePasta() {
             cout << "The chef makes pasta";
         }
         void makeSpecialDish() {
             cout << "The chef makes chicken parm" << endl;
         }
         
     };




     class Movie {
     private:
         string rating;
     public:
         
         string title;
         string director;
         
         
         Movie(string aTitle, string aDirector, string aRating) {
             title = aTitle;
             director = aDirector;
             setRating(aRating);
             
         }
         void setRating(string aRating) {
             if(aRating == "G" || aRating == "PG" || aRating == "PG-13" || aRating == "NR") {
                 rating = aRating;
                 
             }else {
                 rating = "NR";
             }
         }
         string getRating() {
             return rating;
         }
         
         
         
     };





     class Student {
         
     public:
         
         string name;
         string major;
         double gpa;
         
         Student(string aName, string aMajor, double aGpa) {
             name = aName;
             major = aMajor;
             gpa = aGpa;
         }
         
         bool hasHonors() {
             
             if(gpa >= 3.5) {
                 return true;
             }else {
                 return false;
             }
         }
         
     };




     class Book {
     public:
         string title;
         string author;
         int pages;
         
         Book() {
             title = "no title";
             author = "no author";
             pages = 0;
         }
         
         
         Book(string aTitle, string aAuthor, int aPage) {
             
             title = aTitle;
             author = aAuthor;
             pages = aPage;
         }
         
         
         
     };















     string getDayOfWeek(int dayNum) {
         string dayName;
         
         switch(dayNum) {
             case 0:
                 dayName = "Sunday";
                 break;
             case 1:
                 dayName = "Monday";
                 break;
             case 2:
                 dayName = "Tuesday";
                 break;
             case 3:
                 dayName = "Wednesday";
                 break;
             case 4:
                 dayName = "Thursday";
                 break;
             case 5:
                 dayName = "Friday";
                 break;
             case 6:
                 dayName = "Saturday";
                 break;
             default:
                 dayName = "Invalid day number";
         }
         
         
         return dayName;
     }



     int power(int baseNum, int powNum) {
         int result = 1;
         
         
         for(int i = 0; i < powNum; i++) {
             result = result * baseNum;
         }
         
         
         return result;
         
     }




     double cube(double num) {
         return  num * num * num;
     }

     int getMax(int num1, int num2, int num3) {
         int result;
         
         if(num1 >= num2 && num1 >= num3) {
             result = num1;
         }else if(num2 >= num1 && num2 >= num3) {
             result = num2;
         }else {
             result = num3;
         }
         
         return result;
     }
     void sayHi(string name, int age);
    string characterName = "Joel Miller";
    int characterAge;
    characterAge = 43;
    
    
    // insert code here...
    cout << "Hello, World!\n" << endl;
    cout << "My name is Ugur" << endl;
    
    
    
    cout << "There once was a man named " << characterName << endl;
    cout << "He was " << characterAge << " years old" << endl;
    
    characterName = "Walter";
    cout << "He liked the name " << characterName << endl;
    cout << "But he did not like being " << characterAge << endl;
    
    
    
    char grade = 'A';
    
    int age = 50;
    double gpa = 2.89;
    bool isAlone = true;
    bool isMale = true;
    
    cout <<grade << endl;
    
    string phrase = "Giraffe Academy";
    cout << phrase.length() << endl;
    cout << phrase.find("ffe", 0) << endl;
    cout << phrase.substr(8,7) << endl;
    string phrasesub;
    phrasesub = phrase.substr(8,3);
    cout << phrasesub;
    
    cout << -40 << endl;
    
     
    cout << (4 + 5) * 2 << endl;
    int wnum = 5;
    double dnum = 5.5;
    wnum++;
    wnum += 80;
    cout << 10.0 / 3.0 << endl;
    
     
    cout << fmin(200, 4) << endl;
    
     
    
    
    
    char age;
    cout << "Enter your age : ";
    cin >> age;
    
    cout << "You are " << age << " years old" << endl;
     
    string name;
    cout << "Enter your name : ";
    //for string use the command called getline simple as that
    getline(cin, name);
    cout << "Hello " << name << endl;
    
    
    double num1, num2;
    cout << "Enter the first number : ";
    cin >> num1;
    cout << "Enter the second number : ";
    cin >> num2;
    
    cout << num1 + num2 << endl;
     
    string color, pluralNoun, celebrity;
    cout << "Enter a color :";
    getline(cin, color);
    cout << "Enter a plural noun :";
    getline(cin, pluralNoun);
    cout << "Enter a celebrity :";
    getline(cin, celebrity);
    
    cout << "Roses are " << color << endl;
    cout << pluralNoun << " are blue" << endl;
    cout << "I love " <<celebrity << endl;
     
     
    
    
    
    int luckyNums[20] = {4,8,34,64,78,33};
    luckyNums[10] = 61;
    cout << luckyNums[10];
     
    cout << "Top" << endl;
    sayHi("Mike",31);
    sayHi("Steve",69);
    sayHi("Mike",31);
    cout << "Bottom" << endl;
    
    return 0;
     
    
}
void sayHi(string name, int age) {
    cout << "Hello " << name << " You are " << age << endl;
     
    
    double answer = cube(5.0);
    cout << answer << endl;
    cout << cube(2) << endl;
    
    bool isMale = true;
    bool istall = true;
    if(isMale && istall) {
        cout << "You are attractive" << endl;
    }else if(isMale && !istall) {
        cout << "Short king!! like me ";
    }else if(!isMale && istall) {
        cout << "Even better :D ";
    }
    
    else {
        cout << "You are nothing :P ";
    }
     
    
    
    cout << getMax(200, 200,99) << endl;
     
    
    
    int num1, num2;
    char op;
    
    cout << "Enter the first number :";
    cin >> num1;
    cout << "Enter the operator : ";
    cin >> op;
    cout << "Enter the second number : ";
    cin >> num2;
    
    int result;
    if(op == '+') {
        result = num1 + num2;
    }else if(op == '-') {
        result = num1 - num2;
    }else if(op == '/') {
        result = num1 / num2;
    }else if(op == '*') {
        result = num1 * num2;
    }else {
        cout << "Invalid operator";
    }
    cout << result;
     
    
    
    cout << getDayOfWeek(0) << endl;
    
     
    
    
    int index = 1;
    while(index <= 5) {
        cout << index << endl;
        index++;
    }
     
    int index = 9;
    
    do {
        cout << index << endl;
        index++;
        
    }while(index < 7);
    
     
    
    
    int secretNum = 7;
    
    int guess;
    int guessCount;
    int guessLimit = 3;
    bool outOfGuesses = false;
    while(secretNum != guess && !outOfGuesses) {
        if(guessCount < guessLimit) {
            cout << "Enter guess: ";
            cin >> guess;
            guessCount++;
        }else {
            outOfGuesses = true;
        }
        
    }
    if(outOfGuesses) {
        cout << "You lose!" << endl;
    }else {
        cout << "You win!!" << endl;
    }
    
     
    
    int index = 1;
    for(int i = 1; i < 5; i++) {
        cout << i << endl;
    }
     
    int nums[] = {1,2,3,4,5,6};
    
    for(int i = 0; i < 6; i++) {
        cout << nums[i] << endl;
    }
     
    cout << power(2, 3) << endl;
    
     
    
    int numberGrid[3][2] = {
        {1,2},
        {3,4},
        {5,6}
        
        
        //Let's use the comments
        //Describing the line of the code !
        
        
        
    };
    cout << numberGrid[2][0] << endl;
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            cout << numberGrid[i][j];
        }
        cout << endl;
    }
    
     
    
    int age = 19;
    int *pAge = &age;
    double gpa = 2.7;
    double *pGpa = &gpa;
    string name = "Mike";
    string *pName = &name;
    
    
    cout << &*&age << endl;
    cout << *pAge << endl;
    
    cout << pAge << endl;
    cout << &age << endl;
    cout << &name << endl;
    cout << &gpa << endl;
    
    
    string name = "Mike";
    double pi = 3.14;
    char favoriteLetter = 'G';
     
    
    
    Book book1("Harry Potter", "JK Rowling", 500);

    
    Book book2("Lord Of the Rings" , "Tolkien" , 800);

    book1.title = "Ugur";
    cout << book1.title << endl;
    Book book3;
    cout << book3.title << endl;
     
    Student student1("Jim", "Business", 2.4);
    Student student2("Pam", "Art", 3.6);
    
    
    
    
    cout << student1.hasHonors() << endl;
    cout << student2.hasHonors() << endl;
    
    Movie avengers("The Avengers", "Joss Whendon", "PG-13");
    avengers.setRating("PG");
    cout << avengers.getRating() << endl;
    Chef chef;
    chef.makeChicken();
    ItalianChef italianChef;
    italianChef.makeChicken();
    italianChef.makePasta();
    italianChef.makeSpecialDish();
     */
    
    return  0;
    
    
    
    
}
