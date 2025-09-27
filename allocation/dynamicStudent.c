#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student {
    int id;
    char name[50];
    float gpa;
} Student;

typedef struct student_array {
    Student* students;
    int count;
    int capacity;
} Student_array;

int add_student(Student_array* arr, float gpa, char name[50], int id) {
    if (arr->count >= arr->capacity) {
        printf("array full \n");
        arr->capacity = 2* arr->capacity;
        arr->students = (Student*) realloc(arr->students, arr->capacity * sizeof(Student));
        if (arr->students == NULL) {
            return -1;
        }
        printf("done \n");
    }
    Student stdent;
    stdent.gpa = gpa;
    stdent.id=id;
    strncpy(stdent.name, name, sizeof(stdent.name) - 1);

    arr->students[arr->count] = stdent;
    arr->count++;
    return arr->count;
}

int remove_student(Student_array* arr, int index) {
    if (index< 0 || index > arr->count) {
        return -1;
    }

    for (int i=index; i<arr->count; i++) {
        arr->students[i] = arr->students[i+1];
    }
    arr->count--;
    arr->students = realloc(arr->students, arr->count * sizeof(Student));
    if (arr->count == 0 || arr->students == NULL) {
        return -1;
    }
    return arr->count;
}

Student_array* init_array(int capacity) {
    if (capacity <= 0) {
        capacity = 1;
    }

    Student* student = (Student* ) calloc(capacity, sizeof(Student));
    if (student == NULL) {
        return NULL;
    }

    Student_array* arr = (Student_array*) malloc(sizeof(Student_array));
    if (arr == NULL) {
        free(student);
        return NULL;
    }
    arr->count=0;
    arr->capacity=capacity;
    arr->students=student;
    return arr;
} 

void printStudent(const Student_array *arr) {
    printf("Students list %d:\n", arr->count);
    printf("Students capacity %d:\n", arr->capacity);
    for (size_t i = 0; i < arr->count; i++) {
        printf("%d: %s, GPA: %.2f\n", arr->students[i].id,
               arr->students[i].name,
               arr->students[i].gpa);
    }
}

void freeArray(Student_array *arr) {
    free(arr->students);
    arr->students = NULL;
    arr->count = 0;
}

int main() {

    Student_array* arr = init_array(1);
    if (arr == NULL) {
        printf("not allocated \n");
    }
    printStudent(arr);
    int std1 = add_student(arr, 7, "bruh", 1);
    if (std1 == -1) {
        printf("error adding %d\n", std1);
    }
    printStudent(arr);
    int std2 = add_student(arr, 9, "aj", 2);
    if (std2 == -1) {
        printf("error adding %d\n", std2);
    }
    printStudent(arr);
    int std3 = add_student(arr, 10.01, "har", 3);
    if (std3 == -1) {
        printf("error adding %d\n", std3);
    }
    printStudent(arr);

    int rstd1 = remove_student(arr, 2);
    if (rstd1 == -1) {
        printf("error removing %d\n", rstd1);
    }
    printStudent(arr);

    freeArray(arr);
    return 0;
}