%:include<stdio.h>

int main(void) <%
    int array<::> = <% 1, 2, 3, 4, 5 %>;
    printf("Hello World: the second element of array is %d\n", array<:1:>);
    return 0;
%>
