#include <stdio.h>
#include <stdlib.h>
#include "container.h"

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define WHT "\x1B[37m"
#define CYN "\x1B[36m"

int test_dup1(int print) {
    //String vacio.
    if (print)
        printf("\n%sString vacio\n", CYN);

    char* dup;
    int size = dupStr("", &dup);
    if (equalStr(dup, "") && size == 0) {
        free(dup);
        return 1;
    }
    free(dup);
    return 0;
}

int test_dup2(int print) {
    //String de un caracter
    if (print)
        printf("\n%sString de un caracter\n", CYN);

    char* dup;
    int size = dupStr("a", &dup);
    if (equalStr(dup, "a") && size == 1) {
        free(dup);
        return 1;
    }
    free(dup);
    return 0;
}

int test_dup3(int print) {
    //String que incluya todos los caracteres validos distintos de cero
    if (print)
        printf("\n%sString que incluya todos los caracteres validos distintos de cero\n", CYN);

    char* dup;

    char s[95];
    for (int i = 32; i < 127; i++) {
        if ((char)i != 0) {
            s[i - 32] = i;
        }
    }
    char s2[95];
    for (int i = 32; i < 127; i++) {
        if ((char)i != 0) {
            s2[i - 32] = i;
        }
    }

    int size = dupStr(s, &dup);
    //size == 96 for macOS
    if (equalStr(dup, s2) && size == 95) {
        free(dup);
        return 1;
    }
    free(dup);
    return 0;
}

int test_equalStr1(int print) {
    //Dos strings vacios

    char* s1 = "";
    char* s2 = "";

    if (print) {
        printf("%sDos strings vacios\n", CYN);
        printf("%s \"%s\" == \"%s\"", WHT, s1, s2);
    }

    return equalStr(s1, s2);
}

int test_equalStr2(int print) {
    //Dos strings iguales

    char* s1 = "hola";
    char* s2 = "hola";

    if (print) {
        printf("%sDos strings iguales\n", CYN);
        printf("%s \"%s\" == \"%s\"", WHT, s1, s2);
    }

    return equalStr(s1, s2);
}

int test_equalStr3(int print) {
    //Dos strings diferentes

    char* s1 = "hola";
    char* s2 = "chau";

    if (print) {
        printf("%sDos strings diferentes\n", CYN);
        printf("%s \"%s\" == \"%s\"", WHT, s1, s2);
    }

    return !equalStr(s1, s2);
}

int test_cmpStr1(int print) {
    //Dos string vacios
    if (print)
        printf("\n%sDos string vacios\n", CYN);

    char* s1 = "";
    char* s2 = "";

    if (print)
        printf("%s \"%s\" %c \"%s\"\n", WHT, s1, (cmpStr(s1, s2) ? cmpStr(s1, s2) == -1 ? '>' : '<' : '='), s2);

    if (cmpStr(s1, s2) == 0)
        return 1;
    return 0;
}

int test_cmpStr2a(int print) {
    //Dos strings de 1 caracter iguales
    if (print)
        printf("\n%sDos strings de 1 caracter iguales\n", CYN);

    char* s1 = "a";
    char* s2 = "a";

    if (print)
        printf("%s \"%s\" %c \"%s\"\n", WHT, s1, (cmpStr(s1, s2) ? cmpStr(s1, s2) == -1 ? '>' : '<' : '='), s2);

    if (cmpStr(s1, s2) == 0)
        return 1;
    return 0;
}

int test_cmpStr2b(int print) {
    //Dos strings de 1 caracter 'a' < 'b'
    if (print)
        printf("\n%sDos strings de 1 caracter 'a' < 'b'\n", CYN);

    char* s1 = "a";
    char* s2 = "b";

    if (print)
        printf("%s \"%s\" %c \"%s\"\n", WHT, s1, (cmpStr(s1, s2) ? cmpStr(s1, s2) == -1 ? '>' : '<' : '='), s2);

    if (cmpStr(s1, s2) == 1)
        return 1;
    return 0;
}

