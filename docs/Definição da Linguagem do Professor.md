# Definição da Linguagem do Professor
## Gramática
Gramática a ser utilizada e considere também alguma nova regra que tenha sido 
adicionada anteriormente: 

`programa` ->  
	`PROGRAMA` `ID` `INICIO` `lista_comandos` `FIM` 

`lista_comandos` ->
	`comando` `lista_comandos`
	| `ε` 

`Comando` ->
	`MOVER` `PONTO_VIRGULA` 
    | `DIREITA` `PONTO_VIRGULA` 
    | `ESQUERDA` `PONTO_VIRGULA` 
    | `LIMPAR` `PONTO_VIRGULA` 
    | `VOLTAR_BASE` `PONTO_VIRGULA` 
    | `REPETIR` `NUMERO` `bloco` 
    | `SE` `sensor` `bloco` 
    | `SE` `sensor` `bloco` `SENAO` `bloco`

`Sensor` ->
    `SUJO` 
    | `OBSTACULO` 

`bloco` ->
    `ABRE_CHAVES` `lista_comandos` `FECHA_CHAVES` 

> Para evitar ambiguidade relacionada ao `senao`, pode-se exigir chaves em todos os comandos condicionais. Nesta gramática já está ajustado dessa maneira. 

## Tradução
Segue um exemplo de tradução do programa para comandos Python: 
```
mover; 
direita; 
limpar; 
```
Tradução: 
```
robo.mover() 
robo.direita() 
robo.limpar() 
```