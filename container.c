#include "container.h"

/*
Los strings que se agregan al container se agregan sobre una de las 4 listas existentes. Para determinar sobre que lista se debe agregar, se toma el primer byte del string y sobre este byte se identifica el par de bits menos significativos. Los bits se usan como indice en el arreglo de 4 posiciones. Por ejemplo, dado el string "arco" que comienza con "a", entonces el byte que corresponda a esta letra es 97d. Si se toman los ultimos dos bits se obtiene 01b, resultando en la posicion 1 del arreglo data dentro de la estructura container.
Por ultimo, una vez seleccionada la lista (o slot), se debe agregar el string en la lista de forma ordenada. Para esto se debe buscar el lugar donde agregar el nuevo nodo de la lista y el dato utilizando la funcion cmpStr implementada previamente. A partir de esta funcion es posible comparar dos strings y establecer una relacion de orden entre los mismos.

                        ┌───────┐   ┌───────┐   ┌───────┐
                        │       │   │       │   │       │  next 
             ┌─────────►│       ├───►       ├───►       │
             │          ├───────┤   ┌───────┤   ┌───────┤
             │          │       │   │       │   │       │  data
     ┌─ ┌────┴───┐      └┬──────┘   └┬──────┘   └┬──────┘
     │  │   00   │       └─► dado    └─► lado    └─► pato 
     │  │        │
     │  │        │      ┌───────┐   ┌───────┐   ┌───────┐   ┌───────┐   ┌───────┐
     │  │        │      │       │   │       │   │       │   │       │   │   0   │
     │  ├────────┤   ┌──►       ├───►       ├───►       ├───►       ├───►       │
     │  │   01   │   │  ┌───────┤   ┌───────┤   ┌───────┤   ┌───────┤   ┌───────┤
     │  │        ├───┘  │       │   │       │   │       │   │       │   │       │
     │  │        │      └┬──────┘   └┬──────┘   └┬──────┘   └┬──────┘   └┬──────┘
     │  │        │       └─► ala     └─► arco    └─► mate    └─► mesa    └─► queso
     │  ├────────┤
data │  │   10   │      ┌───────┐   ┌───────┐   ┌───────┐
     │  │        │      │       │   │       │   │   0   │
     │  │        ├──────►       ├───►       ├───►       │
     │  │        │      ┌───────┤   ┌───────┤   ┌───────┤
     │  ├────────┤      │       │   │       │   │       │
     │  │   11   │      └┬──────┘   └┬──────┘   └┬──────┘
     │  │        │       └─► barco   └─► flor    └─► rojo
     │  │        ├──┐
     │  │        │  │   ┌───────┐   ┌───────┐
     └─ ├────────┤  │   │       │   │   0   │
        │   13   │  └───►       ├───►       │
        │        │      ┌───────┤   ┌───────┤
        │        │      │       │   │       │
        │        │      └┬──────┘   └┬──────┘
        └────────┘       └─► casa    └─► casa
          count
*/

int len(char* s) {
    //Longitud del string s

    int c = 0;
    //Itera por los caracteres contabilizandolos hasta llegar al NULL-TERMINATING character
    while (s[c] != 0) {
        c++;
    }
    return c;
}

int dupStr(char* src, char** dst) {
    //Duplica un string. Debe contar la cantidad de caracteres totales de src y solicitar la memoria equivalente. Luego, debe copiar todos los caracteres a esta nueva area de memoria. El puntero al nuevo string se almacenara en el doble puntero dst. Ademas, como valor de retorno se debe retornar el tamaño del string.

    int l = len(src);
    //Asigna la memoria necesaria para el string copiado, incluyendo el NULL-TERMINATING character.
    char* newStr = (char*)malloc((l + 1) * sizeof(char));
    for (int i = 0; i <= l; i++) {
        //Asigna caracter por caracter del string src al nuevo string.
        newStr[i] = src[i];
    }
    //El puntero dst apunta al nuevo string.
    *dst = newStr;

    //Retorna la longitud del nuevo string.
    return l;
}

char normalizeChar(char c) {
    //Retorna el char c en mayuscula

    if (c > 96)
        return c - 32;
    return c;
}

int equalStr(char* s1, char* s2) {
    //Evalua la igualdad entre los strings s1 y s2 caracter por caracter

    int l1 = len(s1);
    int l2 = len(s2);
    //Si las longitudes de los strings son distintas los strings lo son tambien.
    if (l1 != l2)
        return 0;
    for (int i = 0; i < l1; i++) {
        //Si alguno de los caracteres son distintos los strings enteros lo son tambien.
        if (normalizeChar(s1[i]) != normalizeChar(s2[i]))
            return 0;
    }
    //Si pasaron todas las condiciones, los strings son iguales
    return 1;
}

