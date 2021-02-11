// compile: g++ -std=c++11 -o pointers pointers.cpp
//Michael Kohorst
//2/11/2021
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Student {//struct for student
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;

    student.f_name = new char[128];
    student.l_name = new char[128];
    
    // Sequence of user input -> store in fields of `student`
    student.id = promptInt("Please enter the student's id number:",0,1000000000);//Ask for student ID and can have max 9 digits

    std::cout << "Please enter the student's first name: ";//Asks for name and can be 128 character long
    std::cin.getline(student.f_name,128);

    std::cout << "Please enter the student's last name: "; //Asks for last name and can be 128 character long
    std::cin.getline(student.l_name,128);

    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 1 , 134217728);//prompts for number assignments
    student.grades = new double[student.n_assignments];
    for(int i = 0; i < student.n_assignments; i++)//Run through each assignment and prompts an input.
    {
        std::string colon = ": ";
        std::string numb = std::to_string(i);
        std::string message = "Please enter grade for assignment " + numb + colon;//Concatennation for this message
        student.grades[i]= promptDouble(message, 0, 1000.0);
    }

    // Call `CalculateStudentAverage(???, ???)`
    std::cout << "Student:" << student.f_name << " " << student.l_name << " [" << student.id << "]";
    average = student.n_assignments;
    calculateStudentAverage(student.grades, &average);
    // Output `average`
    std::cout << "\nAverage grade: " << average;
    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/ 
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int
    int promptedInt = 0;
    int valid = 0;//Once this is valid it will be sent through
    std::string input;
    while(valid == 0)//once this is valid it is sent through
    {
        valid = 1;
        std::cout << message;//Takes in message
        std::cin >> input;
        std::cin.ignore();

        for(int i = 0; i < input.length(); i++)//checks if digits
        {
            if(isdigit(input[i]) == false)
            {
                
                valid = 0;
           }
        }

        if(valid == 1)//checks if between max and min
        {
           promptedInt = stoi(input);
            if(promptedInt > max || promptedInt < min)
           {
              valid = 0;
            }
        }

        if(valid == 0)//if not valid
        {
          std::cout << "Sorry I cannot understand your answer\n";
        }
   } 

   return promptedInt;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
    double promptedD;
    int valid = 0;
    int decimalCheck;
    std::string input;
    while(valid == 0)//Runs through to check if valid entry
    {
        decimalCheck = 0;//Only one decimal allowed
        valid = 1;
        std::cout << message;
        std::cin >> input;
        std::cin.ignore();

        for(int i = 0; i < input.length(); i++)//checks if int
        {
            if(isdigit(input[i]) == false)
            {
                if(input[i] == '.' && decimalCheck == 1)
                {
                    valid = 0; 
                }
                else if(input[i] == '.' && decimalCheck == 0)
                {
                    decimalCheck = 1;
                }
                else
                {
                  valid = 0;  
                }
                
           }
        }

        if(valid == 1)//checks if between max and min
        {
           promptedD = stod(input);
            if(promptedD > max || promptedD < min)
           {
              valid = 0;
            }
        }

        if(valid == 0)//if not valid
        {
          std::cout << "Sorry I cannot understand your answer\n";
        }
   } 

   return promptedD;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
    double* grades = (double*) object;
    double sum = 0;
    int size = (int)(*avg);
    for(int i = 0; i < size; i++)
    {
        sum = grades[i] + sum;
    }
    sum = sum/size;//Moves it up and rounds then moves back down to round to the tenth.
    sum = sum *10;
    sum = round(sum);
    sum = sum/10; 
    *avg = sum;

    
}
