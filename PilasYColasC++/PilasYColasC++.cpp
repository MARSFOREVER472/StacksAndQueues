#include <iostream>
#include <queue> // LIBRERÍA PARA LAS COLAS O FILAS EN C++.
#include <stack> // LIBRERÍA PARA LAS PILAS EN C++.
#include <string> // NO OLVIDAR!!!!!!!!!!

using namespace std; // IMPORTANTE!!!!!!!!!!

// VALIDAR SI EL NÚMERO ES CAPICÚA O NO (123321 ES CAPICÚA, EN ESE CASO).

bool capicua()
{
    string answer; // RESPUESTA.
    cout << "Largo del vector: "; // DESPLIEGA EL LARGO DEL VECTOR.

    // SUPONGA QUE [5][3][2][2][3][5] ES CAPICÚA.

    // - TENIENDO EN CUENTA QUE LAS MÁS IMPORTANTES SON LAS PILAS Y COLAS.
    // - SIN EMBARGO, NO NOS INTERESA INGRESAR NÚMEROS POR PANTALLA.
    // - INCLUSO, EL LARGO DEL VECTOR PODRÍA COMPLICAR UN POCO MÁS EL PROCESO.

    getline(cin, answer); // INGRESA UNA RESPUESTA POR CONSOLA.
    int vector_long = stoi(answer); // EL LARGO DEL VECTOR SE DESPLIEGA MEDIANTE UN PARÁMETRO SECUENCIAL QUE SE DECLARA ABAJO DE ÉSTO.

    int* vec_num = new int(vector_long); // SE CREA UN ARREGLO CON NÚMEROS ENTEROS DECLARADOS ANTERIORMENTE.

    // CREAREMOS UNA ARREGLO CON NÚMEROS Y LO VAMOS A RECORRER MEDIANTE CICLO "for".

    for (int i = 0; i < vector_long; i++)
    {
        cout << "INGRESE UN NUMERO CUALQUIERA: "; // SE PIDE ELEGIR UN NÚMERO POR PANTALLA.
        getline(cin, answer); // Y LUEGO DE HABER HECHO ESTA ACCIÓN, DESPLIEGA ÉSTO DE LO QUE SE HIZO ANTERIORMENTE.
        vec_num[i] = stoi(answer); // DESPLIEGA EL ARREGLO DEL VECTOR COMPLETO POR CONSOLA.
    }

    // CREAREMOS UNAS PILAS Y UNAS FILAS EN ESTE MÉTODO.

    queue<int>* q = new queue<int>(); // FILA, YA QUE ES UN PUNTERO.
    stack<int>* s = new stack<int>(); // PILA, YA QUE TAMBIÉN ES UN PUNTERO.

    // IMPORTANTE!!!!: LOS DATOS ALMACENADOS 'NO' SON PUNTEROS.

    // HAY FUNCIONES BÁSICAS PARA TRABAJAR CON PILAS Y FILAS EN C++, ÉSTAS VENDRÍAN SIENDO:

    // - pop(): ELIMINA EL SIGUIENTE VALOR DENTRO DE UNA PILA O FILA EN UNA ESTRUCTURA DE DATOS.
    // - push(): INSERTA UN VALOR DENTRO DE UNA PILA O FILA EN UNA ESTRUCTURA DE DATOS.
    // - top(): RETORNA EL ÚLTIMO OBJETO INGRESADO DENTRO DE UNA PILA.
    // - front(): RETORNA EL PRIMER OBJETO INGRESADO DENTRO DE UNA FILA O COLA.
    // - back(): RETORNA EL ÚLTIMO OBJETO INGRESADO DENTRO DE UNA FILA O COLA.
    // - empty[bool](): True SI LA ESTRUCTURA DE DATOS ESTÁ VACÍA O NULA, False SI ES QUE ÉSTA MISMA NO ESTÁ VACÍA O NULA.
    // - size(): RETORNA EL TAMAÑO DE UNA ESTRUCTURA DE DATOS.

    int half; // MITAD DEL ARREGLO DE UN VECTOR.

    if (vector_long % 2 == 0) // SI EL LARGO DEL VECTOR ES UN NÚMERO PAR.
    {
        half = vector_long / 2; // LA MITAD DE UN ARREGLO SERÍA UN NÚMERO ENTERO.
    }

    // EN CASO CONTRARIO...

    else
    {
        // 3 2 1 4 1 2 3 (CAPICÚA).
        // 0 HASTA LA MITAD = 3.
        // POSICIONES = 0, 1, 2.
        // POSICIONES = 4, 5, 6.

        half = vector_long / 2 + 1;
    }

    // CREAREMOS UN CICLO "for" PARA EJECUTAR LAS FUNCIONES DENTRO DE UNA PILA O UNA COLA.

    for (int i = 0; i < vector_long / 2; i++) // PARA LA PILA.
    {
        s->push(vec_num[i]);
    }

    for (int i = half; i < vector_long; i++) // PARA LA COLA.
    {
        q->push(vec_num[i]);
    }

    // MIENTRAS QUE EN UNA PILA DEL VECTOR "NO" ESTÉ VACÍA.

    while (!s->empty())
    {
        // SI EL ÚLTIMO ELEMENTO INGRESADO EN UNA PILA ES DISTINTO AL DEL PRIMER VALOR INGRESADO EN UNA COLA, ENTONCES RETORNA FALSO.

        if (s->top() != q->front())
        {
            cout << "NO SON CAPICUAS.";
            return false;
        }

        // SI NO SE CUMPLEN CON ESTA CONDICIÓN.

        s->pop(); // ELIMINA ESTE VALOR DEL ARREGLO DENTRO DE UNA PILA.
        q->pop(); // ELIMINA ESTE VALOR DEL ARREGLO DENTRO DE UNA COLA.
    }

    cout << "ES CAPICUA.";
    return true;
    
}

int main()
{
    capicua(); // MÉTODO DECLARADO EN EL MAIN.
}
