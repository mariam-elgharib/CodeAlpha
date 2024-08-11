#include <iostream>
#include <string>
using namespace std;

struct Course {
	int creds;
	int grade;
};
struct Semester {
	double gpa;
	int numcourses;
	Course* courses;
};

double getGradePoint(int grade) {
	if (grade >= 90) return 4.0;
	if (grade >= 80) return 3.0;
	if (grade >= 70) return 2.0;
	if (grade >= 60) return 1.0;
	return 0.0;
}

void inputdetails(int courses, int numsem, Semester& s) {
	s.numcourses = courses;
	for (int course = 0; course < courses; course++) {
		int percentage = 0;
		cout << "Enter credits for course" << (course + 1) << ":";
		cin >> s.courses[course].creds;
		cout << "Enter grade for course" << (course + 1) << ":";
		cin >> percentage;
		double gradee = getGradePoint(percentage);
		s.courses[course].grade = gradee;
	}

}

void calcGPA(Semester& s) {
	double totalGradePoints = 0.0;
	int totalCredits = 0;

	for (int i = 0; i < s.numcourses; i++) {
		totalGradePoints += s.courses[i].grade * s.courses[i].creds;
		totalCredits += s.courses[i].creds;
	}

	if (totalCredits > 0) {
		s.gpa = totalGradePoints / totalCredits;
	}
	else {
		s.gpa = 0.0;
	}
}

double calcCGPA(Semester semesters[], int numSemesters) {
	double totalGradePoints = 0.0;
	int totalCredits = 0;

	for (int i = 0; i < numSemesters; i++) {
		int semesterCredits = 0;
		double semesterGradePoints = 0.0;

		for (int j = 0; j < semesters[i].numcourses; j++) {
			semesterCredits += semesters[i].courses[j].creds;
			semesterGradePoints += semesters[i].courses[j].grade * semesters[i].courses[j].creds;
		}

		totalCredits += semesterCredits;
		totalGradePoints += semesterGradePoints;
	}

	if (totalCredits > 0) {
		return totalGradePoints / totalCredits;
	}
	else {
		return 0.0;
	}
}

int main()
{
	int semesters = 0;
	cout << "Enter the number of semesters : ";
	cin >> semesters;
	while (semesters <= 0) {
		cout << "Invalid Input! Enter a positive integer : ";
		cin >> semesters;
	}
	Semester* semesterss = new Semester[semesters];

	for (int sem = 0; sem < semesters; sem++) {
		int courses = 0;
		cout << "Enter the number of courses of semester" << (sem + 1) << ':';
		cin >> courses;
		while (courses <= 0) {
			cout << "Invalid Input! Enter a positive integer : ";
			cin >> courses;
		}

		semesterss[sem].courses = new Course[courses];

		inputdetails(courses, sem, semesterss[sem]);
		calcGPA(semesterss[sem]);
		cout << "GPA for semester " << (sem + 1) << ": " << semesterss[sem].gpa << endl;
	}

	double cgpa = calcCGPA(semesterss, semesters);
	cout << "Overall CGPA: " << cgpa << endl;

	return 0;
}
