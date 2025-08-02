### Project Overview
This is a simple Student Record Management System built in C. It allows adding, viewing, updating, deleting, and searching student records. The system uses file handling to store data persistently in a binary file, simulating a backend school database.

### Features
- Add new student records (Name, Roll Number, Grade).
- View all students stored in the system.
- Search for a student by roll number.
- Update student information.
- Delete student records.
- User-friendly menu-driven interface.
- Persistent data saved in a binary file.

### Technologies Used
- C programming language
- File handling using binary files (fopen, fread, fwrite, etc.)
- Structures (struct Student) for organizing student data
- Modular programming with functions for each operation

### How to Run
Prerequisites
- C compiler (e.g., GCC)
- Terminal or command prompt

### Compile the program
```bash
gcc student_record_system.c -o student_record_system
```

## Run the program
```bash
./student_record_system
```
## Usage
On running, a menu appears:
```text
1. View all students
2. Add Student
3. Delete Student
4. Update Student
5. Search Student
6. Exit
```
Enter the number for the desired action and follow prompts.

### File Information
Student records are stored in students.txt as binary data. This allows data to persist between runs of the program.

### Project Structure
- student_record_system.c — The source code
- students.txt — Data file created/updated by the program (not included in repo)

### Future Improvements
- Input validation improvements
- Handling duplicate roll numbers 
- Add sorting and exporting functionality
- GUI or database integration
