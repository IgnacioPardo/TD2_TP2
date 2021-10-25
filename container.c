#include "container.h"

int len(char* s){
	//Longitud del string s
	
	int c = 0;
	//Itera por los caracteres contabilizandolos hasta llegar al NULL-TERMINATING character
	while (s[c] != 0){
			c++;
	}
	return c;
}

int dupStr(char* src, char** dst){
	//Duplica un string. Debe contar la cantidad de caracteres totales de src y solicitar la memoria equivalente. Luego, debe copiar todos los caracteres a esta nueva area de memoria. El puntero al nuevo string se almacenara en el doble puntero dst. Ademas, como valor de retorno se debe retornar el tamaño del string.

	int l = len(src);
	//Asigna la memoria necesaria para el string copiado, incluyendo el NULL-TERMINATING character.
	char *newStr = (char*)malloc((l+1) * sizeof(char));
	for (int i = 0; i < l; i++){
		//Asigna caracter por caracter del string src al nuevo string.
		newStr[i] = src[i];
	}
	//El puntero de dst apunta al nuevo string.
	*dst = newStr;
	
	//Retorna la longitud del nuevo string.
	return len(*dst);
}

char normalizeChar(char c){
	//Retorna el char c en mayuscula

	if (c > 96)
		return c - 32;
	return c;
}

int equalStr(char* s1, char* s2){
	//Evalua la igualdad entre los strings s1 y s2 caracter por caracter
	
	int l1 = len(s1);
  int l2 = len(s2);
	//Si las longitudes de los strings son distintas los strings lo son tambien.
	if (l1 != l2)
		return 0;
	for(int i = 0; i < l1; i++){
		//Si alguno de los caracteres son distintos los strings enteros lo son tambien.
		if(normalizeChar(s1[i]) != normalizeChar(s2[i]))
			return 0;
	}
	//Si pasaron todas las condiciones, los strings son iguales
	return 1;
}

int cmpStr(char* s1, char* s2){
	//Compara dos strings en orden lexicograafico. Retorna (0 si son iguales, 1 si s1<s2, −1 si s2<s1)

	int l1 = len(s1);
	int l2 = len(s2);

	//Dada la longitud de uno de los dos strings, sin importar cual, itera por los caracteres de ambos.
	for (int i = 0; i < l1; i++){
		// Si el valor de i llega a valer la longitud de un string pero es menor que la longitud del otro, asume todas las posiciones previas fueron iguales, pero el string en si es mas corto por lo tanto es menor en orden lexicografico.
		if (i == l1 && i < l2)
			return 1;
		else if (i == l2 && i < l1)
			return -1;
		else{
			//Para comparar los caracteres de cada string, los pasa todos a mayusculas para respetar el orden.
			char a = normalizeChar(s1[i]);
			char b = normalizeChar(s2[i]);
			
			//De algun caracter ser mayor que el otro, retorna el orden correspondiente.
			if (a > b)
				return -1;
			else if (a < b)
				return 1;
		}
	}
	//Si ambos strings son iguales, retorna 0.
	if (equalStr(s1, s2))
		return 0;

	return 1;
}

void split(char* source, int count, char** s1, char** s2){
	//A partir del string en source, genera dos nuevos strings s1 y s2. s1 debe contener los primeros count caracteres del string source, mientas que s2 debe contener los caracteres restantes. La memoria del string source pasado por parametro debe ser liberada. En caso que count supere la cantidad de caracteres totales de source, se debe retornar en s2 un string vacio. El parametro count es siempre un numero positivo.
  
	int ls = len(source);

	//Asigna memoria para la primera y la segunda parte del string.
	//len(p1) := count
	//len(p2) := len(source) - count
	char *p1 = (char*)malloc(count * sizeof(char));
	char *p2 = (char*)malloc((len(source)-count)*sizeof(char));

	//Itera por los caracteres del string
	for (int i = 0; i < ls; i++){
		if (i < count){
			//Si el indice del caracter es menor a count, el caracter pertenece a la primera parte del split.
			p1[i] = source[i];
		}
		else{
			//Si el indice del caracter es mayor o igual a count, el caracter pertenece a la segunda parte del split.
			p2[i-count] = source[i];
		}
	}

	//Si count es mayor que la longitud del string, a p2 se le asigna un string vacio
	if (count > ls)
		p2 = "";
	
	//Los punteros de s1 y s2 apuntan a p1 y p2
	*s1 = p1;
	*s2 = p2;
}

int getIndex(char * s){
	//Retorna el indice del contenedor a donde corresponde el string s
	
	return (int)s[0] & 0x03;
}

