#include <iostream>

using namespace std;

int main()
{
    char letra=65; // Inicia con letra A
    // Inicio ciclo ascendente:
    for(int i=0; i<7;i++)
    {
        letra=65;
        for(int j=0; j<=i;j++)
        {
            cout <<letra;
            letra=letra+1;
        }
        for(int j=11-2*i;j>0; j--)
        {
            cout<<' ';
        }
        letra='A'+i;
        for(int j=0;j<=i; j++)
        {
          if(letra!='G')
            cout<<letra;
          letra--;
        }
        cout<<endl;
    } // fin ciclo ascendente!
    // *****************
    // Inicio ciclo descendente:
    for(int i=5; i>=0;i--)
    {
        letra='A';
        for(int j=0; j<=i;j++)
        {
            cout <<letra;
            letra=letra+1;
        }
        for(int j=11-2*i;j>0; j--)
        {
            cout<<' ';
        }
        letra='A'+i;
        for(int j=0;j<=i; j++)
        {
          if(letra!='G')
            cout<<letra;
          letra--;
        }
        cout<<endl;
   } // fin ciclo ascendente!
   // El return termina la ejecucion del metodo donde lo encuentre!
   return 0; // para salir del main! no debe estar en "for"
} // cierra main