int signo(int a) {
	//Retorna el signo (1/-1) del entero a pasado por parametro, retorna 0 si a = 0

	  if (a > 0)
        return 1;
    else if (a < 0)
        return -1;
    return 0;
}

int cmpStr(char* s1, char* s2) {
    int l1 = len(s1), l2 = len(s2);

    int min_len = l1 < l2 ? l1 : l2;

    for (int i = 0; i < min_len; i++) {
        int s = signo(normalizeChar(s2[i]) - normalizeChar(s1[i]));

        // Si los caracteres son distintos, alguna string es mayor
        if (s)
            return s;
    }

    // Una es prefijo de la otra ⇒ Si tienen la misma longitud, son iguales 
    return signo(l2 - l1);
}

void split(char* source, int count, char** s1, char** s2){
	//A partir del string en source, genera dos nuevos strings s1 y s2. s1 debe contener los primeros count caracteres del string source, mientas que s2 debe contener los caracteres restantes. La memoria del string source pasado por parametro debe ser liberada. En caso que count supere la cantidad de caracteres totales de source, se debe retornar en s2 un string vacio. El parametro count es siempre un numero positivo.
  
	int ls = len(source);
	//Asigna memoria para la primera y la segunda parte del string.
	//len(p1) := count
	char* p1 = (char*)malloc((count+1) * sizeof(char));

	//Copiar source[:count] a p1
	for (int i = 0; i < count; i++) {
			p1[i] = source[i];
	}
	//NULL Terminator
	p1[count] = '\0';

	char* p2;
	if (count >= ls) {
		//Si count es mayor o igual a len(src), p2 = string vacio ""
		p2 = (char*)malloc(1*sizeof(char));
		p2[0] = '\0';
	}
	else{
		//Si count < len(src), se copia source[count:] a p2
		p2 = (char*)malloc((ls-count+1)*sizeof(char));
		for (int i = 0; i <= ls-count; i++) {
			p2[i] = source[i+count];
		}
		p2[ls-count+1] = '\0';
	}
	
	//Copiar strings first y last a los punteros pasados por parametros
	dupStr(p1, s1);
	dupStr(p2, s2);

	//Liberar memoria
	free(p1);
	free(p2);

	free(source);
}

int getIndex(char* s) {
    //Retorna el indice del contenedor a donde corresponde el string s

    return (int)s[0] & 0x03;
}

int contains(struct container* c, char* value) {
    //Determina la cantidad de veces que value esta definido dentro de container. Debe retonar la cantidad de apariciones del dato.

    int count = 0;
    //Itera por las 4 listas del contenedor
    for (int i = 0; i < 4; i++) {
        struct node* n = c->data[i];
        //Itera por la lista enlazadda, contabilizando cada vez que la variable nodo del nodo actual es igual al valor dado.
        while (n != 0) {
            count += equalStr(n->data, value);
            n = n->next;
        }
    }

    return count;
}

void sortedAdd(struct container* c, char* value) {
    //Agregar el string value pasado por parametro dentro del container, respetando los invariantes de la estructura indicados anteriormente.

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
    if (!c->data[i]) {
        c->data[i] = newNode;
        return;
    }

    struct node* n = c->data[i];

    //Ademas distingue entre si la lista contiene un solo nodo o mas.
    if (!n->next) {
        //Si el valor es menor o igual (cmpStr no retorno -1) en orden lexicografico, lo posiciona como el primer elemento de la lista, previo al nodo actual.
        if (cmpStr(value, n->data) + 1) {
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
    while (n->next) {
        //Si el valor es menor o igual (cmpStr != -1) en orden lexicografico, lo posiciona como el primer elemento de la lista, previo al nodo actual.
        if (cmpStr(value, n->next->data) + 1) {
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
    while (n->next != 0) {
        //Borra aquellos nodos cuyo data != value.
        if (!equalStr(n->next->data, value)) {
            struct node* tmp = n->next;
            n->next = n->next->next;
            free(tmp->data);
            free(tmp);
            //Contabilizando cada borrada.
            count++;
        } else
            n = n->next;
    }

    //Finalmente evalua si del primer nodo de la lista la variable data es o no igual a value.
    if (!equalStr(c->data[i]->data, value)) {
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

    for (int i = 0; i < 4; i++) {
        struct node* n = c->data[i];
        while (n != 0) {
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

    printf("\x1B[37m\nCointeiner count: %i\n", c->count);
    for (int i = 0; i < 4; i++) {
        fprintf(stdout, "\x1B[37m%i -> ", i);
        struct node* n = c->data[i];
        while (n != 0) {
            fprintf(stdout, "\x1B[37m[%s]->", n->data);
            n = n->next;
        }
        fprintf(stdout, "\x1B[37m %i\n", 0);
    }
}