#include <stdio.h>
#include <stdlib.h>
#include "container.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"

int test_dup1(){
	//String vacio.
  char *dup;
  int size = dupStr("", &dup); 
	if (equalStr(dup, "") && size == 0){
		free(dup);
		return 1;
	}
	free(dup);
	return 0;
}

int test_dup2(){
  //string de un caracter
  char *dup;
  int size = dupStr("a", &dup); 
	if (equalStr(dup, "a") && size == 1){
		free(dup);
		return 1;
	}
	free(dup);
	return 0;
}

int test_dup3(){
	//String que incluya todos los caracteres validos distintos de cero
  char *dup;
	
	char s[95];
	for (int i = 32; i < 127; i++){
		if ((char)i != 0){
			s[i-32] = i;
		}
	}
	char s2[95];
	for (int i = 32; i < 127; i++){
		if ((char)i != 0){
			s2[i-32] = i;
		}
	}
	
  int size = dupStr(s, &dup); 
	if (equalStr(dup, s2) && size == 95){
		free(dup);
		return 1;
	}
	free(dup);
	return 0;
}

int test_cmpStr1(){
	//Dos string vacios
	char *s1 = "";
	char *s2 = "";
	if (cmpStr(s1, s2) == 0)
		return 1;
	return 0;
}

int test_cmpStr2a(){
	//Dos strings de 1 caracter iguales
	char *s1 = "a";
	char *s2 = "a";
	if (cmpStr(s1, s2) == 0)
		return 1;
	return 0;
}

int test_cmpStr2b(){
	//Dos strings de 1 caracter 'a' < 'b'
	char *s1 = "a";
	char *s2 = "b";
	if (cmpStr(s1, s2) == 1)
		return 1;
	return 0;
}

int test_cmpStr2c(){
	//Dos strings de 1 caracter 'b' > 'a'
	char *s1 = "b";
	char *s2 = "a";
	if (cmpStr(s1, s2) == -1)
		return 1;
	return 0;
}

int test_cmpStr3a(){
	//Strings iguales hasta un caracter
	char *s1 = "abc";
	char *s2 = "bbc";
	if (cmpStr(s1, s2) == 1)
		return 1;
	return 0;
}

int test_cmpStr3b(){
	//Strings iguales hasta un caracter
	char *s1 = "hula";
	char *s2 = "hola";
	if (cmpStr(s1, s2) == -1)
		return 1;
	return 0;
}

int test_cmpStr4a(){
	//Dos strings diferentes s1 < s2
	char *s1 = "adenosintrifosfato";
	char *s2 = "aristocracia";
	if (cmpStr(s1, s2) == 1)
		return 1;
	return 0;
}

int test_cmpStr4b(){
	//Dos strings diferentes s1 > s2
	char *s1 = "zimbabwe";
	char *s2 = "abecedario";
	if (cmpStr(s1, s2) == -1)
		return 1;
	return 0;
}

int test_cmpStr4c(){
	//Dos strings diferentes s1 < s2 (s2 caps)
	char *s1 = "alquitran";
	char *s2 = "BUENAVISTA";
	if (cmpStr(s1, s2) == 1)
		return 1;
	return 0;
}

int test_split1a(){
	//Un string vacio, count = 1
  char* first;
	char* last;
	split("", 1, &first, &last);
	return equalStr(first, "") * equalStr(last, "");
}

int test_split1b(){
  //Un string vacio, count = 2
  char* first;
	char* last;
	split("", 2, &first, &last);
	return equalStr(first, "") * equalStr(last, "");
}

int test_split1c(){
	//Un string vacio, count = 3
  char* first;
	char* last;
	split("", 3, &first, &last);
	return equalStr(first, "") * equalStr(last, "");
}

int test_split2a(){
	//Un string de un caracter, count = 1
  char* first;
	char* last;
	split("a", 1, &first, &last);
	return equalStr(first, "a") * equalStr(last, "");
}

int test_split2b(){
  //Un string de un caracter, count = 2
  char* first;
	char* last;
	split("a", 2, &first, &last);
	return equalStr(first, "a") * equalStr(last, "");
}

