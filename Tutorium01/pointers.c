#include <stdio.h>
#include <stdint.h>

typedef struct {char *name; int age; } Person;
void foo(Person *p) {
	printf("%s is %d years old\n", p->name, (*p).age); // -> is just a bit of syntax sugar
}
void bar(Person people[], size_t count) {
	for(size_t i = 0; i < count; i++) {
		printf("%s is %d years old\n", people[i].name, (people + i)->age);
	}
}

int main() {
    Person p = {"John", 42};
    foo(&p);
    Person people[] = {{"John", 42}, {"Jane", 43}};
    bar(people, 2);
}