int test_cmpStr2c(int print) {
    //Dos strings de 1 caracter 'b' > 'a'
    if (print)
        printf("\n%sDos strings de 1 caracter 'b' > 'a'\n", CYN);

    char* s1 = "b";
    char* s2 = "a";

    if (print)
        printf("%s \"%s\" %c \"%s\"\n", WHT, s1, (cmpStr(s1, s2) ? cmpStr(s1, s2) == -1 ? '>' : '<' : '='), s2);

    if (cmpStr(s1, s2) == -1)
        return 1;
    return 0;
}

int test_cmpStr3a(int print) {
    //Strings iguales hasta un caracter
    if (print)
        printf("\n%sStrings iguales hasta un caracter\n", CYN);

    char* s1 = "abc";
    char* s2 = "bbc";

    if (print)
        printf("%s \"%s\" %c \"%s\"\n", WHT, s1, (cmpStr(s1, s2) ? cmpStr(s1, s2) == -1 ? '>' : '<' : '='), s2);

    if (cmpStr(s1, s2) == 1)
        return 1;
    return 0;
}

int test_cmpStr3b(int print) {
    //Strings iguales hasta un caracter
    if (print)
        printf("\n%sStrings iguales hasta un caracter\n", CYN);

    char* s1 = "hula";
    char* s2 = "hola";

    if (print)
        printf("%s \"%s\" %c \"%s\"\n", WHT, s1, (cmpStr(s1, s2) ? cmpStr(s1, s2) == -1 ? '>' : '<' : '='), s2);

    if (cmpStr(s1, s2) == -1)
        return 1;
    return 0;
}

int test_cmpStr4a(int print) {
    //Dos strings diferentes s1 < s2
    if (print)
        printf("\n%sDos strings diferentes s1 < s2\n", CYN);

    char* s1 = "adenosintrifosfato";
    char* s2 = "aristocracia";

    if (print)
        printf("%s \"%s\" %c \"%s\"\n", WHT, s1, (cmpStr(s1, s2) ? cmpStr(s1, s2) == -1 ? '>' : '<' : '='), s2);

    if (cmpStr(s1, s2) == 1)
        return 1;
    return 0;
}

int test_cmpStr4b(int print) {
    //Dos strings diferentes s1 > s2
    if (print)
        printf("\n%sDos strings diferentes s1 > s2\n", CYN);

    char* s1 = "zimbabwe";
    char* s2 = "abecedario";

    if (print)
        printf("%s \"%s\" %c \"%s\"\n", WHT, s1, (cmpStr(s1, s2) ? cmpStr(s1, s2) == -1 ? '>' : '<' : '='), s2);

    if (cmpStr(s1, s2) == -1)
        return 1;
    return 0;
}

int test_cmpStr4c(int print) {
    //Dos strings diferentes s1 < s2 (s2 caps)
    if (print)
        printf("\n%sDos strings diferentes s1 < s2 (s2 caps)\n", CYN);

    char* s1 = "alquitran";
    char* s2 = "BUENAVISTA";

    if (print)
        printf("%s \"%s\" %c \"%s\"\n", WHT, s1, (cmpStr(s1, s2) ? cmpStr(s1, s2) == -1 ? '>' : '<' : '='), s2);

    if (cmpStr(s1, s2) == 1)
        return 1;
    return 0;
}

int test_cmpStr4d(int print) {
    //Dos strings diferentes s1 < s2
    if (print)
        printf("\n%sDos strings diferentes s1 < s2\n", CYN);

    char* s1 = "abc";
    char* s2 = "abcd";

    if (print)
        printf("%s \"%s\" %c \"%s\"\n", WHT, s1, (cmpStr(s1, s2) ? cmpStr(s1, s2) == -1 ? '>' : '<' : '='), s2);

    if (cmpStr(s1, s2) == 1)
        return 1;
    return 0;
}

