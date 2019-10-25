//This program creates a student list, where a user can add remove and print out the number of students
//Author: Mark Daniloff
//10/10/2019

#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctype.h>
#include <stdio.h>
#include <cctype>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <iomanip>

using namespace std;

//Initialize functions and structs
struct Student {
  char fname[10];
  char lname[10];
  int id;
  float gpa;
}; 
void addStudent(vector<Student*>* v);
void delStudent(vector<Student*>* v);
void printStudent(vector<Student*>* v);
int main()
{
  vector<Student*> *v = new vector<Student*>();
  Student* s = new Student;
  char input[7];
  int n = 0;
    cout << "Type in ADD to add students, DELETE to delete students, PRINT to print students, and QUIT to quit. " << endl;
   while (strcmp(input, "QUIT") != 0) {
     cin.get(input, 8);
    //ADD
    if (strcmp(input, "ADD") == 0) {
      addStudent(v);
    }
    //DELETE
    if (strcmp(input, "DELETE") == 0) {
      delStudent(v);    
    }
    //PRINT
    if (strcmp(input, "PRINT") == 0) {
      printStudent(v);
      cin.ignore();
    }
    //ELSE
    else {
      cout << "Please enter ADD, DELETE, PRINT, or QUIT." << endl;
    } 
  }
  //QUIT
  if (strcmp(input, "QUIT") == 0) {
    
  }
}
//Method to add student
void addStudent(vector<Student*> *v) {
  Student* s = new Student;
  cout << "First name: " << endl;
  cin >> s->fname;
  cin.ignore();
  cout << "Last name: " << endl;
  cin >> s->lname;
  cin.ignore();
  cout << "ID: " << endl;
  cin >> s->id;
  cin.ignore();
  cout << "GPA: " << endl;
  cin >> s->gpa;
  cin.ignore();
  //Goes to next empty space in vector
  v->push_back(s);
}

//Method to delete student
void delStudent(vector<Student*> *v) {
  int id;
  cout << "Enter student id: " << endl;
  cin >> id;
  cin.ignore();
  //Go through vector with an iterator and see which student that id corresponds to and delete that student
  vector <Student*>::iterator it;
  int i = 0;
  for (it = v->begin(); it != v->end(); it++) {
    if ((*it)->id == id) {
      delete *it;
      v -> erase(it);
      break;
    }
  }
}

//Method to print student
void printStudent(vector<Student*> *v) {
  //Create iterator and go through vector and print out the name id and gpa of each student in the struct
  vector <Student*>::iterator it;
  int i = 0;
  for (it = v->begin(); it != v->end(); it++) {
    cout << "Name: " << (*it)->fname << " " << (*it)->lname << endl;
    cout << "ID: " << (*it)->id << endl;
    cout << std::setprecision(3) << "GPA: " << (*it)->gpa << endl;
  }
   cout << "Please enter ADD, DELETE, PRINT, or QUIT." << endl;
}
