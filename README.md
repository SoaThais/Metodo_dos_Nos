# Metodo_dos_Nos

## Parametrização:
-> Vão

-> Número de módulos

-> Carregamento:

    ID Fx Fy
    
    ...

## Entrada de Dados
-> Lista de Nós: 

    ID COORD X COORD Y

    1    0        0

    ...

-> Lista de Barras: 

    ID NÓ INICIAL NÓ FINAL

    1       1       2

    ...

-> Condições de Contorno (Reações de Apoio):

    ID Rx Ry
    ...

Ideia: Implementar Nós e Barras com Grafos 

## Passo-a-passo: 
-> Script que gera a entrada de dados (o usuário só informa vão, n de módulos, carregamentos, a entrada de dados é gerada pelo programa)

-> Reações de Apoio (Eq. do Corpo Rígido)

-> Esforços Internos nas barras (Eq. do Ponto Material)

## Saída de Dados
-> Lista Fint:

    IDbarra Fint
    ...