int test_split2c(){
  //Un string de un caracter, count = 3
  char* first;
	char* last;
	split("a", 3, &first, &last);
	return equalStr(first, "a") * equalStr(last, "");
}

int test_split3a(){
  // Un string de multiples caracteres, count = 1
  char* first;
	char* last;
	split("mostacho", 1, &first, &last);
	return equalStr(first, "m") * equalStr(last, "ostacho");
}

int test_split3b(){
  // Un string de multiples caracteres, count = 2
  char* first;
	char* last;
	split("mostacho", 2, &first, &last);
	return equalStr(first, "mo") * equalStr(last, "stacho");
}

int test_split3c(){
  // Un string de multiples caracteres, count = 3
  char* first;
	char* last;
	split("mostacho", 3, &first, &last);
	return equalStr(first, "mos") * equalStr(last, "tacho");
}

int test_sortedAdd1(){
	//Agregar un dato por lista
  struct container* c = newContainer();

	sortedAdd(c, "dado");
	sortedAdd(c, "arbol");
	sortedAdd(c, "zorro");
	sortedAdd(c, "caracol");

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

int test_sortedAdd2(){
	//Sobre el primer caso, agregar un dato mayor a todos por lista
  struct container* c = newContainer();

	sortedAdd(c, "lado");
	sortedAdd(c, "dado");

	int res = equalStr(c->data[0]->data, "dado");
	deleteContainer(c);
	return res;
}

int test_sortedAdd3(){
	//Sobre el primer caso, agregar un dato menor a todos por lista
	struct container* c = newContainer();
  sortedAdd(c, "lado");
	sortedAdd(c, "dado");

	int res = equalStr(c->data[0]->data, "dado");
	deleteContainer(c);
	return res;
}

int test_sortedAdd4(){
	//Sobre el primer caso, agregar un dato que ordenado termine entre dos elementos
	struct container* c = newContainer();
  sortedAdd(c, "dado");
  sortedAdd(c, "lado");
	sortedAdd(c, "pato");

	int res = equalStr(c->data[0]->next->data, "lado");
	deleteContainer(c);
	return res;

}

int test_contains1(){
  //Dada una estructura, consultar si existe un dato que se ubique como ultimo dato de alguna de las listas
	struct container* c = newContainer();
	sortedAdd(c, "aristocracia");
	sortedAdd(c, "abecedario");
	sortedAdd(c, "adenosintrifosfato");

	if (contains(c, "aristocracia")){
		deleteContainer(c);
		return 1;
	}
	
	deleteContainer(c);
	return 0;
}

int test_contains2(){
  //Dada una estructura, consultar si existe un dato que se ubique como primer dato de algunade las listas

	struct container* c = newContainer();
	sortedAdd(c, "aristocracia");
	sortedAdd(c, "abecedario");
	sortedAdd(c, "adenosintrifosfato");

	if (contains(c, "abecedario")){
		deleteContainer(c);
		return 1;
	}
	
	deleteContainer(c);
	return 0;
}

int test_contains3(){
  //Dada una estructura, consultar si existe un dato que se ubique en el medio de una lista
	struct container* c = newContainer();
	sortedAdd(c, "aristocracia");
	sortedAdd(c, "abecedario");
	sortedAdd(c, "adenosintrifosfato");

	if (contains(c, "adenosintrifosfato")){
		deleteContainer(c);
		return 1;
	}
	
	deleteContainer(c);
	return 0;
}

int test_contains4(){
	//Dada una estructura, consultar si existe un dato que no este en la lista
	struct container* c = newContainer();
	sortedAdd(c, "aristocracia");
	sortedAdd(c, "abecedario");
	sortedAdd(c, "adenosintrifosfato");

	if (contains(c, "alfareria")){
		deleteContainer(c);
		return 0;
	}
	
	deleteContainer(c);
	return 1;
}


int test_inverseDelete1(){
	//Para un dato que se ubique al comienzo de una lista
	struct container* c = newContainer();
	sortedAdd(c, "aristocracia");
	sortedAdd(c, "abecedario");
	sortedAdd(c, "adenosintrifosfato");

	int count = inverseDelete(c, "abecedario");
	if (equalStr(c->data[1]->data, "abecedario") && count == 2 && c->count == 1){
		deleteContainer(c);
		return 1;
	}
	deleteContainer(c);
	return 0;
}

int test_inverseDelete2(){
	//Para un dato que se ubique al final de una lista
	struct container* c = newContainer();
	sortedAdd(c, "aristocracia");
	sortedAdd(c, "abecedario");
	sortedAdd(c, "adenosintrifosfato");

	int count = inverseDelete(c, "aristocracia");
	if (equalStr(c->data[1]->data, "aristocracia") && count == 2 && c->count == 1){
		deleteContainer(c);
		return 1;
	}
	deleteContainer(c);
	return 0;
}

int test_inverseDelete3(){
	//Para un dato que se ubique entre dos nodos de una lista
	struct container* c = newContainer();
	sortedAdd(c, "aristocracia");
	sortedAdd(c, "abecedario");
	sortedAdd(c, "adenosintrifosfato");

	int count = inverseDelete(c, "adenosintrifosfato");
	if (equalStr(c->data[1]->data, "adenosintrifosfato") && count == 2 && c->count == 1){
		deleteContainer(c);
		return 1;
	}
	deleteContainer(c);
	return 0;
}

int main() {

	printf("%stest_dup1\n", test_dup1() ? GRN : RED);
	printf("%stest_dup2\n", test_dup2() ? GRN : RED);
	printf("%stest_dup3\n", test_dup3() ? GRN : RED);
	printf("%stest_cmpStr1\n", test_cmpStr1() ? GRN : RED);
	printf("%stest_cmpStr2a\n", test_cmpStr2a() ? GRN : RED);
	printf("%stest_cmpStr2b\n", test_cmpStr2b() ? GRN : RED);
	printf("%stest_cmpStr2c\n", test_cmpStr2c() ? GRN : RED);
	printf("%stest_cmpStr3a\n", test_cmpStr3a() ? GRN : RED);
	printf("%stest_cmpStr3b\n", test_cmpStr3b() ? GRN : RED);
	printf("%stest_cmpStr4a\n", test_cmpStr4a() ? GRN : RED);
	printf("%stest_cmpStr4b\n", test_cmpStr4b() ? GRN : RED);
	printf("%stest_cmpStr4c\n", test_cmpStr4c() ? GRN : RED);
	printf("%stest_split1a\n", test_split1a() ? GRN : RED);
	printf("%stest_split1b\n", test_split1b() ? GRN : RED);
	printf("%stest_split1c\n", test_split1c() ? GRN : RED);
	printf("%stest_split2a\n", test_split2a() ? GRN : RED);
	printf("%stest_split2b\n", test_split2b() ? GRN : RED);
	printf("%stest_split2c\n", test_split2c() ? GRN : RED);
	printf("%stest_split3a\n", test_split3a() ? GRN : RED);
	printf("%stest_split3b\n", test_split3b() ? GRN : RED);
	printf("%stest_split3c\n", test_split3c() ? GRN : RED);
	printf("%stest_sortedAdd1\n", test_sortedAdd1() ? GRN : RED);
	printf("%stest_sortedAdd2\n", test_sortedAdd2() ? GRN : RED);
	printf("%stest_sortedAdd3\n", test_sortedAdd3() ? GRN : RED);
	printf("%stest_sortedAdd4\n", test_sortedAdd4() ? GRN : RED);
	printf("%stest_contains1\n", test_contains1() ? GRN : RED);
	printf("%stest_contains2\n", test_contains2() ? GRN : RED);
	printf("%stest_contains3\n", test_contains3() ? GRN : RED);
	printf("%stest_contains4\n", test_contains4() ? GRN : RED);
	printf("%stest_inverseDelete1\n", test_inverseDelete1() ? GRN : RED);
	printf("%stest_inverseDelete2\n", test_inverseDelete2() ? GRN : RED);
	printf("%stest_inverseDelete3\n", test_inverseDelete3() ? GRN : RED);


	// A Continuacion dejamos algunos ejemplos de como
	// llama a las funciones pedidas. Este codigo debe
	// ser borrado / modificado.

	// dupStr
	
	/*char* dup;
	int size = dupStr("hola", &dup);
	printf("dupStr(\"hola\",&dup) -> size = %i, dup = \"%s\"\n", size, dup);
	free(dup);

	// cmpStr
	printf("cmpStr(\"abc\",\"abc\") -> %i\n", cmpStr("abc","abc"));
	printf("cmpStr(\"abcd\",\"abc\") -> %i\n", cmpStr("abcd","abc"));
	printf("cmpStr(\"abc\",\"abcd\") -> %i\n", cmpStr("abc","abcd"));

	// split
	dupStr("Hola Carola", &dup);
	char* s1;
	char* s2;
	printf("split(\"%s\",5,&s1,&s2) -> ", dup);
	split(dup,5,&s1,&s2);
	printf("s1=\"%s\",s2=\"%s\"\n",s1,s2);
	free(s1);
	free(s2);

	// sortedAdd
	struct container* c = newContainer();
	printContainer(c);
	sortedAdd(c, "perro");
	sortedAdd(c, "perro");
	sortedAdd(c, "gato");
	sortedAdd(c, "elefante");
	sortedAdd(c, "burro");
	sortedAdd(c, "pato");
	sortedAdd(c, "paloma");
	printContainer(c);

	// contains
	printf("contains(c,\"perro\") -> %i\n", contains(c,"perro"));
	printf("contains(c,\"carola\") -> %i\n", contains(c,"carola"));

	// inverseDelete
	inverseDelete(c,"perro");
	printContainer(c);
	
	char* dup1;
	char og[5] = "hola";
	og[4] = '\0';
	int size1 = dupStr(og, &dup1);
	printf("dupStr(\"hola\", &dup) -> size = %i, dup = \"%s\"\n", size1, dup1);
	og[1] = 'a';
	printf("%s\n", og);
	printf("%s\n", dup);
	free(dup);

	printf("%i\n", cmpStr("ala","perro"));
	printf("%i\n", cmpStr("casa","cal"));
	printf("%i\n", cmpStr("topo","top"));
	printf("%i\n", cmpStr("pato","pato"));

	char* first;
	char* last;
	split("mostacho",3, &first, &last);
	printf("s1 = %s\n", first);
	printf("s2 = %s\n", last);

	split("elefante",0, &first, &last);
	printf("s1 = %s\n", first);
	printf("s2 = %s\n", last);

	split("tucan",10, &first, &last);
	printf("s1 = %s\n", first);
	printf("s2 = %s\n", last);

	char *toCMP[5];
	toCMP[0] = "ala";
	toCMP[1] = "ALA";
	toCMP[2] = "mate";
	toCMP[3] = "mesa";
	toCMP[4] = "queso";
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			printf("%s %s %i\n",toCMP[i], toCMP[j], cmpStr(toCMP[i], toCMP[j]));
		}
	}
	

	struct container* cont = newContainer();
	sortedAdd(cont, "aristocracia");

	sortedAdd(cont, "abecedario");

	sortedAdd(cont, "zimbabwe");
	sortedAdd(cont, "alfarero");

	sortedAdd(cont, "adenosintrifosfato");

	sortedAdd(cont, "aguila");

	sortedAdd(cont, "zorro");

	sortedAdd(cont, "scaloneta");

	sortedAdd(cont, "esteroides");
	printContainer(cont);

	struct container* cont2 = newContainer();
	sortedAdd(cont2, "dado");
	sortedAdd(cont2, "lado");
	sortedAdd(cont2, "pato");
	sortedAdd(cont2, "ala");
	sortedAdd(cont2, "arco");
	sortedAdd(cont2, "mate");
	sortedAdd(cont2, "mesa");
	sortedAdd(cont2, "queso");
	sortedAdd(cont2, "barco");
	sortedAdd(cont2, "flor");
	sortedAdd(cont2, "nariz");
	sortedAdd(cont2, "rojo");
	sortedAdd(cont2, "casa");
	sortedAdd(cont2, "casa");
	printContainer(cont2);

	printf("\n");

	printf("pero -> %i\n", contains(cont2, "pero")); 
	printf("arco -> %i\n", contains(cont2, "arco")); 
	printf("casa -> %i\n", contains(cont2, "casa"));

	printf("\n");

	printf("mate %i\n\n", inverseDelete(cont2,"mate"));

	printContainer(cont2);
	*/
	return 0;
}