int test_cmpStr4e(int print) {
    //Dos strings diferentes s1 > s2
    if (print)
        printf("\n%sDos strings diferentes s1 > s2\n", CYN);

    char* s1 = "abcd";
    char* s2 = "abc";

    if (print)
        printf("%s \"%s\" %c \"%s\"\n", WHT, s1, (cmpStr(s1, s2) ? cmpStr(s1, s2) == -1 ? '>' : '<' : '='), s2);

    if (cmpStr(s1, s2) == -1)
        return 1;
    return 0;
}

int test_split1a(int print) {
    //Un string vacio, count = 1
    if (print)
        printf("\n%sUn string vacio, count = 1\n", CYN);

    char* first;
    char* last;
    split("", 1, &first, &last);

    if (print)
        printf("%s\n\"%s\" %i: \"%s\"|\"%s\"\n", WHT, "", 1, first, last);

    return equalStr(first, "") * equalStr(last, "");
}

int test_split1b(int print) {
    //Un string vacio, count = 2
    if (print)
        printf("\n%sUn string vacio, count = 2\n", CYN);

    char* first;
    char* last;
    split("", 2, &first, &last);

    if (print)
        printf("%s\n\"%s\" %i: \"%s\"|\"%s\"\n", WHT, "", 2, first, last);

    return equalStr(first, "") * equalStr(last, "");
}

int test_split1c(int print) {
    //Un string vacio, count = 3
    if (print)
        printf("\n%sUn string vacio, count = 3\n", CYN);

    char* first;
    char* last;
    split("", 3, &first, &last);

    if (print)
        printf("%s\n\"%s\" %i: \"%s\"|\"%s\"\n", WHT, "", 3, first, last);

    return equalStr(first, "") * equalStr(last, "");
}

int test_split2a(int print) {
    //Un string de un caracter, count = 1
    if (print)
        printf("\n%sUn string de un caracter, count = 1\n", CYN);

    char* first;
    char* last;
    split("a", 1, &first, &last);

    if (print)
        printf("%s\n\"%s\" %i: \"%s\"|\"%s\"\n", WHT, "a", 1, first, last);

    return equalStr(first, "a") * equalStr(last, "");
}

int test_split2b(int print) {
    //Un string de un caracter, count = 2
    if (print)
        printf("\n%sUn string de un caracter, count = 2\n", CYN);

    char* first;
    char* last;
    split("a", 2, &first, &last);

    if (print)
        printf("%s\n\"%s\" %i: \"%s\"|\"%s\"\n", WHT, "a", 2, first, last);

    return equalStr(first, "a") * equalStr(last, "");
}

int test_split2c(int print) {
    //Un string de un caracter, count = 3
    if (print)
        printf("\n%sUn string de un caracter, count = 3\n", CYN);

    char* first;
    char* last;
    split("a", 3, &first, &last);

    if (print)
        printf("%s\n\"%s\" %i: \"%s\"|\"%s\"\n", WHT, "a", 3, first, last);

    return equalStr(first, "a") * equalStr(last, "");
}

int test_split3a(int print) {
    // Un string de multiples caracteres, count = 1
    if (print)
        printf("\n%s Un string de multiples caracteres, count = 1\n", CYN);

    char* first;
    char* last;
    split("mostacho", 1, &first, &last);

    if (print)
        printf("%s\n\"%s\" %i: \"%s\"|\"%s\"\n", WHT, "mostacho", 1, first, last);

    return equalStr(first, "m") * equalStr(last, "ostacho");
}

int test_split3b(int print) {
    // Un string de multiples caracteres, count = 2
    if (print)
        printf("\n%s Un string de multiples caracteres, count = 2\n", CYN);

    char* first;
    char* last;
    split("mostacho", 2, &first, &last);

    if (print)
        printf("%s\n\"%s\" %i: \"%s\"|\"%s\"\n", WHT, "mostacho", 2, first, last);

    return equalStr(first, "mo") * equalStr(last, "stacho");
}

