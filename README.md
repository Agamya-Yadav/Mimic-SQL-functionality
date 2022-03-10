<div align="center">
  <h1>Mimic-SQL-functionality</h1>
</div>

---

## Overview
A menu driven application written in C++ to parse and execute SQL like queries with limited functionality. <br>
Supports queries to fetch data from the given tables (Student database).
<br />

## Tables
Data is fetched from <TABLE_NAME>.txt file. Various supported tables are as follows,
- *csestudents* : RollNo, StudentName
- *grades* : RollNo, CourseID, Grade (Grade in [A+, A-, B+, B-, C+, C-])
- *courses*: CourseID, CourseName

<br />

## Queries supported
The following queries are supported,
1. "SHOW csestudents/courses/grades"; It will show all the records of the file row wise in the same order it appears in the file.
2. "SHOW <TABLE_NAME> SORTBY <COLUMN_NAME>"; It will sort the records based on the column name of the file, and show all the records row wise. Implemented using MergeSort.
3. "SHOW <TABLE_NAME> WHERE <COLUMN_NAME>=<COLUMN_VALUE>"; It will show all the fields of the selected records. 
4. "SHOW CourseID=<COURSE_ID>"; It will show all students' roll numbers, names, and grades in the course identified by <COURSE_ID>.
5. "CLEAR"; Clear the console.
6. "QUIT"; Exit the program.

<br />

## Setting up and running the project locally
1. Clone this repository and go into the repo folder
```
cd Mimic-SQL-functionality
```
2. Compile the *source.cpp* file using,
```
g++ source.cpp -o source 
```
3. Run the program using,
```
./source
```

**Note:** Please make sure to populate the tables with appropriate data before running the program.
