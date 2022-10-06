#ifndef _TDATA_
#define _TDATA_

#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano; 
} tData;

int InformaQtdDiasNoMesMA( int a_mes, int a_ano );
tData InicializaDataParam( int a_dia, int a_mes, int a_ano );
tData LeData( );
void ImprimeData( tData a_data );
int EhBissextoAno( int a_ano );
int EhBissexto(tData a_data);
int InformaQtdDiasNoMesMA( int a_mes, int a_ano );
int InformaQtdDiasNoMes( tData a_data );
tData AvancaParaDiaSeguinte( tData a_data );
int EhIgual( tData a_data1, tData a_data2 );
int EhMenorDataAqDataB(tData a, tData b);

#endif