int test_split3c(int print) {
    // Un string de multiples caracteres, count = 3
    if (print)
        printf("\n%s Un string de multiples caracteres, count = 3\n", CYN);

    char* first;
    char* last;
    split("mostacho", 3, &first, &last);

    if (print)
        printf("%s\n\"%s\" %i: \"%s\"|\"%s\"\n", WHT, "mostacho", 3, first, last);

    return equalStr(first, "mos") * equalStr(last, "tacho");
}

int test_sortedAdd1(int print) {
    //Agregar un dato por lista
    if (print)
        printf("\n%sAgregar un dato por lista\n", CYN);

    struct container* c = newContainer();

    sortedAdd(c, "dado");
    sortedAdd(c, "arbol");
    sortedAdd(c, "zorro");
    sortedAdd(c, "caracol");

    if (print)
        printContainer(c);

    if (!equalStr(c->data[0]->data, "dado"))
        return 0;
    if (!equalStr(c->data[1]->data, "arbol"))
        return 0;
    if (!equalStr(c->data[2]->data, "zorro"))
        return 0;
    if (!equalStr(c->data[3]->data, "caracol"))
        return 0;
    return 1;

    deleteContainer(c);
}

int test_sortedAdd2(int print) {
    //Sobre el primer caso, agregar un dato mayor a todos por lista
    if (print)
        printf("\n%sSobre el primer caso, agregar un dato mayor a todos por lista\n", CYN);

    struct container* c = newContainer();

    sortedAdd(c, "lado");
    sortedAdd(c, "dado");

    if (print)
        printContainer(c);

    int res = equalStr(c->data[0]->data, "dado");
    deleteContainer(c);
    return res;
}

int test_sortedAdd3(int print) {
    //Sobre el primer caso, agregar un dato menor a todos por lista
    if (print)
        printf("\n%sSobre el primer caso, agregar un dato menor a todos por lista\n", CYN);

    struct container* c = newContainer();
    sortedAdd(c, "lado");
    sortedAdd(c, "dado");

    if (print)
        printContainer(c);

    int res = equalStr(c->data[0]->data, "dado");
    deleteContainer(c);
    return res;
}

int test_sortedAdd4(int print) {
    //Sobre el primer caso, agregar un dato que ordenado termine entre dos elementos
    if (print)
        printf("\n%sSobre el primer caso, agregar un dato que ordenado termine entre dos elementos\n", CYN);

    struct container* c = newContainer();
    sortedAdd(c, "dado");
    sortedAdd(c, "lado");
    sortedAdd(c, "pato");

    if (print)
        printContainer(c);

    int res = equalStr(c->data[0]->next->data, "lado");
    deleteContainer(c);
    return res;
}

int test_contains1(int print) {
    //Dada una estructura, consultar si existe un dato que se ubique como ultimo dato de alguna de las listas
    if (print)
        printf("\n%sDada una estructura, consultar si existe un dato que se ubique como ultimo dato de alguna de las listas\n", CYN);

    struct container* c = newContainer();
    sortedAdd(c, "aristocracia");
    sortedAdd(c, "abecedario");
    sortedAdd(c, "adenosintrifosfato");

    int cont = contains(c, "aristocracia");
    if (print) {
        printContainer(c);
        printf("\n%s%s: %i\n", WHT, "aristocracia", cont);
    }

    if (cont) {
        deleteContainer(c);
        return 1;
    }

    deleteContainer(c);
    return 0;
}

int test_contains2(int print) {
    //Dada una estructura, consultar si existe un dato que se ubique como primer dato de algunade las listas
    if (print)
        printf("\n%s//Dada una estructura, consultar si existe un dato que se ubique como primer dato de algunade las listas\n", CYN);

    struct container* c = newContainer();
    sortedAdd(c, "aristocracia");
    sortedAdd(c, "abecedario");
    sortedAdd(c, "adenosintrifosfato");

    int cont = contains(c, "abecedario");
    if (print) {
        printContainer(c);
        printf("\n%s%s: %i\n", WHT, "abecedario", cont);
    }

    if (cont) {
        deleteContainer(c);
        return 1;
    }

    deleteContainer(c);
    return 0;
}

