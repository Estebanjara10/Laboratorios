#include <iostream>
#include <string>
//
using namespace std;
//
int fact(int);
long potenciaNum(long numero, long potencia);
bool esPrimo(int numero);
//
int main()
{
    // Declaracion de variables:
    int opcion=1;
    string n;
    //
    while(opcion != 0){
        cout << endl << "Seleccione una opcion"<<endl;
        cout << "------------------------------"<<endl;
        cout << "2.Combinacion de billetes"<<endl;
        cout << "3.Verficacion de un mes"<<endl;
        cout << "4."<<endl;
        cout << "6.Valor aproximado del numero euler"<<endl;
        cout << "9.Suma digitos elevados a si mismos"<<endl;
        cout << "10.Numero primo de orden n"<<endl;
        cout << "11.Minimo Comun Multiplo"<<endl;
        cout << "13.Suma de todos los numeros primos menores de n"<<endl;
        cout << "15."<<endl;
        cout << "16."<<endl;
        cout << "0.Para SALIR..."<<endl;;
        cout << "------------------------------"<<endl;
        cin>>opcion;
        switch(opcion){
            case 2:
                int valor,entero;
                cout << "Ingrese el valor:" << endl;
                cin >> valor;
                // Se evalua 50mil:
                entero = (int)(valor/50000);
                cout << "se necesitan " << entero <<" billetes de 50000"<<endl;
                valor=(valor%50000);
                // Se evalua 20mil:
                entero = (int)(valor/20000);
                cout << "se necesitan " << entero <<" billetes de 20000"<<endl;
                valor=(valor%20000);
                // Se evalua 10mil:
                entero = (int)(valor/10000);
                cout << "se necesitan " << entero <<" billetes de 10000"<<endl;
                valor=(valor%10000);
                // Se evalua 5mil:
                entero = (int)(valor/5000);
                cout << "se necesitan " << entero <<" billetes de 5000"<<endl;
                valor=(valor%5000);
                // Se evalua 2mil:
                entero = (int)(valor/2000);
                cout << "se necesitan " << entero <<" billetes de 2000"<<endl;
                valor=(valor%2000);
                // Se evalua mil:
                entero = (int)(valor/1000);
                cout << "se necesitan " << entero <<" billetes de 1000"<<endl;
                valor=(valor%1000);
                // Se evalua moneda 500:
                entero = (int)(valor/500);
                cout << "se necesitan " << entero <<" monedas de 500"<<endl;
                valor=(valor%500);
                // Se evalua moneda 200:
                entero = (int)(valor/200);
                cout << "se necesitan " << entero <<" monedas de 200"<<endl;
                valor=(valor%200);
                // Se evalua moneda 100:
                entero = (int)(valor/100);
                cout << "se necesitan " << entero <<" monedas de 100"<<endl;
                valor=(valor%100);
                // Se evalua moneda 50:
                entero = (int)(valor/50);
                cout << "se necesitan " << entero <<" monedas de 50"<<endl;
                valor=(valor%50);
                cout<< "Faltante: "<<valor<<endl;
              break; // case 2!!
            case 3:
                int dia; int mes;
                cout << "ingrese numero del mes " << endl; // formato dd/mm/
                cin >> mes;
                cout << "ingrese numero del dia " << endl;
                cin >> dia;
                if (mes==2 && dia==29){
                    cout << dia << "/" << mes <<"/" << "es valida en bisiesto"<<endl;
                }
                else if (((mes==3) || (mes==4) || (mes==6) || (mes==9) || (mes==11)) && (dia<=30)) {
                    cout << dia << "/" << mes <<"/" << "es una fecha valida"<<endl;
                }
                else if (((1==mes) || (mes==5) || (mes==7) || (mes==8) || (mes==10) || (mes==12)) && (dia<=31)) {
                    cout << dia << "/" << mes <<"/" << "es una fecha valida";
                }    else {

                    cout << dia << "/" << mes <<"/" << "es una fecha no valida"<<endl;

                     }
              break;
           case 6:
            // calcular un factorial n(n-1)!
            unsigned int s;//sumas para aproximación
            cout<<"Escriba un numero: ";
            cin>>s;
            double e;
            e = 0;
            for(unsigned int i=0;i<s;i++){
                double u=fact(i);//muy importante
                e+=1/u;// e: variable declarada al inicio del main.
            }
            cout<<"\nel valor aproximado de e en base a su numero "<<s<<" es "<<e<<endl;
            break;

          case 9:
            cout << "ingrese un numero:" << endl;
            cin >> n; // se lee como string para manejar cada posición!
            //
            int d;
            long suma;
            suma = 0;
            for (int i=0; i < (int)n.length(); i++) {
               d = n[i] - '0';  // Codigo ASCII menos el caracter '0': 52(el cuatro)-48(el cero)=4
               suma += potenciaNum(d, d);
            }
            cout << "El resultado de la SUMA de digitos elevados a si mismos: " << suma << endl;
            break;

         case 10:
            int orden;
            cout << "Ingrese el orden del numero primo a buscar:" << endl;
            cin >> orden;
            int contNum, tope;
            contNum = 0; // contador de numeros enteros en orden creciente
            tope = orden; // tope para descontar a medida que encuentra primos
            //
            while(tope != 0) {
                if(esPrimo(contNum)) { // verifica cada numero y descuenta al encontrar un primo
                    tope--;
                }
                if(tope != 0) // incrementa el numero, si no se ha alcazado el tope de primos
                    contNum++;
            }
            cout << "El numero primo de orden [" << orden << "] es: " << contNum << endl;
            break;

         case 13:
            int n;
            cout << "ingrese el numero al que le quiere sumar sus numeros primos menores: " << endl;
            cin >> n;
            int acuSUM,com;
            acuSUM=0, com=0;
            while (com<n){
                if (esPrimo(com)){
                    acuSUM= acuSUM + com;
                }
                com++;
            }
                cout << "el resultado de la suma es: " << acuSUM << endl;
            break;

         case 11:
           int top;
           cout << "Ingrese un numero para el MCM:" << endl;
           cin >> top;
           //
           int mcm, res, num;
           long prod;
           for(int i = 1; i <= top; i++) { // ciclo
              num = i;
              if (num == 1) {
                  mcm = num;
              } else {
                  prod = mcm * num;
                  //
                  do
                  {
                      res = mcm % num;
                      mcm = num;
                      num = res;
                  } while (res != 0);

                  mcm = prod / mcm;
              }
           }
           cout << "El minimo comun multiplo es: " << mcm << endl;
           break;



        } // fin switch
       } //fin while

return 0; // fin main!
}
//
int fact(int f){
    int factorial=f;
    if(factorial>1){
        factorial=f*fact(f-1); //llamada recursiva de la funcion
        return factorial;
    }
    else{
        return 1;
    }
}
//
long potenciaNum(long numero, long potencia)
{
    long resultado = numero;
    while (potencia > 1)
    {
        resultado = resultado * numero;
        potencia--;
    }
    return resultado;
}
//
bool esPrimo(int numero) {
  bool bPrimo = true;
  if (numero == 0 || numero == 1) bPrimo = false;
  /*
          El número 4 es un caso especial, pues al dividirlo entre
          2 el resultado es 2, y el ciclo nunca se cumple, indicando que
          el 4 SÍ es primo, pero realmente NO lo es, así que si el número es 4
                        inmediatamente indicamos que no es primo (regresando 0)
          Nota: solo es para el 4, los demás funcionan bien
  */
  if (numero == 4) bPrimo = false;
  for (int x = 2; x < numero / 2; x++) {
    // Si es divisible por cualquiera de estos números, no
    // es primo
    if (numero % x == 0) bPrimo = false;
  }
  // Si no se pudo dividir por ninguno de los de arriba, sí es primo
  return bPrimo;
}
//















