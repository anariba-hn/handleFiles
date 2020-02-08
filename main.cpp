#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <io.h>

using namespace std;

void CrearCarpeta();
void CrearArchivo();
void pausa();

int main()
{
    bool continua = false;
    char keyword;

    do
    {
        system("cls");
        cout << " ---- Sistema de Archivos ----" << endl;
        cout << "\t1 .-Crear Directorio." << endl;
        cout << "\t2 .-Crear archivo." << endl;
        cout << "\t3 .-Salir" << endl;

        cin >> keyword;

        switch (keyword)
        {
        case '1':
            cout << "Has elejido CrearCarpeta." << endl;
            CrearCarpeta();
            pausa();
            break;
        case '2':
            cout << "Has elejido CrearArchivo." << endl;
            CrearArchivo();
            pausa();
            break;
        case '3':
            continua = true;
            break;
        default:
            system("cls");
            cout << "Porfabor, presione una opcion valida: ";
            pausa();
            break;
        }

    } while (continua != true);
    
    return 0;
}

void CrearCarpeta(){
    cout << "Creando carpeta..." << endl;
    
    if(mkdir("./EstructuraDeDatosII") != 0){
        cout << "Ups ! Kernel error" << endl;
        getwchar();
        return;
    }else{

        cout << "Directorio creado correctamente." << endl;
        getwchar();
    }

}

void CrearArchivo(){
    ofstream file;
    cout << "Creando archivo..." << endl;

    file.open("./EstructuraDeDatosII/test.txt");
    if(file.fail()){
        cout << "Ups ! Kernel error" << endl;
        getwchar();
        return;
    }else{
        file << "Escribiendo archivo" << endl;
        file << "desde programa" << endl;
        file << "creado en c++" << endl;
        file << "porque no tengo permisos" << endl;
        file << "de admin en el cmd." << endl;
        file.close();

        cout << "Archivo creado correctamente." << endl;
        getwchar();
    }
}

void pausa()
{
    cout << "Pulsa una tecla para continuar...";
    getwchar();
}