int test_contains3(int print) {
    //Dada una estructura, consultar si existe un dato que se ubique en el medio de una lista
    if (print)
        printf("\n%sDada una estructura, consultar si existe un dato que se ubique en el medio de una lista\n", CYN);

    struct container* c = newContainer();
    sortedAdd(c, "aristocracia");
    sortedAdd(c, "abecedario");
    sortedAdd(c, "adenosintrifosfato");

    int cont = contains(c, "adenosintrifosfato");
    if (print) {
        printContainer(c);
        printf("\n%s%s: %i\n", WHT, "adenosintrifosfato", cont);
    }

    if (cont) {
        deleteContainer(c);
        return 1;
    }

    deleteContainer(c);
    return 0;
}

int test_contains4(int print) {
    //Dada una estructura, consultar si existe un dato que no este en la lista
    if (print)
        printf("\n%sDada una estructura, consultar si existe un dato que no este en la lista\n", CYN);

    struct container* c = newContainer();
    sortedAdd(c, "aristocracia");
    sortedAdd(c, "abecedario");
    sortedAdd(c, "adenosintrifosfato");

    int cont = contains(c, "alfareria");
    if (print) {
        printContainer(c);
        printf("\n%s%s: %i\n", WHT, "alfareria", cont);
    }

    if (cont) {
        deleteContainer(c);
        return 0;
    }

    deleteContainer(c);
    return 1;
}

int test_inverseDelete1a(int print) {
    //Para un dato que se ubique al comienzo de una lista
    if (print)
        printf("\n%sPara un dato que se ubique al comienzo de una lista\n", CYN);

    struct container* c = newContainer();
    sortedAdd(c, "aristocracia");
    sortedAdd(c, "abecedario");
    sortedAdd(c, "adenosintrifosfato");

    if (print)
        printContainer(c);

    int count = inverseDelete(c, "abecedario");

    if (print)
        printContainer(c);

    if (equalStr(c->data[1]->data, "abecedario") && count == 2 && c->count == 1) {
        deleteContainer(c);
        return 1;
    }
    deleteContainer(c);
    return 0;
}

int test_inverseDelete1b(int print) {
    //Para un dato que se ubique al comienzo de una lista
    if (print)
        printf("\n%sPara un dato que se ubique al comienzo de una lista\n", CYN);

    struct container* c = newContainer();
    sortedAdd(c, "dudoso");
    sortedAdd(c, "dromedario");
    sortedAdd(c, "deuteronomio");

    if (print)
        printContainer(c);

    int count = inverseDelete(c, "deuteronomio");

    if (print)
        printContainer(c);

    if (equalStr(c->data[0]->data, "deuteronomio") && count == 2 && c->count == 1) {
        deleteContainer(c);
        return 1;
    }
    deleteContainer(c);
    return 0;
}

int test_inverseDelete2a(int print) {
    //Para un dato que se ubique al final de una lista
    if (print)
        printf("\n%sPara un dato que se ubique al final de una lista\n", CYN);

    struct container* c = newContainer();
    sortedAdd(c, "aristocracia");
    sortedAdd(c, "abecedario");
    sortedAdd(c, "adenosintrifosfato");

    if (print)
        printContainer(c);

    int count = inverseDelete(c, "aristocracia");

    if (print)
        printContainer(c);

    if (equalStr(c->data[1]->data, "aristocracia") && count == 2 && c->count == 1) {
        deleteContainer(c);
        return 1;
    }
    deleteContainer(c);
    return 0;
}

int test_inverseDelete2b(int print) {
    //Para un dato que se ubique al comienzo de una lista
    if (print)
        printf("\n%sPara un dato que se ubique al comienzo de una lista\n", CYN);

    struct container* c = newContainer();
    sortedAdd(c, "dudoso");
    sortedAdd(c, "dromedario");
    sortedAdd(c, "deuteronomio");

    if (print)
        printContainer(c);

    int count = inverseDelete(c, "dromedario");

    if (print)
        printContainer(c);

    if (equalStr(c->data[0]->data, "dromedario") && count == 2 && c->count == 1) {
        deleteContainer(c);
        return 1;
    }
    deleteContainer(c);
    return 0;
}

