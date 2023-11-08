#include <stdio.h>
typedef struct {
    char *name;
    int age;
} Person;

void foo(Person p) {
	p.age = 100;
	printf("Age in foo: %d\n", p.age);
}
void bar(Person *p) {
	p->age = 200;
	printf("Age in bar: %d\n", p->age);
}
int main(void) {
	Person p = {.name = "Me", .age = 20};
	printf("Age in main: %d\n", p.age);
	foo(p);
	printf("Age in main: %d\n", p.age);
	bar(&p);
	printf("Age in main: %d\n", p.age);
}