int contains(struct container* c, char* value) {
	//Determina la cantidad de veces que value est ́a definido dentro de container. Debe retonar la cantidad de apariciones del dato.

	int count = 0;
	//Itera por las 4 listas del contenedor
	for(int i=0; i<4; i++) {
			struct node* n = c->data[i];
			//Itera por la lista enlazadda, contabilizando cada vez que la variable nodo del nodo actual es igual al valor dado.
			while(n != 0) {
					count += equalStr(n->data, value);
					n = n->next;
			}
	}

	return count;
}

void sortedAdd(struct container* c, char* value) {
	//Agregar el string value pasado por par ́ametro dentro del container, respetando los invariantes de la estructura indicados anteriormente.

	//Si el valor ya no pertenece al contenedor se incrementa la variable count del contenerod
	if (!contains(c, value))
		c->count++;
	
	//Obtiene el indice de las listas del contenedor a partir del valor
	int i = getIndex(value);


	//Nuevo nodo a partir del valor dado
	struct node* newNode = (struct node*)malloc(sizeof(struct node*));
	dupStr(value, &newNode->data);
	newNode->next = 0;

	//El algoritmo distingue entre el primer elemento de la lista y el resto de la lista.

	//Si la lista no contiene ningun nodo, el puntero a la lista del contador apunta al nuevo nodo creado.
	if (!c->data[i]){
		c->data[i] = newNode;
		return;
	}
	
	struct node* n = c->data[i];

	//Ademas distingue entre si la lista contiene un solo nodo o mas.
	if (!n->next){
		//Si el valor es menor o igual (cmpStr no retorno -1) en orden lexicografico, lo posiciona como el primer elemento de la lista, previo al nodo actual.
		if (cmpStr(value, n->data) + 1){
			c->data[i] = newNode;
			newNode->next = n;
			//Termina la funcion
			return;
		}
		//Si el valor es mayor, posiciona el nuevo nodo segundo en la lista
		n->next = newNode;
		//Termina la funcion
		return;
	}

	//Itera por el resto de la lista
	while(n->next){
		//Si el valor es menor o igual (cmpStr no retorno -1) en orden lexicografico, lo posiciona como el primer elemento de la lista, previo al nodo actual.
		if (cmpStr(value, n->next->data) + 1){
			newNode->next = n->next;
			n->next = newNode;
			//Termina la funcion
			return;
		}
		//Pasa al siguiente nodo
		n = n->next;
	}

	//De no haber posicionado al nuevo nodo en ninguna posicion de la lista, lo setea ultimo en ella
	n->next = newNode;
}

int inverseDelete(struct container* c, char* value) {
	//Borra todos los datos del slot al que pertenece el string value, menos todas las copias que existan del string value. Debe retonar la cantidad de datos que fueron borrados.	
		//Retorna 0 y no modifica c si no contiene value. 
		if (!contains(c, value))
			return 0;

		int count = 0;
		int i = getIndex(value);

		//Distingue entre el primer elemento y el resto de la lista.

    struct node* n = c->data[i];

		//Comienza iterando por toda la lista exceptuando por el primero.
		while(n->next != 0) {
			//Borra aquellos nodos cuyo data != value.
			if (!equalStr(n->next->data, value)){
				struct node* tmp = n->next;
				n->next = n->next->next;
				free(tmp->data);
				free(tmp);
				//Contabilizando cada borrada.
				count++;
			}
			else{
				n = n->next;
			}
		}
		
		//Finalmente evalua si del primer nodo de la lista la variable data es o no igual a value.
		if (!equalStr(c->data[i]->data, value)){
			//De no serlo se reemplaza a si mismo por el proximo nodo de la lista, o de ser el unico por el valor 0.
			struct node* tmp = c->data[i];
			c->data[i] = c->data[i]->next;
			free(tmp->data);
			free(tmp);
			count++;
		}
		//Descuenta la cantidad de nodos que se borraron del total del contenedor
		c->count -= count;
    return count;
}

struct container* newContainer() {
	//Solicita memoria e inicializa una estructura container vacia.
	
	struct container* c = (struct container*)malloc(sizeof(struct container));
	c->data[0] = 0;
	c->data[1] = 0;
	c->data[2] = 0;
	c->data[3] = 0;
	c->count = 0;
	return c;
}

void deleteContainer(struct container* c) {
	//Borra toda la memoria solicitada dentro de un container.
	
	for(int i=0; i<4; i++) {
		struct node* n = c->data[i];
		while(n != 0) {
			struct node* t = n;
			n = n->next;
			free(t->data);
			free(t);
		}
	}
	free(c);
}

void printContainer(struct container* c) {
	//Imprime en pantalla el container pasado por parametro.
	
	printf("Cointeiner count: %i\n", c->count);
	for(int i=0; i<4; i++) {
		fprintf(stdout,"%i -> ",i);
		struct node* n = c->data[i];
		while(n != 0) {
			fprintf(stdout,"[%s]->",n->data);
			n = n->next;
		}
		fprintf(stdout," %i\n", 0);
	}
}