#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float marks[5];
    float total;
    float average;
    char grade;
};

char calculateGrade(float avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 75) return 'B';
    else if (avg >= 60) return 'C';
    else if (avg >= 50) return 'D';
    else return 'F';
}

int main() {
    int n, i, j;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].name);   // safer: no spaces in name for now

        s[i].total = 0;
        for (j = 0; j < 5; j++) {
            printf("Marks in Subject %d: ", j + 1);
            scanf("%f", &s[i].marks[j]);   // correctly stores marks
            s[i].total += s[i].marks[j];
        }

        s[i].average = s[i].total / 5.0;
        s[i].grade = calculateGrade(s[i].average);
    }

    printf("\n=========== REPORT CARD ===========\n");
    printf("Roll\tName\tTotal\tAverage\tGrade\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\t%.2f\t%c\n",
               s[i].roll, s[i].name, s[i].total, s[i].average, s[i].grade);
    }

    return 0;
}