int test_inverseDelete3a(int print) {
    //Para un dato que se ubique entre dos nodos de una lista
    if (print)
        printf("\n%sPara un dato que se ubique entre dos nodos de una lista\n", CYN);

    struct container* c = newContainer();
    sortedAdd(c, "aristocracia");
    sortedAdd(c, "abecedario");
    sortedAdd(c, "adenosintrifosfato");

    if (print)
        printContainer(c);

    int count = inverseDelete(c, "adenosintrifosfato");

    if (print)
        printContainer(c);

    if (equalStr(c->data[1]->data, "adenosintrifosfato") && count == 2 && c->count == 1) {
        deleteContainer(c);
        return 1;
    }
    deleteContainer(c);
    return 0;
}

int test_inverseDelete3b(int print) {
    //Para un dato que se ubique al comienzo de una lista
    if (print)
        printf("\n%sPara un dato que se ubique al comienzo de una lista\n", CYN);

    struct container* c = newContainer();
    sortedAdd(c, "dudoso");
    sortedAdd(c, "dromedario");
    sortedAdd(c, "deuteronomio");

    if (print)
        printContainer(c);

    int count = inverseDelete(c, "dudoso");

    if (print)
        printContainer(c);
    if (equalStr(c->data[0]->data, "dudoso") && count == 2 && c->count == 1) {
        deleteContainer(c);
        return 1;
    }
    deleteContainer(c);
    return 0;
}

int main() {
    //Setear en 1 para imprimir por pantalla las variables testeadas
    int print = 0;
    char separator[38] = " ↑\n\n------------------------------\n\n";

    system("clear");

    printf("\n%stest_dup1%s", (test_dup1(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_dup2%s", (test_dup2(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_dup3%s\n", (test_dup3(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_equalStr1%s", (test_equalStr1(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_equalStr2%s", (test_equalStr2(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_equalStr3%s\n", (test_equalStr3(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_cmpStr1%s", (test_cmpStr1(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_cmpStr2a%s", (test_cmpStr2a(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_cmpStr2b%s", (test_cmpStr2b(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_cmpStr2c%s", (test_cmpStr2c(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_cmpStr3a%s", (test_cmpStr3a(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_cmpStr3b%s", (test_cmpStr3b(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_cmpStr4a%s", (test_cmpStr4a(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_cmpStr4b%s", (test_cmpStr4b(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_cmpStr4c%s", (test_cmpStr4c(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_cmpStr4d%s", (test_cmpStr4d(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_cmpStr4e%s\n", (test_cmpStr4e(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_split1a%s", (test_split1a(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_split1b%s", (test_split1b(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_split1c%s", (test_split1c(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_split2a%s", (test_split2a(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_split2b%s", (test_split2b(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_split2c%s", (test_split2c(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_split3a%s", (test_split3a(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_split3b%s", (test_split3b(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_split3c%s\n", (test_split3c(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_sortedAdd1%s", (test_sortedAdd1(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_sortedAdd2%s", (test_sortedAdd2(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_sortedAdd3%s", (test_sortedAdd3(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_sortedAdd4%s\n", (test_sortedAdd4(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_contains1%s", (test_contains1(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_contains2%s", (test_contains2(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_contains3%s", (test_contains3(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_contains4%s\n", (test_contains4(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_inverseDelete1a%s", (test_inverseDelete1a(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_inverseDelete1b%s", (test_inverseDelete1b(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_inverseDelete2a%s", (test_inverseDelete2a(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_inverseDelete2b%s", (test_inverseDelete2b(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_inverseDelete3a%s", (test_inverseDelete3a(print) ? GRN "✅ " : RED "❌ "), (print ? separator : ""));
    printf("\n%stest_inverseDelete3b\n", (test_inverseDelete3b(print) ? GRN "✅ " : RED "❌ "));

    return 0;
}
