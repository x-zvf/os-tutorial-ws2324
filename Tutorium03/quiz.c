/* All of these things are valid, standards conforming C code */
#include<stdio.h>

int arr[10] = {1,2,3,4,5,6,7,8,9,10};

/* Declaration specifiers have no defined order:
 * this is equivalent to:
 * static volatile unsigned long long l = 4;
 * Although GCC does have -Wold-style-declaration (K&R style), which warns about
 * static and typedef not being at the start of the declaration.
 */
long static volatile long unsigned l = 4;

struct {
    int a;
    int b;
} typedef S;


/* C11 standard, 6.5.2.3/6:
 * One special guarantee is made in order to simplify the use of unions: if a union contains
several structures that share a common initial sequence (see below), and if the union
object currently contains one of these structures, it is permitted to inspect the common
initial part of any of them anywhere that a declaration of the completed type of the union
is visible. Two structures share a common initial sequence if corresponding members
have compatible types (and, for bit-fields, the same widths) for a sequence of one or more
initial members. */

enum EventKind {
    MOUSE,
    KEYBOARD
};

union Event {
    enum EventKind kind; 
    struct Mouse {
        enum EventKind kind;
        unsigned int x;
        unsigned int y;
    } mouse;
    struct Key {
        enum EventKind kind;
        unsigned int code;
    } key;
};

int main()
{
    /* Array access is defined to be equivalent to pointer arithmetic:
     * a[i] == *(a + i)
     * Addition is commutative, so:
     * *(a + i) == *(i + a)
     * therefore:
     * a[i] == i[a]
     */
    /* C11 standard: 6.5.2.1.2: the definition of the subscript operator []
is that E1[E2] is identical to (*((E1)+(E2))). Because of the conversion rules that
apply to the binary + operator, if E1 is an array object (equivalently, a pointer to the
initial element of an array object) and E2 is an integer, E1[E2] designates the E2-th
element of E1 (counting from zero). */
    printf("%d\n", 3[arr]);

    printf("%lld\n", l);

    S s = {1,2};
    printf("%d\n", s.a);

    short a = 1;
    printf("%zu\n", sizeof(+a)["123456"]);
    /*
     * One would think: Unary + => integer promotion; => sizeof(int)["123456"] => "123456"[4] => 5
     * but sizeof has higher precedence than [], so it's actually equivalent to:
     * sizeof( (+a)["123456"] ) => sizeof( "123456"[1] ) => sizeof( '2' ) => 1
     */

    printf("%c\n", "abcdefg"<:3:>);
    // with -trigraphs : printf("%c\n", "abcdefg"??(3??));

    return 0;
}
