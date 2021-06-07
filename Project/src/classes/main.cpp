#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <typeinfo>
#include <stdlib.h>
#include <random>
#include <vector>
#include <string>
#include "movies.h"
#include "series.h"
  
using namespace std;

int main(){
    string text, word;
    vector <string> row;

    vector <vector <string>> mov, series; // vector de vectores de strings
    vector <Movie> mov_ob; // vector de objetos Movie, es decir, vector que tiene todas las peliculas como objetos individuales. (no se si funciona en practica)
    vector <Episode> series_ob; // vector de objetos Episode, mismo caso que arriba (no estoy seguro de que funcione en práctica)

    ifstream file_mov, file_series; // cada .csv por tipo de video

    file_mov.open("./files/movies.csv");
    file_series.open("./files/series.csv");

    while(getline(file_mov,text)){ // extracción de lineas del csv de peliculas
        
        stringstream ss(text); // cada linea del csv se vuelve un objeto ss para separar
        row.clear(); // limpia el vector row para la siguiente linea

        while(getline(ss,word,',')){ // divide cada linea en sus componentes (id,titulo,genero,duracion,rating,comentario)
            row.push_back(word); // agrega al vector row cada 'celda' individual, como en el ejemplo
        }

        mov.push_back(row); // agrega el vector row al vector de vectores mov
    }

    while(getline(file_series,text)){ //extracción de lineas del csv de series, funciona igualmente al de arriba
        
        stringstream ss(text); 
        row.clear();

        while(getline(ss,word,',')){
            row.push_back(word);
        }

        series.push_back(row);
    }

    for(int i = 0; i<mov.size(); i++){ // crea objetos Movie usando los componentes del vector de vectores mov y los agrega al vector de objetos Movie mov_ob
        vector <string>a = mov[i];
        Movie m(a[0],a[1],a[2],stof(a[3]),stof(a[4]),a[5]);
        mov_ob.push_back(m);
    }

    for(int i = 0; i<series.size(); i++){ //mismo caso que arriba, pero con el de series, o Episode, series_ob
        vector <string>b = mov[i];
        Episode s(a[0],a[1],a[2],stof(a[3]),stof(a[4]),a[5],,,);    // los parametros son los mismo que en Movie, pero tiene tres extra al final
                                                                    // que son titulo de serie, num de temporada y num de episodio. Para sacar esos tres 
                                                                    // hay que hacer una subrutina que los separe e identifique episode number y season number
                                                                    // I have no clue how to do that, hasta aqui queda lo de hoy
                                                                    // Emiliano - 06/06/2021
        series_ob.push_back(s);
    }

    return 0;
}
