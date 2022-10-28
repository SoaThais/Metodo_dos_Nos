# Método dos Nós

## Instrução para compilar o programa (via terminal):
g++ *.cpp -o .\main

## Instrução para executar o programa (via terminal):
.\main  

## Observações 
Ao adicionar um carregamento, deve-se utilizar o sinal para indicar o sentido em que o mesmo deve ser aplicado.

O sinal positivo é utilizado para:
- Força na mesma direção e sentido do eixo x
- Força na mesma direção e sentido do eixo y

O sinal negativo é utilizado para:
- Força na mesma direção, mas sentido oposto ao eixo x
- Força na mesma direção, mas sentido oposto ao eixo y

## Exemplo de Uso 

Cálculo dos esforços internos da treliça mostrada abaixo, na qual:
- Vão = 6 
- Número de Módulos = 2
- Carregamento no nó 2 = Força de módulo 2, aplicada no sentido positivo do eixo y 
- Carregamento no nó 3 = Força de módulo 3, aplicada no sentido negativo do eixo y 

![image](https://user-images.githubusercontent.com/84290168/198708731-6c0b6a31-430a-4d9d-bca0-68cc4cc747ff.png)

### Parâmetros de Entrada do Programa

----------------Parametros de Entrada----------------

- Vão: 6
- Numero de modulos: 2

Menu
1. Adicionar Forca
2. Aplicar Metodo dos Nos
3. Encerrar Programa

Opcao: 1

Forca 1:
- Id do No: 2
- Fx: 0
- Fy: 2

Menu
1. Adicionar Forca
2. Aplicar Metodo dos Nos
3. Encerrar Programa

Opcao: 1

Forca 2:
- Id do No: 3
- Fx: 0
- Fy: -3

Menu
1. Adicionar Forca
2. Aplicar Metodo dos Nos
3. Encerrar Programa

Opcao: 2

### Parâmetros de Saida do Programa

------------------------ Reacoes de Apoio -----------------------

- No 0 (eixo x): 0
- No 0 (eixo y): -0.25
- No 4 (eixo y): 1.25

--------------------------- Barra 6 --------------------------

- Id: 6
- No Inicial: 3
- No Final: 4
- Esforco: -1.44338

--------------------------- Barra 1 --------------------------

- Id: 1
- No Inicial: 0
- No Final: 2
- Esforco: -0.144338

--------------------------- Barra 0 --------------------------

- Id: 0
- No Inicial: 0
- No Final: 1
- Esforco: 0.288675

--------------------------- Barra 2 --------------------------

- Id: 2
- No Inicial: 1
- No Final: 2
- Esforco: -0.288675

--------------------------- Barra 3 --------------------------

- Id: 3
- No Inicial: 1
- No Final: 3
- Esforco: 0.288675

--------------------------- Barra 4 --------------------------

- Id: 4
- No Inicial: 2
- No Final: 3
- Esforco: -2.02073

--------------------------- Barra 5 --------------------------

- Id: 5
- No Inicial: 2
- No Final: 4
- Esforco: 0.721688
